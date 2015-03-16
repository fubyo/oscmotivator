/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  27 Jun 2013 4:39:07pm

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

#include "ThresholdSetter.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
ThresholdSetter::ThresholdSetter ()
{

    //[UserPreSize]
    //[/UserPreSize]

    setSize (560, 10);


    //[Constructor] You can add your own custom stuff here..
	value = 0;
	threshold = 0;
    //[/Constructor]
}

ThresholdSetter::~ThresholdSetter()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]



    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void ThresholdSetter::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    //[UserPaint] Add your own custom painting code here..
	int width = getWidth();
	int height = getHeight();

	g.setColour(juce::Colours::blue);
	g.drawRect(0,0, (int)(value*width),height, 5);

	g.setColour(juce::Colours::red);
	g.drawLine((int)(threshold*width), 0, (int)(threshold*width), height, 3);
    //[/UserPaint]
}

void ThresholdSetter::resized()
{
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void ThresholdSetter::mouseDown (const MouseEvent& e)
{
    //[UserCode_mouseDown] -- Add your code here...
	int x = e.getMouseDownX();
	threshold = (double)x/getWidth();

	repaint();
    //[/UserCode_mouseDown]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void ThresholdSetter::setValue(double Value)
{
	if (Value>1)
		Value = 1;

	if (Value<0)
		Value = 0;

	value = Value;
	repaint();
}

bool ThresholdSetter::thresholdExceeded()
{
	return value>=threshold;
}

double ThresholdSetter::getThreshold()
{
	return threshold;
}

void ThresholdSetter::setThreshold(double Threshold)
{
	threshold = Threshold;
	repaint();
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Jucer information section --

    This is where the Jucer puts all of its metadata, so don't change anything in here!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="ThresholdSetter" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330000013"
                 fixedSize="1" initialWidth="560" initialHeight="10">
  <METHODS>
    <METHOD name="mouseDown (const MouseEvent&amp; e)"/>
  </METHODS>
  <BACKGROUND backgroundColour="ffffffff"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif
