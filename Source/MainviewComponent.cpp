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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "MainviewComponent.h"
#include "C:/Users/marinos/Promotion/Tools/oscmotivator/Source/MainComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
#include "Pool.h"
//[/MiscUserDefs]

//==============================================================================
MainviewComponent::MainviewComponent ()
    : tabbedComponent (0)
{
    addAndMakeVisible (tabbedComponent = new MyTabbedComponent (TabbedButtonBar::TabsAtTop));
    tabbedComponent->setTabBarDepth (30);
    tabbedComponent->addTab (L"New Gesture", Colour (0xffdfdfdf), new MainComponent(), true);
    tabbedComponent->addTab (L"+", Colours::lightgrey, 0, false);
    tabbedComponent->setCurrentTabIndex (0);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (640, 600);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

MainviewComponent::~MainviewComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    deleteAndZero (tabbedComponent);


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MainviewComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xfffcfcfc));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MainviewComponent::resized()
{
    tabbedComponent->setBounds (0, 0, 640, 600);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void MainviewComponent::addPlusTab()
{
	tabbedComponent->addTab (L"+", Colours::lightgrey, 0, false);
}

void MainviewComponent::addGesture(String name, MainComponent* mc)
{
	 tabbedComponent->addTab (name, Colour (0xffdfdfdf), mc, true);
}

void MainviewComponent::unregisterReceivers()
{
	int getNumOfTabs =  tabbedComponent->getNumTabs()-1;

	for (int i=0; i<getNumOfTabs; i++)
	{
		MainComponent* mc = (MainComponent*)tabbedComponent->getTabContentComponent(i);
		mc->getTimeLineController()->unregisterReceivers();
	}
}

void MainviewComponent::clearGestures()
{
	tabbedComponent->clearTabs();
}

int MainviewComponent::getNumberOfGestures()
{
	return tabbedComponent->getNumTabs()-1;
}

Component* MainviewComponent::getMainComponent(int index)
{
	if (index == -1)
		return 0;

	return tabbedComponent->getTabContentComponent(index);
}

String MainviewComponent::getNameOfGesture(int index)
{
	return tabbedComponent->getTabNames()[index];
}

void MyTabbedComponent::currentTabChanged (int newCurrentTabIndex, const String &newCurrentTabName)
{
	if (newCurrentTabIndex!=-1 && newCurrentTabIndex == getNumTabs()-1 && getNumTabs()!=1) //New tab
	{
		addTab (L"New Gesture", Colour (0xffdfdfdf), new MainComponent(), true, getNumTabs()-1);
		setCurrentTabIndex(getNumTabs()-2);
	}
}

void MyTabbedComponent::popupMenuClickOnTab (int tabIndex, const String &tabName)
{
	PopupMenu m;
    m.addItem(1, "Rename...");
    m.addItem(2, "Close");

    const int result = m.show();

    if(result == 1)
    {
            TextEditor* textEditor = new TextEditor;
            textEditor->setMultiLine (false);
            textEditor->setReturnKeyStartsNewLine (false);
            textEditor->setReadOnly (false);
            textEditor->setScrollbarsShown (false);
            textEditor->setCaretVisible (true);
            textEditor->setPopupMenuEnabled (false);
            textEditor->setText (tabName);
            textEditor->setSize (400, 20);

            DialogWindow::showModalDialog("Rename...", textEditor, getCurrentContentComponent(), Colours::lightgrey, true, false, true);

            setTabName(tabIndex, textEditor->getText());
            delete textEditor;
    }
    else if (result == 2)
    {
            if (!(tabIndex==0 && getNumTabs()==2))
            {
                    int selectedTab = getCurrentTabIndex();
                    removeTab(tabIndex);
					setCurrentTabIndex(0);
            }
    }
}


MyTabbedComponent::MyTabbedComponent(TabbedButtonBar::Orientation orientation) : TabbedComponent(orientation)
{

}

MyTabbedComponent::~MyTabbedComponent()
{

}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Jucer information section --

    This is where the Jucer puts all of its metadata, so don't change anything in here!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MainviewComponent" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330000013"
                 fixedSize="1" initialWidth="640" initialHeight="600">
  <BACKGROUND backgroundColour="fffcfcfc"/>
  <TABBEDCOMPONENT name="new tabbed component" id="56de13125d26f02c" memberName="tabbedComponent"
                   virtualName="" explicitFocusOrder="0" pos="0 0 640 600" orientation="top"
                   tabBarDepth="30" initialTab="0">
    <TAB name="New Gesture" colour="ffdfdfdf" useJucerComp="1" contentClassName=""
         constructorParams="" jucerComponentFile="C:/Users/marinos/Promotion/Tools/oscmotivator/Source/MainComponent.cpp"/>
    <TAB name="+" colour="ffd3d3d3" useJucerComp="0" contentClassName=""
         constructorParams="" jucerComponentFile=""/>
  </TABBEDCOMPONENT>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif
