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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "SignalTimeLine.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
#include "TimeLineController.h"
#include "MainComponent.h"
//[/MiscUserDefs]

//==============================================================================
SignalTimeLine::SignalTimeLine ()
{

    //[UserPreSize]
    //[/UserPreSize]

    setSize (620, 128);


    //[Constructor] You can add your own custom stuff here..
	milliDuration = 0;
	defaultWidth = 620;
	numberOfRecordings = 1;

	startMarkerPosition = 0;
	endMarkerPosition = defaultWidth;
    //[/Constructor]
}

SignalTimeLine::~SignalTimeLine()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void SignalTimeLine::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xffededed));

    //[UserPaint] Add your own custom painting code here..

	//Render the signals
	int width = getWidth();
	int height = getHeight();
	int numberOfSamples = samples.size();
	vector<double> minmaxDifferences;
	int numberOfDimensions = minValues.size();

	for (int i=0; i<numberOfDimensions; i++)
		minmaxDifferences.push_back(maxValues[i]-minValues[i]);

	//for every sample pair (and every dimension), render a line
	if (numberOfSamples)
	{
		for (int i=0; i<numberOfSamples-1; i++)
		{
			g.setColour(juce::Colours::black);
			for (int j=0; j<numberOfDimensions; j++)
			{
				int x1 = i*width/(numberOfSamples-1);
				int y1 = height-height*(samples[i].value[j]-minValues[j])/minmaxDifferences[j];
				int x2 = (i+1)*width/(numberOfSamples-1);
				int y2 = height-height*(samples[i+1].value[j]-minValues[j])/minmaxDifferences[j];

				g.drawLine(x1, y1, x2, y2);
			}
		}
	}

	//render the start marker
	g.setColour(juce::Colours::red);
	g.drawLine(startMarkerPosition, 0, startMarkerPosition, height);
	g.drawText("start", startMarkerPosition+2, 1, 50, 20, juce::Justification::topLeft, false);

	g.setColour(juce::Colours::blue);
	g.drawLine(endMarkerPosition, 0, endMarkerPosition, height);
	g.drawText("end", endMarkerPosition-23, 1, 50, 20, juce::Justification::topLeft, false);
    //[/UserPaint]
}

void SignalTimeLine::resized()
{
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void SignalTimeLine::clearRecording()
{
	samples.clear();
	minValues.clear();
	maxValues.clear();
}

void SignalTimeLine::addSample(vector<double> value, double timeStamp)
{
	RecordedSample sample;
	sample.value = value;
	sample.timestamp = timeStamp;

	samples.push_back(sample);
}

void SignalTimeLine::recordingFinished()
{
	int numberOfDimensions = 0;
	if (samples.size())
	{
		minValues.clear();
		maxValues.clear();

		numberOfDimensions = samples[0].value.size();
		for (int i=0; i<numberOfDimensions; i++)
		{
			minValues.push_back(samples[0].value[i]);
			maxValues.push_back(samples[0].value[i]);
		}
	}

	for (int i=0; i<samples.size(); i++)
	{
		for (int j=0; j<numberOfDimensions; j++)
		{
			if (samples[i].value[j]>maxValues[j])
				maxValues[j] = samples[i].value[j];

			if (samples[i].value[j]<minValues[j])
				minValues[j] = samples[i].value[j];
		}
	}

	//Calculate width
	if (samples.size())
	{
		int milliSecondsTotalLength = samples[samples.size()-1].timestamp - samples[0].timestamp;
		numberOfRecordings = (int)floor((double)milliSecondsTotalLength/milliDuration+0.5);

		setSize(numberOfRecordings*defaultWidth, getHeight());
	}

	repaint();
}

void SignalTimeLine::mouseDown (const MouseEvent &event)
{
	int x = event.getMouseDownX();

	if (event.mods.isLeftButtonDown())
	{
		setStartMarker(x);
	}
	else if (event.mods.isRightButtonDown())
	{
		setEndMarker(x);
	}

	if (samples.size())
		sendChangeMessage();

	repaint();
}

int SignalTimeLine::xToMillisecondsTime(int xCoordinate)
{
	int milliSecondsTotalLength = 0;

	if (samples.size())
		milliSecondsTotalLength = samples[samples.size()-1].timestamp - samples[0].timestamp;

	return (int)((double)xCoordinate*milliSecondsTotalLength/getWidth());
}

void SignalTimeLine::setStartMarker(int xCoordinate)
{
	if (xCoordinate < endMarkerPosition)
		startMarkerPosition = xCoordinate;
}

void SignalTimeLine::setEndMarker(int xCoordinate)
{
	if (xCoordinate > startMarkerPosition)
		endMarkerPosition = xCoordinate;
}

int SignalTimeLine::getStartMillisecondsTime()
{
	return xToMillisecondsTime(startMarkerPosition);
}

int SignalTimeLine::getEndMillisecondsTime()
{
	return xToMillisecondsTime(endMarkerPosition);
}

vector<double> SignalTimeLine::getValue(int millisecondsTime)
{
	vector<double> vectorvalue;

	if (samples.size())
	{
		int index = -1;

		for (int i=0; i<samples.size()-1; i++)
		{
			if (millisecondsTime>=samples[i].timestamp && millisecondsTime<samples[i+1].timestamp)
			{
				index = i;
			}
		}

		int numberOfDimensions = samples[0].value.size();

		if (index!=-1)
		{
			double factor = (millisecondsTime - samples[index].timestamp)/(samples[index+1].timestamp - samples[index].timestamp);
			for (int i=0; i<numberOfDimensions; i++)
			{
				double value = samples[index].value[i]*(1-factor) + samples[index+1].value[i]*factor;
				vectorvalue.push_back(value);
			}
		}
		else
		{
			if (millisecondsTime<samples[0].timestamp)
				return samples[0].value;
			else if (millisecondsTime>=samples[samples.size()-1].timestamp)
				return samples[samples.size()-1].value;
		}
	}

	return vectorvalue;
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Jucer information section --

    This is where the Jucer puts all of its metadata, so don't change anything in here!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="SignalTimeLine" componentName=""
                 parentClasses="public Component, public ChangeBroadcaster" constructorParams=""
                 variableInitialisers="" snapPixels="8" snapActive="1" snapShown="1"
                 overlayOpacity="0.330000013" fixedSize="1" initialWidth="620"
                 initialHeight="128">
  <BACKGROUND backgroundColour="ffededed"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif
