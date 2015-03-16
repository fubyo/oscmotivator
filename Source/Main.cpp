#include "../JuceLibraryCode/JuceHeader.h"
#include "MainComponent.h"
#include "MainviewComponent.h"
#include "OscManager.h"
#include "DebugComponent.h"

class MainWindow  : public DocumentWindow, public MenuBarModel
{
	void save()
	{
		FileChooser myChooser ("Please select where you want to save the configuration to...",
							   File::getSpecialLocation (File::userHomeDirectory),
							   "*.xml", false);

		if (myChooser.browseForFileToSave(true))
		{
			const MessageManagerLock mmLock;

			File configurationFile(myChooser.getResult());

			XmlElement configurationElement("Configuration");
			int numberOfGestures = MVC->getNumberOfGestures();
			configurationElement.setAttribute("GestureNo", numberOfGestures);

			for (int i=0; i<numberOfGestures; i++)
			{
				MainComponent* mc = (MainComponent*)MVC->getMainComponent(i);
				TimeLineController* tlc = mc->getTimeLineController();

				String name = MVC->getNameOfGesture(i);
				double fps = tlc->fpsEditor->getText().getDoubleValue();
				double duration = tlc->durationEditor->getText().getDoubleValue();
				int numberOfRecordings = tlc->recordingComboBox->getSelectedItemIndex();
				String oscAddresses = tlc->receivingAddressesEditor->getText();
				String hostAddress = tlc->hostEditor->getText();
				int port = tlc->portEditor->getText().getIntValue();
				String address = tlc->addressEditor->getText();
				int type = tlc->typeComboBox->getSelectedItemIndex();
				bool follow = tlc->followToggleButton->getToggleState();
				double window = tlc->windowKnob->getValue();
				double tolerance = tlc->trajectoryToleranceKnob->getValue();
				double speedTolerance = tlc->speedToleranceKnob->getValue();
				double likelihoodThreshold = tlc->likelihoodSetter->getThreshold();
				double smoothnessThreshold = tlc->smoothnessSetter->getThreshold();
				String activationHost = tlc->activationHostEditor->getText();
				int activationPort = tlc->activationPortEditor->getText().getIntValue();
				String activationAddress = tlc->activationAddressEditor->getText();
				int startMarkerPosition = tlc->stl->startMarkerPosition;
				int endMarkerPosition = tlc->stl->endMarkerPosition;
				bool relativeFollowing = tlc->relativeFollowing;

				String tabidentifier = "Tab_" + String(i);
				XmlElement* tabElement = new XmlElement(tabidentifier);

				tabElement->setAttribute("name", name);
				tabElement->setAttribute("fps", fps);
				tabElement->setAttribute("duration", duration);
				tabElement->setAttribute("numberOfRecordings", numberOfRecordings);
				tabElement->setAttribute("oscAddresses", oscAddresses);
				tabElement->setAttribute("hostAddress", hostAddress);
				tabElement->setAttribute("port", port);
				tabElement->setAttribute("address", address);
				tabElement->setAttribute("type", type);
				tabElement->setAttribute("follow", follow);
				tabElement->setAttribute("window", window);
				tabElement->setAttribute("tolerance", tolerance);
				tabElement->setAttribute("speedTolerance", speedTolerance);
				tabElement->setAttribute("likelihoodThreshold", likelihoodThreshold);
				tabElement->setAttribute("smoothnessThreshold", smoothnessThreshold);
				tabElement->setAttribute("activationHost", activationHost);
				tabElement->setAttribute("activationPort", activationPort);
				tabElement->setAttribute("activationAddress", activationAddress);
				tabElement->setAttribute("startMarkerPosition", startMarkerPosition);
				tabElement->setAttribute("endMarkerPosition", endMarkerPosition);
				tabElement->setAttribute("relativeFollowing", relativeFollowing);

				int numOfSamples = tlc->stl->samples.size();
				tabElement->setAttribute("numOfSamples", numOfSamples);
				
				int numOfDimensions = 0;
				if (numOfSamples)
					numOfDimensions = tlc->stl->samples[0].value.size();

				tabElement->setAttribute("numOfDimensions", numOfDimensions);
				
				for (int ii=0; ii<numOfSamples; ii++)
				{
					String sampleIdentifier = "Sample_" + String(ii);
					XmlElement* sampleElement = new XmlElement(sampleIdentifier);
					sampleElement->setAttribute("timestamp", tlc->stl->samples[ii].timestamp);
					for (int iii=0; iii<numOfDimensions; iii++)
					{
						sampleElement->setAttribute(String(iii), tlc->stl->samples[ii].value[iii]);
					}

					tabElement->addChildElement(sampleElement);
				}

				configurationElement.addChildElement(tabElement);
			}

			configurationFile.replaceWithText(configurationElement.createDocument("OscMotivator Configuration File"));
		}
	}
	
