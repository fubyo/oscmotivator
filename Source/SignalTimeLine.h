/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  26 Jun 2013 4:13:55pm

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.12

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_SIGNALTIMELINE_SIGNALTIMELINE_EE035F12__
#define __JUCER_HEADER_SIGNALTIMELINE_SIGNALTIMELINE_EE035F12__

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
#include "OscManager.h"
#include "Pool.h"

struct RecordedSample
{
	vector<double> value;
	double timestamp;
};

enum Features
{
	Value,
	Timestamp,
	Velocity,
	Acceleration
};

enum Types
{
	OneShot,
	PingPong,
	CircularForward,
	CircularPingPong
};

class TimeLineController;
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Jucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class SignalTimeLine  : public Component,
                        public ChangeBroadcaster
{
public:
    //==============================================================================
    SignalTimeLine ();
    ~SignalTimeLine();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	friend class MainWindow;

	vector<RecordedSample> samples;
	vector<double> minValues;
	vector<double> maxValues;
	int milliDuration;
	double fps;
	int defaultWidth;
	int numberOfRecordings;

	void clearRecording();
	void addSample(vector<double> value, double timeStamp);
	void recordingFinished();

	void mouseDown (const MouseEvent &event);

	int getStartMillisecondsTime();
	int getEndMillisecondsTime();

	vector<double> getValue(int millisecondsTime);
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();



    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
	int startMarkerPosition;
	int endMarkerPosition;
	//double xToTime(int xCoordinate);
	int xToMillisecondsTime(int xCoordinate);

	void setStartMarker(int xCoordinate);
	void setEndMarker(int xCoordinate);
    //[/UserVariables]

    //==============================================================================


    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    SignalTimeLine (const SignalTimeLine&);
    const SignalTimeLine& operator= (const SignalTimeLine&);
};


#endif   // __JUCER_HEADER_SIGNALTIMELINE_SIGNALTIMELINE_EE035F12__
