/*
  ==============================================================================

  This is an automatically generated file created by the Jucer!

  Creation date:  25 Jun 2013 2:44:15pm

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Jucer version: 1.12

  ------------------------------------------------------------------------------

  The Jucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-6 by Raw Material Software ltd.

  ==============================================================================
*/

#ifndef __JUCER_HEADER_MAINVIEWCOMPONENT_MAINVIEWCOMPONENT_85612CEA__
#define __JUCER_HEADER_MAINVIEWCOMPONENT_MAINVIEWCOMPONENT_85612CEA__

//[Headers]     -- You can add your own extra header files here --
#include "../JuceLibraryCode/JuceHeader.h"

class MyTabbedComponent  : public TabbedComponent
{
public:
    //==============================================================================
	MyTabbedComponent (TabbedButtonBar::Orientation orientation);
	~MyTabbedComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	void currentTabChanged (int newCurrentTabIndex, const String &newCurrentTabName);
	void popupMenuClickOnTab (int tabIndex, const String &tabName);
    //[/UserMethods]

    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================


    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    MyTabbedComponent (const MyTabbedComponent&);
    const MyTabbedComponent& operator= (const MyTabbedComponent&);
};

class MainComponent;
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Jucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class MainviewComponent  : public Component
{
public:
    //==============================================================================
    MainviewComponent ();
    ~MainviewComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
	void currentTabChanged (int newCurrentTabIndex, const String &newCurrentTabName);
	void popupMenuClickOnTab (int tabIndex, const String &tabName);

	Component* getMainComponent(int index);
	String getNameOfGesture(int index);
	int getNumberOfGestures();

	void unregisterReceivers();
	void clearGestures();

	void addGesture(String name, MainComponent* mc);
	void addPlusTab();
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();



    //==============================================================================
    juce_UseDebuggingNewOperator

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    MyTabbedComponent* tabbedComponent;


    //==============================================================================
    // (prevent copy constructor and operator= being generated..)
    MainviewComponent (const MainviewComponent&);
    const MainviewComponent& operator= (const MainviewComponent&);
};


#endif   // __JUCER_HEADER_MAINVIEWCOMPONENT_MAINVIEWCOMPONENT_85612CEA__
