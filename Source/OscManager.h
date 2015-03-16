#pragma once
#include "../oscpack/osc/OscOutboundPacketStream.h"
#include "../oscpack/ip/UdpSocket.h"
#include "../oscpack/osc/OscReceivedElements.h"
#include "../oscpack/osc/OscPacketListener.h"
#include "Pool.h"
#include "DebugComponent.h"

#include "../JuceLibraryCode/JuceHeader.h"

#include <vector>
using namespace std;

struct ReceiverRegistration
{
	String address;
	int parameterIndex;
	int port;
	double *pValues;
};

class SocketThread: public Thread, public osc::OscPacketListener
{
public:
	SocketThread(vector<ReceiverRegistration>* Receivers, int Port);
	~SocketThread();

	int getPort();

	void run();
	void Break();

private:
	vector<ReceiverRegistration>* receivers;
	int port;
	ScopedPointer<UdpListeningReceiveSocket> s;

protected:
	virtual void ProcessMessage(const osc::ReceivedMessage& m, const IpEndpointName& remoteEndpoint);
};



class OscManager : public Thread
{
public:
    //==============================================================================
	OscManager ();
    ~OscManager();

	void registerReceiver(String Address, int ParameterIndex, int Port, double* pValues);
	void unregisterReceiver(double *pValues);

	void run();
	void stop();

	//==============================================================================
    juce_UseDebuggingNewOperator
    juce_DeclareSingleton (OscManager, false)

private:

	vector<ReceiverRegistration> receivers;
	vector<SocketThread*> sockets;

	CriticalSection cs;
};