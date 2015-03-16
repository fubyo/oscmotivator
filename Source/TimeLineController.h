/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  19 Jul 2013 2:58:52pm

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.12

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_TIMELINECONTROLLER_TIMELINECONTROLLER_4AE04CE8__
#define __JUCER_HEADER_TIMELINECONTROLLER_TIMELINECONTROLLER_4AE04CE8__

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "../oscpack/osc/OscOutboundPacketStream.h"
#include "../oscpack/ip/UdpSocket.h"
#include "../oscpack/osc/OscReceivedElements.h"
#include "../oscpack/osc/OscPacketListener.h"
#include "SignalTimeLine.h"
#include <fftw3.h>
#include "FollowingHMM.h"
//[/Headers]

#include "ThresholdSetter.h"


//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Jucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class TimeLineController  : public Component,
                            public Timer,
                            public TextEditorListener,
                            public ChangeListener,
                            public ButtonListener,
                            public ComboBoxListener,
                            public SliderListener
{
public:
    //==============================================================================
    TimeLineController ();
    ~TimeLineController();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	friend class MainWindow;

	void timerCallback();

	void reconfigureOscReceiving();
	void parseLine(String line);
	vector<double*> currentValues;

	vector<double> lastValues;
	vector<double> bestValuesAtFollowingPosition;
	bool relativeFollowing;

	void textEditorTextChanged (TextEditor &textEditor);
	void textEditorFocusLost (TextEditor &textEditor);
	void textEditorReturnKeyPressed (TextEditor &textEditor);
	void textEditorEscapeKeyPressed (TextEditor &textEditor);

	bool following;
	bool recording;

	SignalTimeLine* stl;
	double durationInSeconds;

	void changeListenerCallback	(ChangeBroadcaster *source);

	void configureHMM(int startMillisecondsTime, int endMillisecondsTime);

	double hmmIndexToTime(int index);
	int timeToHmmIndex(double time);
	double timeToHmmIndexAsDouble(double time);

	vector<double> getCurrentValueVector();

	void sendGestureActivationIfNeeded();
	void unregisterReceivers();

	void resetFollowing();
	void startFollowing();
	void stopFollowing();
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();
    void buttonClicked (Button* buttonThatWasClicked);
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged);
    void sliderValueChanged (Slider* sliderThatWasMoved);



    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	int millisecondsInterval;
	int millisecondsRecorded;

	ScopedPointer<DatagramSocket> timelineSocket;
	ScopedPointer<DatagramSocket> activationSocket;

	char buffer[1024];
	void prepareTimelineSending();
	void prepareActivationSending();
	void sendTimeline();

	FollowingHMM HMM;

	CriticalSection cs;

	bool gestureIsActive;

	//Smoothness measurement
	double progressionBuffer[512];
	int progressionBufferSize;
	int K;
	int NC;
	fftw_plan fftplan;
	fftw_complex *fftout;
	void addProgressionValueToBuffer(double progressionValue);
	void initializeSpectralArcLengthCalculation();
	double getSpectralArcLengthSmoothness();
	void releaseFFTW();

	void saveCurrentValues();
    //[/UserVariables]

    //==============================================================================
    GroupComponent* groupComponent;
    TextButton* recordButton;
    Label* label2;
    TextEditor* durationEditor;
    ComboBox* recordingComboBox;
    Slider* slider;
    ToggleButton* followToggleButton;
    Label* label4;
    TextEditor* fpsEditor;
    Label* label5;
    TextEditor* hostEditor;
    Label* label6;
    TextEditor* portEditor;
    Label* label7;
    TextEditor* addressEditor;
    Label* label3;
    Label* label8;
    ComboBox* typeComboBox;
    Label* label9;
    Slider* windowKnob;
    Label* label10;
    Slider* trajectoryToleranceKnob;
    GroupComponent* groupComponent2;
    Label* label14;
    TextEditor* activationHostEditor;
    Label* label15;
    TextEditor* activationPortEditor;
    Label* label16;
    TextEditor* activationAddressEditor;
    Label* label;
    Label* label17;
    Label* speedToleranceKnobLabel;
    Slider* speedToleranceKnob;
    Viewport* signalViewport;
    TextEditor* receivingAddressesEditor;
    Label* label11;
    ThresholdSetter* likelihoodSetter;
    ThresholdSetter* smoothnessSetter;
    ToggleButton* relativeToggleButton;
    TextButton* setButton;
    Path internalPath1;


    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    TimeLineController (const TimeLineController&);
    const TimeLineController& operator= (const TimeLineController&);
};


#endif   // __JUCER_HEADER_TIMELINECONTROLLER_TIMELINECONTROLLER_4AE04CE8__
