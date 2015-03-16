#include "OscManager.h"
#include "MainComponent.h"
#include "MainviewComponent.h"

juce_ImplementSingleton (OscManager)

OscManager::OscManager() : Thread("OscManager")
{

}

OscManager::~OscManager()
{
	 stopThread(100);
	 clearSingletonInstance();
}

void OscManager::registerReceiver(String Address, int ParameterIndex, int Port, double* pValues)
{
	cs.enter();

	ReceiverRegistration receiver;
	receiver.address = Address;
	receiver.parameterIndex = ParameterIndex;
	receiver.port = Port;
	receiver.pValues = pValues;

	if (pValues)
		*receiver.pValues = 0;

	receivers.push_back(receiver);

	cs.exit();
}

void OscManager::unregisterReceiver(double *pValues)
{
	cs.enter();

	for (int i=0; i<receivers.size(); i++)
		if (receivers[i].pValues==pValues)
		{
			receivers.erase(receivers.begin()+i);
			cs.exit();
			return;
		}

	cs.exit();
}

void OscManager::run()
{
	while (!threadShouldExit())
	{
		//Update Sockets: Check if new sockets are needed
		for (unsigned int i=0; i<receivers.size(); i++)
		{
			bool found=false;

			for (unsigned int j=0; j<sockets.size(); j++)
			{
				if (sockets[j]->getPort()==receivers[i].port)
					found=true;
			}

			if (!found)
			{
				SocketThread* st = new SocketThread(&receivers, receivers[i].port);
				if (st)
				{
					sockets.push_back(st);
					st->startThread();
				}
			}
		}

		//Update Sockets: Remove not needed sockets
		cs.enter();

		int j=0;
		while (j<sockets.size())
		{
			bool found=false;

			for (unsigned int i=0; i<receivers.size(); i++)
			{
				if (sockets[j]->getPort()==receivers[i].port)
					found=true;
			}

			if (!found)
			{
				sockets[j]->Break();
				sockets[j]->stopThread(100);
				delete sockets[j];
				sockets.erase(sockets.begin()+j);
			}
			else
				j++;
		}

		cs.exit();

		sleep(10);
	}
}

void OscManager::stop()
{
	cs.enter();

	for (unsigned int i=0; i<sockets.size(); i++)
	{
		sockets[i]->Break();
		sockets[i]->stopThread(500);
		delete sockets[i];
	}
	sockets.clear();

	cs.exit();

	stopThread(500);
}

SocketThread::SocketThread(vector<ReceiverRegistration>* Receivers, int Port) : Thread("SocketThread")
{
	port = Port;
	receivers=Receivers;
	s = new UdpListeningReceiveSocket(IpEndpointName(IpEndpointName::ANY_ADDRESS, Port), this);
}
	
SocketThread::~SocketThread()
{
	
}

int SocketThread::getPort()
{
	return port;
}

void SocketThread::run()
{
	if (!threadShouldExit())
	{
		s->Run();
		sleep(5);
	}
	
}

void SocketThread::Break()
{
	s->AsynchronousBreak();
}

void SocketThread::ProcessMessage(const osc::ReceivedMessage& m, const IpEndpointName& remoteEndpoint)
{
	String mesAddress = String(m.AddressPattern()).trim();
	double currentTime = Time::getMillisecondCounterHiRes();

	vector<float> arguments;
	osc::ReceivedMessage::const_iterator arg = m.ArgumentsBegin();
	for (long i=0; i<m.ArgumentCount(); i++)
	{
		arguments.push_back(arg->AsFloatUnchecked());
		arg++;
	}
	
	//Check for incoming control messages
	if (mesAddress.matchesWildcard("/resetFollowing", false))
	{
		osc::ReceivedMessage::const_iterator arg = m.ArgumentsBegin();
		float index = arg->AsFloat()-1;

		const MessageManagerLock mmLock;

		MainviewComponent* MVC = (MainviewComponent*)Pool::Instance()->getObject("MainviewComponent");
		MainComponent* mc = (MainComponent*)MVC->getMainComponent((int)index);
		if (mc)
		{
			TimeLineController* tlc = mc->getTimeLineController();
			tlc->resetFollowing();
		}

		
	}
	else if (mesAddress.matchesWildcard("/startFollowing", false))
	{
		if (m.ArgumentCount()==1)
		{
			osc::ReceivedMessage::const_iterator arg = m.ArgumentsBegin();
			float index = arg->AsFloat()-1;

			const MessageManagerLock mmLock;

			MainviewComponent* MVC = (MainviewComponent*)Pool::Instance()->getObject("MainviewComponent");
			MainComponent* mc = (MainComponent*)MVC->getMainComponent(index);
			if (mc)
			{
				TimeLineController* tlc = mc->getTimeLineController();
				tlc->startFollowing();
			}
		}
	}
	else if (mesAddress.matchesWildcard("/stopFollowing", false))
	{
		if (m.ArgumentCount()==1)
		{
			osc::ReceivedMessage::const_iterator arg = m.ArgumentsBegin();
			float index = arg->AsFloat()-1;
		
			const MessageManagerLock mmLock;

			MainviewComponent* MVC = (MainviewComponent*)Pool::Instance()->getObject("MainviewComponent");
			MainComponent* mc = (MainComponent*)MVC->getMainComponent(index);
			if (mc)
			{
				TimeLineController* tlc = mc->getTimeLineController();
				tlc->stopFollowing();
			}
		}

	}
	else
		for (unsigned int i=0; i<receivers->size(); i++)
		{
			String recAddress = (receivers->begin()+i)->address.trim();

			if (mesAddress.matchesWildcard(recAddress, false))
			{
				//Save the current value, timestamp, velocity
				float newValue=0;
				if (arguments.size())
					newValue=arguments[(receivers->begin()+i)->parameterIndex];

				 double timeDifference=currentTime-(receivers->begin()+i)->pValues[1];

				//if (timeDifference>0)
				{
					double velocity=(newValue-(receivers->begin()+i)->pValues[Features::Value])/timeDifference;
					double acceleration=(velocity-(receivers->begin()+i)->pValues[Features::Velocity])/timeDifference; 

					(receivers->begin()+i)->pValues[Features::Value] = newValue;
					(receivers->begin()+i)->pValues[Features::Timestamp] = currentTime;
					(receivers->begin()+i)->pValues[Features::Velocity] = velocity;
					(receivers->begin()+i)->pValues[Features::Acceleration] = acceleration;
				}
			} 
		}
}