	void load()
	{
		FileChooser myChooser ("Please select where you want to load the configuration from...",
                               File::getSpecialLocation (File::userHomeDirectory),
                               "*.xml", false);

		//Loading the parameters of each tab
		if (myChooser.browseForFileToOpen())
		{
			const MessageManagerLock mmLock;

			File configurationFile (myChooser.getResult());

			XmlDocument configurationDocument(configurationFile);
			XmlElement* configurationElement = configurationDocument.getDocumentElement();

			if (configurationElement->hasTagName ("Configuration"))
			{
				int numberOfGestures = configurationElement->getIntAttribute("GestureNo", 0);

				if (numberOfGestures)
				{
					MVC->unregisterReceivers();
					MVC->clearGestures();

					for (int i=0; i<numberOfGestures; i++)
					{
						String identifier = "Tab_" + String(i);
						XmlElement* e = configurationElement->getChildByName(identifier);

						String name = e->getStringAttribute("name");
						double fps = e->getDoubleAttribute("fps");
						double duration = e->getDoubleAttribute("duration");
						int numberOfRecordings = e->getIntAttribute("numberOfRecordings");
						String oscAddresses = e->getStringAttribute("oscAddresses");
						String hostAddress = e->getStringAttribute("hostAddress");
						int port = e->getIntAttribute("port");
						String address = e->getStringAttribute("address");
						int type = e->getIntAttribute("type");
						bool follow = e->getBoolAttribute("follow");
						double window = e->getDoubleAttribute("window");
						double tolerance = e->getDoubleAttribute("tolerance");
						double speedTolerance = e->getDoubleAttribute("speedTolerance");
						double likelihoodThreshold = e->getDoubleAttribute("likelihoodThreshold");
						double smoothnessThreshold = e->getDoubleAttribute("smoothnessThreshold");
						String activationHost = e->getStringAttribute("activationHost");
						int activationPort = e->getIntAttribute("activationPort");
						String activationAddress = e->getStringAttribute("activationAddress");
						int startMarkerPosition = e->getIntAttribute("startMarkerPosition");
						int endMarkerPosition = e->getIntAttribute("endMarkerPosition");
						bool relativeFollowing = e->getBoolAttribute("relativeFollowing", false);

						MainComponent* mc = new MainComponent();
						TimeLineController* tlc = mc->getTimeLineController();

						int numOfSamples = e->getIntAttribute("numOfSamples");
						int numOfDimensions = e->getIntAttribute("numOfDimensions");

						for (int ii=0; ii<numOfSamples; ii++)
						{
							String sampleIdentifier = "Sample_" + String(ii);
							XmlElement* sampleElement = e->getChildByName(sampleIdentifier);

							RecordedSample sample;
							sample.timestamp = sampleElement->getDoubleAttribute("timestamp");

							for (int iii=0; iii<numOfDimensions; iii++)
							{
								sample.value.push_back(sampleElement->getDoubleAttribute(String(iii)));
							}

							tlc->stl->samples.push_back(sample);
						}
					
						tlc->fpsEditor->setText(String(fps));
						tlc->durationEditor->setText(String(duration));
						tlc->recordingComboBox->setSelectedItemIndex(numberOfRecordings);
						tlc->receivingAddressesEditor->setText(oscAddresses);
						tlc->hostEditor->setText(hostAddress);
						tlc->portEditor->setText(String(port));
						tlc->addressEditor->setText(address);
						tlc->typeComboBox->setSelectedItemIndex(type);
						tlc->windowKnob->setValue(window);
						tlc->trajectoryToleranceKnob->setValue(tolerance);
						tlc->speedToleranceKnob->setValue(speedTolerance);
						tlc->likelihoodSetter->setThreshold(likelihoodThreshold);
						tlc->smoothnessSetter->setThreshold(smoothnessThreshold);
						tlc->activationHostEditor->setText(activationHost);
						tlc->activationPortEditor->setText(String(activationPort));
						tlc->activationAddressEditor->setText(activationAddress);

						tlc->stl->milliDuration = (int)duration*1000;
						tlc->stl->recordingFinished();

						tlc->stl->startMarkerPosition = startMarkerPosition;
						tlc->stl->endMarkerPosition = endMarkerPosition;
						tlc->changeListenerCallback(0);

						tlc->reconfigureOscReceiving();

						tlc->prepareTimelineSending();
						tlc->prepareActivationSending();

						tlc->relativeToggleButton->setToggleState(relativeFollowing, true);
						tlc->followToggleButton->setToggleState(follow, true);

						MVC->addGesture(name, mc);
					}

					MVC->addPlusTab();
				}
			}

			//Cleaning up:
			if (configurationElement)
				delete configurationElement;
		}
	}

public:
	MainviewComponent* MVC;

