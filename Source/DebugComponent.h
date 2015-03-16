/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  19 Jul 2013 12:43:39pm

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.12

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_DEBUGCOMPONENT_DEBUGCOMPONENT_A5E872ED__
#define __JUCER_HEADER_DEBUGCOMPONENT_DEBUGCOMPONENT_A5E872ED__

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Jucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class DebugComponent  : public Component
{
public:
    //==============================================================================
    DebugComponent ();
    ~DebugComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	void print(String text)
	{
		textEditor->setText(textEditor->getText() + text + String("\n"));
	};
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();



    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    TextEditor* textEditor;


    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    DebugComponent (const DebugComponent&);
    const DebugComponent& operator= (const DebugComponent&);
};


#endif   // __JUCER_HEADER_DEBUGCOMPONENT_DEBUGCOMPONENT_A5E872ED__