    //==============================================================================
    MainWindow() : DocumentWindow ("OscMotivator v0.11", Colours::lightgrey, DocumentWindow::allButtons, true)
    {
        MainviewComponent* const mainviewComponent = new MainviewComponent();
		MVC = mainviewComponent;

		Pool::Instance()->reg("MainviewComponent", MVC);

        setContentOwned (mainviewComponent, true);

        centreWithSize (640, 640);

		setMenuBar(this, 25);

		setResizable(false, false);
        setVisible (true);
    }

    ~MainWindow()
    {
        // (the content component will be deleted automatically, so no need to do it here)
		setMenuBar(0);
    }

	const StringArray getMenuBarNames()
	{
		StringArray result;
		result.add("File");
		result.add("Help");

		return result;
	}

	const PopupMenu getMenuForIndex (int topLevelMenuIndex, const String &menuName)
	{
		PopupMenu menu;

		if (topLevelMenuIndex == 0)
		{
			menu.addItem(1, "Load...");
			menu.addItem(2, "Save...");
			menu.addSeparator();
			menu.addItem(3, "Quit");
		}
		else if (topLevelMenuIndex == 1)
		{
			menu.addItem(1, "Go to homepage");
			menu.addItem(2, "Info...");
		}

		return menu;
	}

	void menuItemSelected (int menuItemID, int topLevelMenuIndex)
	{
		if (topLevelMenuIndex==0 && menuItemID==3)
		{
			closeButtonPressed();
		}
		else if (topLevelMenuIndex==0 && menuItemID==1) // Load...
		{
			load();
		}
		else if (topLevelMenuIndex==0 && menuItemID==2) // Save...
		{
			save();
		}
	}

    //==============================================================================
    void closeButtonPressed()
    {
        JUCEApplication::quit();
    }
};

//==============================================================================
class OscMotivatorApplication  : public JUCEApplication
{
public:
    //==============================================================================
    OscMotivatorApplication() : mainWindow(0)
    {
    }

    ~OscMotivatorApplication()
    {
    }

    //==============================================================================
    void initialise (const String& commandLine)
    {
	/*	
		#ifdef _DEBUG
			int flag = _CrtSetDbgFlag(_CRTDBG_REPORT_FLAG);
			flag |= _CRTDBG_LEAK_CHECK_DF; // Turn on leak-checking bit
			_CrtSetDbgFlag(flag);
			_CrtSetBreakAlloc(2911);
		#endif
	
		DebugComponent* debug = new DebugComponent();
		Pool::Instance()->reg("DebugComponent", debug);
		rw = new DocumentWindow ("Debug", juce::Colours::white, false);
		rw->setContentComponent(debug);
		rw->setSize(300, 300);
		rw->setVisible(true);
		rw->setResizable(true, true);
*/
		String  parameter = commandLine.fromFirstOccurrenceOf("-r", false, true);
		if (parameter.length())
		{
			int remotePort = parameter.getIntValue();

			OscManager::getInstance()->registerReceiver("/resetFollowing", 0, remotePort, 0);
			OscManager::getInstance()->registerReceiver("/startControl", 0, remotePort, 0);
			OscManager::getInstance()->registerReceiver("/stopControl", 0, remotePort, 0);
		}

        mainWindow = new MainWindow();
		OscManager::getInstance()->startThread();
		fftw_cleanup();
    }

    void shutdown()
    {
        mainWindow = 0;
		OscManager::getInstance()->stop();
		OscManager::deleteInstance();
		Pool::Instance()->cleanUp();

		fftw_cleanup();
    }

    //==============================================================================
    void systemRequestedQuit()
    {
        quit();
    }

    //==============================================================================
    const String getApplicationName()
    {
        return "OscMotivator";
    }

    const String getApplicationVersion()
    {
        return "0.1";
    }

    bool moreThanOneInstanceAllowed()
    {
        return true;
    }

    void anotherInstanceStarted (const String& commandLine)
    {
        
    }

private:
    ScopedPointer<MainWindow> mainWindow;
	ScopedPointer<DocumentWindow> rw;

};

//==============================================================================
// This macro generates the main() routine that starts the app.
START_JUCE_APPLICATION(OscMotivatorApplication)
