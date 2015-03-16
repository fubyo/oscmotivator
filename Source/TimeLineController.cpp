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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "TimeLineController.h"
#include "SignalTimeLine.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
TimeLineController::TimeLineController ()
    : groupComponent (0),
      recordButton (0),
      label2 (0),
      durationEditor (0),
      recordingComboBox (0),
      slider (0),
      followToggleButton (0),
      label4 (0),
      fpsEditor (0),
      label5 (0),
      hostEditor (0),
      label6 (0),
      portEditor (0),
      label7 (0),
      addressEditor (0),
      label3 (0),
      label8 (0),
      typeComboBox (0),
      label9 (0),
      windowKnob (0),
      label10 (0),
      trajectoryToleranceKnob (0),
      groupComponent2 (0),
      label14 (0),
      activationHostEditor (0),
      label15 (0),
      activationPortEditor (0),
      label16 (0),
      activationAddressEditor (0),
      label (0),
      label17 (0),
      speedToleranceKnobLabel (0),
      speedToleranceKnob (0),
      signalViewport (0),
      receivingAddressesEditor (0),
      label11 (0),
      likelihoodSetter (0),
      smoothnessSetter (0),
      relativeToggleButton (0),
      setButton (0)
{
    addAndMakeVisible (groupComponent = new GroupComponent (L"new group",
                                                            L"Follow parameters"));

    addAndMakeVisible (recordButton = new TextButton (L"new button"));
    recordButton->setButtonText (L"Record");
    recordButton->addListener (this);
    recordButton->setColour (TextButton::buttonColourId, Colour (0xfffd826b));
    recordButton->setColour (TextButton::buttonOnColourId, Colour (0xfff23c3c));

    addAndMakeVisible (label2 = new Label (L"new label",
                                           L"Duration"));
    label2->setFont (Font (15.0000f, Font::plain));
    label2->setJustificationType (Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (durationEditor = new TextEditor (L"new text editor"));
    durationEditor->setMultiLine (false);
    durationEditor->setReturnKeyStartsNewLine (false);
    durationEditor->setReadOnly (false);
    durationEditor->setScrollbarsShown (true);
    durationEditor->setCaretVisible (true);
    durationEditor->setPopupMenuEnabled (true);
    durationEditor->setText (L"1.0");

    addAndMakeVisible (recordingComboBox = new ComboBox (L"new combo box"));
    recordingComboBox->setEditableText (false);
    recordingComboBox->setJustificationType (Justification::centredLeft);
    recordingComboBox->setTextWhenNothingSelected (L"0");
    recordingComboBox->setTextWhenNoChoicesAvailable (L"(no choices)");
    recordingComboBox->addItem (L"1", 1);
    recordingComboBox->addItem (L"2", 2);
    recordingComboBox->addItem (L"3", 3);
    recordingComboBox->addItem (L"4", 4);
    recordingComboBox->addItem (L"5", 5);
    recordingComboBox->addItem (L"6", 6);
    recordingComboBox->addItem (L"7", 7);
    recordingComboBox->addItem (L"8", 8);
    recordingComboBox->addListener (this);

    addAndMakeVisible (slider = new Slider (L"new slider"));
    slider->setRange (0, 1, 0);
    slider->setSliderStyle (Slider::LinearHorizontal);
    slider->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    slider->addListener (this);

    addAndMakeVisible (followToggleButton = new ToggleButton (L"new toggle button"));
    followToggleButton->setButtonText (L"Follow");
    followToggleButton->addListener (this);

    addAndMakeVisible (label4 = new Label (L"new label",
                                           L"FPS:"));
    label4->setFont (Font (15.0000f, Font::plain));
    label4->setJustificationType (Justification::centredLeft);
    label4->setEditable (false, false, false);
    label4->setColour (TextEditor::textColourId, Colours::black);
    label4->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (fpsEditor = new TextEditor (L"new text editor"));
    fpsEditor->setMultiLine (false);
    fpsEditor->setReturnKeyStartsNewLine (false);
    fpsEditor->setReadOnly (false);
    fpsEditor->setScrollbarsShown (true);
    fpsEditor->setCaretVisible (true);
    fpsEditor->setPopupMenuEnabled (true);
    fpsEditor->setText (L"50");

    addAndMakeVisible (label5 = new Label (L"new label",
                                           L"Host:"));
    label5->setFont (Font (15.0000f, Font::plain));
    label5->setJustificationType (Justification::centredLeft);
    label5->setEditable (false, false, false);
    label5->setColour (TextEditor::textColourId, Colours::black);
    label5->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (hostEditor = new TextEditor (L"new text editor"));
    hostEditor->setMultiLine (false);
    hostEditor->setReturnKeyStartsNewLine (false);
    hostEditor->setReadOnly (false);
    hostEditor->setScrollbarsShown (true);
    hostEditor->setCaretVisible (true);
    hostEditor->setPopupMenuEnabled (true);
    hostEditor->setText (L"127.0.0.1");

    addAndMakeVisible (label6 = new Label (L"new label",
                                           L"Port:"));
    label6->setFont (Font (15.0000f, Font::plain));
    label6->setJustificationType (Justification::centredLeft);
    label6->setEditable (false, false, false);
    label6->setColour (TextEditor::textColourId, Colours::black);
    label6->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (portEditor = new TextEditor (L"new text editor"));
    portEditor->setMultiLine (false);
    portEditor->setReturnKeyStartsNewLine (false);
    portEditor->setReadOnly (false);
    portEditor->setScrollbarsShown (true);
    portEditor->setCaretVisible (true);
    portEditor->setPopupMenuEnabled (true);
    portEditor->setText (L"3334");

    addAndMakeVisible (label7 = new Label (L"new label",
                                           L"Address:"));
    label7->setFont (Font (15.0000f, Font::plain));
    label7->setJustificationType (Justification::centredLeft);
    label7->setEditable (false, false, false);
    label7->setColour (TextEditor::textColourId, Colours::black);
    label7->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (addressEditor = new TextEditor (L"new text editor"));
    addressEditor->setMultiLine (false);
    addressEditor->setReturnKeyStartsNewLine (false);
    addressEditor->setReadOnly (false);
    addressEditor->setScrollbarsShown (true);
    addressEditor->setCaretVisible (true);
    addressEditor->setPopupMenuEnabled (true);
    addressEditor->setText (L"/timeline");

    addAndMakeVisible (label3 = new Label (L"new label",
                                           L"Recordings"));
    label3->setFont (Font (15.0000f, Font::plain));
    label3->setJustificationType (Justification::centredLeft);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label8 = new Label (L"new label",
                                           L"Type"));
    label8->setFont (Font (15.0000f, Font::plain));
    label8->setJustificationType (Justification::centredLeft);
    label8->setEditable (false, false, false);
    label8->setColour (TextEditor::textColourId, Colours::black);
    label8->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (typeComboBox = new ComboBox (L"new combo box"));
    typeComboBox->setEditableText (false);
    typeComboBox->setJustificationType (Justification::centredLeft);
    typeComboBox->setTextWhenNothingSelected (L"0");
    typeComboBox->setTextWhenNoChoicesAvailable (L"(no choices)");
    typeComboBox->addItem (L"One Shot", 1);
    typeComboBox->addItem (L"Ping Pong", 2);
    typeComboBox->addListener (this);

    addAndMakeVisible (label9 = new Label (L"new label",
                                           L"Window"));
    label9->setFont (Font (15.0000f, Font::plain));
    label9->setJustificationType (Justification::centredLeft);
    label9->setEditable (false, false, false);
    label9->setColour (TextEditor::textColourId, Colours::black);
    label9->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (windowKnob = new Slider (L"windowKnob"));
    windowKnob->setRange (0, 1, 0);
    windowKnob->setSliderStyle (Slider::RotaryVerticalDrag);
    windowKnob->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    windowKnob->addListener (this);

    addAndMakeVisible (label10 = new Label (L"new label",
                                            L"Trajectory tolerance"));
    label10->setFont (Font (15.0000f, Font::plain));
    label10->setJustificationType (Justification::centredLeft);
    label10->setEditable (false, false, false);
    label10->setColour (TextEditor::textColourId, Colours::black);
    label10->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (trajectoryToleranceKnob = new Slider (L"positionKnob"));
    trajectoryToleranceKnob->setRange (0.01, 0.4, 0);
    trajectoryToleranceKnob->setSliderStyle (Slider::RotaryVerticalDrag);
    trajectoryToleranceKnob->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    trajectoryToleranceKnob->addListener (this);

    addAndMakeVisible (groupComponent2 = new GroupComponent (L"new group",
                                                             L"Following activation"));

    addAndMakeVisible (label14 = new Label (L"new label",
                                            L"Host:"));
    label14->setFont (Font (15.0000f, Font::plain));
    label14->setJustificationType (Justification::centredLeft);
    label14->setEditable (false, false, false);
    label14->setColour (TextEditor::textColourId, Colours::black);
    label14->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (activationHostEditor = new TextEditor (L"new text editor"));
    activationHostEditor->setMultiLine (false);
    activationHostEditor->setReturnKeyStartsNewLine (false);
    activationHostEditor->setReadOnly (false);
    activationHostEditor->setScrollbarsShown (true);
    activationHostEditor->setCaretVisible (true);
    activationHostEditor->setPopupMenuEnabled (true);
    activationHostEditor->setText (L"127.0.0.1");

    addAndMakeVisible (label15 = new Label (L"new label",
                                            L"Port:"));
    label15->setFont (Font (15.0000f, Font::plain));
    label15->setJustificationType (Justification::centredLeft);
    label15->setEditable (false, false, false);
    label15->setColour (TextEditor::textColourId, Colours::black);
    label15->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (activationPortEditor = new TextEditor (L"new text editor"));
    activationPortEditor->setMultiLine (false);
    activationPortEditor->setReturnKeyStartsNewLine (false);
    activationPortEditor->setReadOnly (false);
    activationPortEditor->setScrollbarsShown (true);
    activationPortEditor->setCaretVisible (true);
    activationPortEditor->setPopupMenuEnabled (true);
    activationPortEditor->setText (L"3334");

    addAndMakeVisible (label16 = new Label (L"new label",
                                            L"Address:"));
    label16->setFont (Font (15.0000f, Font::plain));
    label16->setJustificationType (Justification::centredLeft);
    label16->setEditable (false, false, false);
    label16->setColour (TextEditor::textColourId, Colours::black);
    label16->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (activationAddressEditor = new TextEditor (L"new text editor"));
    activationAddressEditor->setMultiLine (false);
    activationAddressEditor->setReturnKeyStartsNewLine (false);
    activationAddressEditor->setReadOnly (false);
    activationAddressEditor->setScrollbarsShown (true);
    activationAddressEditor->setCaretVisible (true);
    activationAddressEditor->setPopupMenuEnabled (true);
    activationAddressEditor->setText (L"/activate");

    addAndMakeVisible (label = new Label (L"new label",
                                          L"Likelihood"));
    label->setFont (Font (15.0000f, Font::plain));
    label->setJustificationType (Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (label17 = new Label (L"new label",
                                            L"Following smoothness"));
    label17->setFont (Font (15.0000f, Font::plain));
    label17->setJustificationType (Justification::centredLeft);
    label17->setEditable (false, false, false);
    label17->setColour (TextEditor::textColourId, Colours::black);
    label17->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (speedToleranceKnobLabel = new Label (L"new label",
                                                            L"Speed tolerance"));
    speedToleranceKnobLabel->setFont (Font (15.0000f, Font::plain));
    speedToleranceKnobLabel->setJustificationType (Justification::centredLeft);
    speedToleranceKnobLabel->setEditable (false, false, false);
    speedToleranceKnobLabel->setColour (TextEditor::textColourId, Colours::black);
    speedToleranceKnobLabel->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (speedToleranceKnob = new Slider (L"positionKnob"));
    speedToleranceKnob->setRange (0, 1, 0);
    speedToleranceKnob->setSliderStyle (Slider::RotaryVerticalDrag);
    speedToleranceKnob->setTextBoxStyle (Slider::NoTextBox, false, 80, 20);
    speedToleranceKnob->addListener (this);

    addAndMakeVisible (signalViewport = new Viewport (L"new viewport"));
    signalViewport->setScrollBarsShown (false, true);
    signalViewport->setScrollBarThickness (10);
    signalViewport->setViewedComponent (new SignalTimeLine());

    addAndMakeVisible (receivingAddressesEditor = new TextEditor (L"new text editor"));
    receivingAddressesEditor->setMultiLine (true);
    receivingAddressesEditor->setReturnKeyStartsNewLine (true);
    receivingAddressesEditor->setReadOnly (false);
    receivingAddressesEditor->setScrollbarsShown (true);
    receivingAddressesEditor->setCaretVisible (true);
    receivingAddressesEditor->setPopupMenuEnabled (true);
    receivingAddressesEditor->setText (String::empty);

    addAndMakeVisible (label11 = new Label (L"new label",
                                            L"OSC receiving addresses     Format: <port> <address> <parameter index> "));
    label11->setFont (Font (15.0000f, Font::plain));
    label11->setJustificationType (Justification::centredLeft);
    label11->setEditable (false, false, false);
    label11->setColour (TextEditor::textColourId, Colours::black);
    label11->setColour (TextEditor::backgroundColourId, Colour (0x0));

    addAndMakeVisible (likelihoodSetter = new ThresholdSetter());
    addAndMakeVisible (smoothnessSetter = new ThresholdSetter());
    addAndMakeVisible (relativeToggleButton = new ToggleButton (L"new toggle button"));
    relativeToggleButton->setButtonText (L"Relative Coordinate Following");
    relativeToggleButton->addListener (this);

    addAndMakeVisible (setButton = new TextButton (L"new button"));
    setButton->setButtonText (L"Set");
    setButton->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (640, 620);


    //[Constructor] You can add your own custom stuff here..
	windowKnob->setValue(0.1);
	trajectoryToleranceKnob->setValue(0.1);
	speedToleranceKnob->setValue(0.1);

	typeComboBox->setSelectedItemIndex(0);
	recordingComboBox->setSelectedItemIndex(0);

	receivingAddressesEditor->addListener(this);
	fpsEditor->addListener(this);
	durationEditor->addListener(this);
	portEditor->addListener(this);
	hostEditor->addListener(this);
	activationPortEditor->addListener(this);
	activationHostEditor->addListener(this);

	following = false;
	recording = false;

	millisecondsInterval = (int)1000.0/fpsEditor->getText().getIntValue();
	millisecondsRecorded = 0;

	stl = (SignalTimeLine*)signalViewport->getViewedComponent();
	stl->addChangeListener(this);

	durationInSeconds = durationEditor->getText().getDoubleValue();
	stl->milliDuration = (int)durationInSeconds*1000;

	slider->setRange(0, durationInSeconds);

	timelineSocket = new DatagramSocket(0);
	prepareTimelineSending();

	windowKnob->setValue(0.25);
	speedToleranceKnob->setValue(0.50);
	trajectoryToleranceKnob->setValue(0.05);

	gestureIsActive = false;

	activationSocket = new DatagramSocket(0);
	prepareActivationSending();

	//Spectral Arc Length Stuff
	for(int i=0; i<512; i++)
		progressionBuffer[i]=0;

	progressionBufferSize = 16;
	fftout = 0;

	initializeSpectralArcLengthCalculation();
	K = (int)pow(2, log((double)progressionBufferSize)/log(2.0)+4);

	relativeFollowing = false;
    //[/Constructor]
}

TimeLineController::~TimeLineController()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    deleteAndZero (groupComponent);
    deleteAndZero (recordButton);
    deleteAndZero (label2);
    deleteAndZero (durationEditor);
    deleteAndZero (recordingComboBox);
    deleteAndZero (slider);
    deleteAndZero (followToggleButton);
    deleteAndZero (label4);
    deleteAndZero (fpsEditor);
    deleteAndZero (label5);
    deleteAndZero (hostEditor);
    deleteAndZero (label6);
    deleteAndZero (portEditor);
    deleteAndZero (label7);
    deleteAndZero (addressEditor);
    deleteAndZero (label3);
    deleteAndZero (label8);
    deleteAndZero (typeComboBox);
    deleteAndZero (label9);
    deleteAndZero (windowKnob);
    deleteAndZero (label10);
    deleteAndZero (trajectoryToleranceKnob);
    deleteAndZero (groupComponent2);
    deleteAndZero (label14);
    deleteAndZero (activationHostEditor);
    deleteAndZero (label15);
    deleteAndZero (activationPortEditor);
    deleteAndZero (label16);
    deleteAndZero (activationAddressEditor);
    deleteAndZero (label);
    deleteAndZero (label17);
    deleteAndZero (speedToleranceKnobLabel);
    deleteAndZero (speedToleranceKnob);
    deleteAndZero (signalViewport);
    deleteAndZero (receivingAddressesEditor);
    deleteAndZero (label11);
    deleteAndZero (likelihoodSetter);
    deleteAndZero (smoothnessSetter);
    deleteAndZero (relativeToggleButton);
    deleteAndZero (setButton);


    //[Destructor]. You can add your own custom destruction code here..
	for (int i=0;i<currentValues.size(); i++)
		delete [] currentValues[i];

	releaseFFTW();
    //[/Destructor]
}

//==============================================================================
void TimeLineController::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xffdbdbdb));

    g.setColour (Colour (0xffababab));
    g.fillPath (internalPath1);

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void TimeLineController::resized()
{
    groupComponent->setBounds (8, 368, 626, 48);
    recordButton->setBounds (552, 8, 80, 24);
    label2->setBounds (88, 8, 72, 24);
    durationEditor->setBounds (152, 8, 40, 24);
    recordingComboBox->setBounds (504, 8, 40, 24);
    slider->setBounds (3, 316, 634, 24);
    followToggleButton->setBounds (560, 337, 72, 24);
    label4->setBounds (8, 8, 40, 24);
    fpsEditor->setBounds (48, 8, 39, 24);
    label5->setBounds (8, 287, 48, 24);
    hostEditor->setBounds (48, 287, 96, 24);
    label6->setBounds (152, 287, 48, 24);
    portEditor->setBounds (191, 287, 49, 24);
    label7->setBounds (257, 287, 64, 24);
    addressEditor->setBounds (320, 287, 312, 24);
    label3->setBounds (424, 8, 87, 24);
    label8->setBounds (421, 337, 40, 24);
    typeComboBox->setBounds (461, 337, 96, 24);
    label9->setBounds (246, 384, 64, 24);
    windowKnob->setBounds (303, 384, 24, 24);
    label10->setBounds (333, 384, 147, 24);
    trajectoryToleranceKnob->setBounds (466, 384, 24, 24);
    groupComponent2->setBounds (8, 426, 625, 112);
    label14->setBounds (18, 502, 48, 24);
    activationHostEditor->setBounds (58, 502, 96, 24);
    label15->setBounds (162, 502, 48, 24);
    activationPortEditor->setBounds (201, 502, 41, 24);
    label16->setBounds (250, 502, 64, 24);
    activationAddressEditor->setBounds (314, 502, 102, 24);
    label->setBounds (19, 443, 150, 16);
    label17->setBounds (19, 472, 150, 16);
    speedToleranceKnobLabel->setBounds (487, 383, 112, 24);
    speedToleranceKnob->setBounds (595, 383, 24, 24);
    signalViewport->setBounds (10, 133, 622, 138);
    receivingAddressesEditor->setBounds (9, 62, 567, 63);
    label11->setBounds (9, 38, 496, 24);
    likelihoodSetter->setBounds (24, 460, 600, 10);
    smoothnessSetter->setBounds (24, 488, 600, 10);
    relativeToggleButton->setBounds (20, 384, 212, 24);
    setButton->setBounds (586, 84, 46, 24);
    internalPath1.clear();
    internalPath1.startNewSubPath (576.0f, 69.0f);
    internalPath1.lineTo (584.0f, 96.0f);
    internalPath1.lineTo (576.0f, 117.0f);
    internalPath1.closeSubPath();

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void TimeLineController::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == recordButton)
    {
        //[UserButtonCode_recordButton] -- add your button handler code here..
		recording = true;
		millisecondsRecorded = 0;
		stl->clearRecording();

		int fps = fpsEditor->getText().getIntValue();
		int millisecondIntervals = (int)1000.0/fps;
		startTimer(millisecondIntervals);

        //[/UserButtonCode_recordButton]
    }
    else if (buttonThatWasClicked == followToggleButton)
    {
        //[UserButtonCode_followToggleButton] -- add your button handler code here..
		if (followToggleButton->getToggleState())
		{
			recordButton->setEnabled(false);
			following =true;

			saveCurrentValues();

			int currentIndex = timeToHmmIndex(slider->getValue());
			HMM.setCurrentIndex(currentIndex);
			HMM.setWindow(windowKnob->getValue());
			HMM.transitionVariance = speedToleranceKnob->getValue();
			HMM.initialise();

			startTimer(millisecondsInterval);
		}
		else
		{
			recordButton->setEnabled(true);
			following = false;
			stopTimer();
		}

        //[/UserButtonCode_followToggleButton]
    }
    else if (buttonThatWasClicked == relativeToggleButton)
    {
        //[UserButtonCode_relativeToggleButton] -- add your button handler code here..
		const ScopedLock myScopedLock (cs);

		relativeFollowing =  relativeToggleButton->getToggleState();

		if (relativeFollowing)
		{
			int currentIndex = timeToHmmIndex(slider->getValue());
			HMM.setCurrentIndex(currentIndex);
			HMM.setWindow(windowKnob->getValue());
			HMM.transitionVariance = speedToleranceKnob->getValue();
			HMM.initialise();
		}

		saveCurrentValues();
        //[/UserButtonCode_relativeToggleButton]
    }
    else if (buttonThatWasClicked == setButton)
    {
        //[UserButtonCode_setButton] -- add your button handler code here..
		reconfigureOscReceiving();
        //[/UserButtonCode_setButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}

void TimeLineController::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == recordingComboBox)
    {
        //[UserComboBoxCode_recordingComboBox] -- add your combo box handling code here..

        //[/UserComboBoxCode_recordingComboBox]
    }
    else if (comboBoxThatHasChanged == typeComboBox)
    {
        //[UserComboBoxCode_typeComboBox] -- add your combo box handling code here..
		if (typeComboBox->getSelectedItemIndex() == 0)
			HMM.followingMode = Types::OneShot;
		else if (typeComboBox->getSelectedItemIndex() == 1)
			HMM.followingMode = Types::PingPong;

		HMM.initialise();
        //[/UserComboBoxCode_typeComboBox]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void TimeLineController::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]

    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == slider)
    {
        //[UserSliderCode_slider] -- add your slider handling code here..
		sendTimeline();
        //[/UserSliderCode_slider]
    }
    else if (sliderThatWasMoved == windowKnob)
    {
        //[UserSliderCode_windowKnob] -- add your slider handling code here..
		const ScopedLock myScopedLock (cs);

		HMM.setWindow(windowKnob->getValue());
		HMM.initialise();
        //[/UserSliderCode_windowKnob]
    }
    else if (sliderThatWasMoved == trajectoryToleranceKnob)
    {
        //[UserSliderCode_trajectoryToleranceKnob] -- add your slider handling code here..
		HMM.variance = trajectoryToleranceKnob->getValue();
        //[/UserSliderCode_trajectoryToleranceKnob]
    }
    else if (sliderThatWasMoved == speedToleranceKnob)
    {
        //[UserSliderCode_speedToleranceKnob] -- add your slider handling code here..
		const ScopedLock myScopedLock (cs);

		HMM.transitionVariance = speedToleranceKnob->getValue();
		HMM.initialise();
        //[/UserSliderCode_speedToleranceKnob]
    }

    //[UsersliderValueChanged_Post]

    //[/UsersliderValueChanged_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void TimeLineController::timerCallback()
{
	if (following)
	{
		const ScopedLock myScopedLock (cs);

		vector<double> valuevector = getCurrentValueVector();
		Sample sample;
		sample.values = getCurrentValueVector();

		int oldBestIndex = HMM.currentIndex;
		int bestIndex = oldBestIndex;

		if (HMM.samples.size() && sample.values.size() == HMM.samples[0].values.size())
		{
			bestIndex = HMM.follow(sample);

			if (HMM.followingMode == Types::OneShot && bestIndex<oldBestIndex)
				bestIndex = oldBestIndex;

			//Set the likelihood
			likelihoodSetter->setValue(HMM.confidence);
			if (!likelihoodSetter->thresholdExceeded())
				bestIndex = oldBestIndex;

			//update the slider
			double timelineValue = hmmIndexToTime(bestIndex);
			slider->setValue(timelineValue);

			//calculate and set the smoothness
			double progression = millisecondsInterval*(bestIndex-oldBestIndex);
			addProgressionValueToBuffer(progression);
			double smoothness = getSpectralArcLengthSmoothness()/10;
			smoothnessSetter->setValue(smoothness);

			//send activation message
			sendGestureActivationIfNeeded();

			//Finish by setting the current progression index
			HMM.setCurrentIndex(bestIndex);

			//if relative following then save the values for the next iteration
			if (relativeFollowing)
				saveCurrentValues();
		}
	}
	else if (recording)
	{
		int numOfRecordings = recordingComboBox->getSelectedItemIndex()+1;
		if (millisecondsRecorded > (int)1000.0*durationInSeconds*numOfRecordings)
		{
			recording = false;
		}
		else
		{
			vector<double> valuevector;
			for (int i = 0; i<currentValues.size(); i++)
				valuevector.push_back(currentValues[i][0]);

			int timestamp = millisecondsRecorded;
			stl->addSample(valuevector, (double) timestamp);

			int milliDuration = (int)(durationInSeconds*1000);
			slider->setValue((millisecondsRecorded%milliDuration)/1000.0);

			millisecondsRecorded+=millisecondsInterval;
		}
	}
	else
	{
		stopTimer();
		stl->recordingFinished();

		slider->setValue(0);
	}
}

void TimeLineController::unregisterReceivers()
{
	for (int i=0; i<currentValues.size(); i++)
	{
		OscManager::getInstance()->unregisterReceiver(currentValues[i]);
	}
}

void TimeLineController::reconfigureOscReceiving()
{
	//unregister old receivers
	for (int i=0; i<currentValues.size(); i++)
	{
		OscManager::getInstance()->unregisterReceiver(currentValues[i]);
	}

	//delete current values
	for (int i=0; i<currentValues.size(); i++)
	{
		delete [] currentValues[i];
	}
	currentValues.clear();

	//parse the
	String text = receivingAddressesEditor->getText();
	text = text.trim();

	bool moreLinesToParse = true;
	do
	{
		int indexOfEndLine = text.indexOf(String("\n"));
		if (indexOfEndLine==0 || indexOfEndLine==-1)
		{
			parseLine(text);
			moreLinesToParse = false;
		}
		else
		{
			String line = text.substring(0, indexOfEndLine);
			parseLine(line);

			text = text.substring(indexOfEndLine+1);
		}
	} while (moreLinesToParse);
}

void TimeLineController::parseLine(String line)
{
	line = line.trim();

	int port = 0;
	String address;
	int parameterIndex = -1;

	int indexOfSpace = line.indexOf(String(" "));
	if (indexOfSpace!=-1)
	{
		String temp=line.substring(0, indexOfSpace);
		temp = temp.trim();

		port = temp.getIntValue(); //get the port

		line = line.substring(indexOfSpace);
		line = line.trim();

		indexOfSpace = line.indexOf(String(" "));
		if (indexOfSpace!=-1)
		{
			temp = line.substring(0, indexOfSpace);
			temp = temp.trim();

			address = temp; //get the address

			line = line.substring(indexOfSpace);
			line = line.trim();

			parameterIndex = line.getIntValue(); //get the parameter index
		}
	}

	if (port>0 && address.length())
	{
		double* value = new double[4];
		currentValues.push_back(value);

		OscManager::getInstance()->registerReceiver(address, parameterIndex, port, value);
	}
}

void TimeLineController::textEditorTextChanged (TextEditor &textEditor)
{
	if (&textEditor == addressEditor)
	{
		reconfigureOscReceiving();
	}
	else if (&textEditor == durationEditor)
	{
		durationInSeconds = durationEditor->getText().getDoubleValue();
		stl->milliDuration = (int)(durationInSeconds*1000);
		slider->setRange(0, durationInSeconds);
	}
	else if (&textEditor == fpsEditor)
	{
		double fps = fpsEditor->getText().getDoubleValue();
		stl->fps = fps;
		if (fps)
			millisecondsInterval = (int)1000.0/fps;
		else
			millisecondsInterval = (int)(durationInSeconds*1000);

		startTimer(millisecondsInterval);
	}
}

void TimeLineController::textEditorFocusLost(TextEditor &textEditor)
{
	if (&textEditor == hostEditor || &textEditor == portEditor)
	{
		prepareTimelineSending();
	}
	else if (&textEditor == activationHostEditor || &textEditor == activationPortEditor)
	{
		prepareActivationSending();
	}
}

void TimeLineController::textEditorReturnKeyPressed (TextEditor &textEditor)
{
	if (&textEditor == hostEditor || &textEditor == portEditor)
	{
		prepareTimelineSending();
	}
	else if (&textEditor == activationHostEditor || &textEditor == activationPortEditor)
	{
		prepareActivationSending();
	}
}

void TimeLineController::textEditorEscapeKeyPressed (TextEditor &textEditor)
{
	if (&textEditor == hostEditor || &textEditor == portEditor)
	{
		prepareTimelineSending();
	}
	else if (&textEditor == activationHostEditor || &textEditor == activationPortEditor)
	{
		prepareActivationSending();
	}
}

void TimeLineController::prepareTimelineSending()
{
	timelineSocket->connect(hostEditor->getText(), portEditor->getText().getIntValue(), 100);
}

void TimeLineController::prepareActivationSending()
{
	activationSocket->connect(activationHostEditor->getText(), activationPortEditor->getText().getIntValue(), 100);
}

void TimeLineController::sendTimeline()
{
	osc::OutboundPacketStream p( buffer, 1024 );

	p << osc::BeginMessage( addressEditor->getText().toUTF8() );

	p << (float)slider->getValue();

	p << osc::EndMessage;

	timelineSocket->write(p.Data(), p.Size());
}

void TimeLineController::changeListenerCallback	(ChangeBroadcaster *source)
{
	const ScopedLock myScopedLock (cs);

	int startTime = stl->getStartMillisecondsTime();
	int endTime = stl->getEndMillisecondsTime();

	configureHMM(startTime, endTime);
}

void TimeLineController::configureHMM(int startMillisecondsTime, int endMillisecondsTime)
{
	HMM.clearSamples();

	//Feed the HMM with samples
	int timeIndex = startMillisecondsTime;
	for (timeIndex; timeIndex<=endMillisecondsTime; timeIndex+=millisecondsInterval)
	{
		Sample sample;
		sample.values = stl->getValue(timeIndex);
		HMM.addSample(sample);
	}

	int newIndex = timeToHmmIndex(slider->getValue());
	HMM.currentIndex = newIndex;

	//Initialize the HMM
	HMM.initialise();
}

double TimeLineController::hmmIndexToTime(int index)
{
	int numberOfStates = HMM.samples.size();
	return durationInSeconds*(double)index/(numberOfStates-1);
}

int TimeLineController::timeToHmmIndex(double time)
{
	int numberOfStates = HMM.samples.size();
	return (int)((numberOfStates-1)*(double)time/durationInSeconds);
}

double TimeLineController::timeToHmmIndexAsDouble(double time)
{
	int numberOfStates = HMM.samples.size();
	return ((numberOfStates-1.0)*(double)time/durationInSeconds);
}

vector<double> TimeLineController::getCurrentValueVector()
{
	vector<double> valuevector;

	if (relativeFollowing)
	{
		for (int i=0; i<lastValues.size(); i++)
		{
			valuevector.push_back(bestValuesAtFollowingPosition[i]+currentValues[i][0]-lastValues[i]);
		}
	}
	else
	{
		for (int i=0; i<currentValues.size(); i++)
		{
			valuevector.push_back(currentValues[i][0]);
		}
	}
	return valuevector;
}

void TimeLineController::addProgressionValueToBuffer(double progressionValue)
{
	//Shift values
	for (int i=0; i<progressionBufferSize-1; i++)
		progressionBuffer[i] = progressionBuffer[i+1];

	//Putting the new progressionValue at the end
	progressionBuffer[progressionBufferSize-1] = progressionValue;
}

void TimeLineController::initializeSpectralArcLengthCalculation()
{
	//Compute K
	K = (int)pow(2, log((double)progressionBufferSize)/log(2.0)+4);

	//Set up the output buffer
	NC = (K/2)+1;

	if (fftout!=0)
		fftw_free(fftout);

	fftout = (fftw_complex*)fftw_malloc ( sizeof ( fftw_complex ) * NC );

	//Create a FFT-plan
	fftplan = fftw_plan_dft_r2c_1d ( K, progressionBuffer, fftout, FFTW_ESTIMATE );
}

double TimeLineController::getSpectralArcLengthSmoothness()
{
	fftw_execute (fftplan);

	//Calculate magnitude spectrum
	vector<double> magnitudeSpektrum;
	for (int i=0; i<NC; i++)
	{
		double magnitude = sqrt(fftout[i][0]*fftout[i][0]+fftout[i][1]*fftout[i][1]);
		magnitudeSpektrum.push_back(magnitude);
	}

	double smoothness=-1000;

	if (magnitudeSpektrum[0])
	{
		//Normalize magnitude spectrum
		for (int i=NC-1; i>=0; i--)
		{
			magnitudeSpektrum[i] = magnitudeSpektrum[i]/magnitudeSpektrum[0];
		}

		smoothness = 0;

		for (int i = 1; i<NC; i++)
		{
			smoothness+= sqrt( (1/(NC-1))*(1/(NC-1)) + (magnitudeSpektrum[i]-magnitudeSpektrum[i-1])*(magnitudeSpektrum[i]-magnitudeSpektrum[i-1]) );
		}
	}

	return smoothness;
}

void TimeLineController::releaseFFTW()
{
	fftw_destroy_plan(fftplan);
	fftw_free(fftout);
}

void TimeLineController::sendGestureActivationIfNeeded()
{
	bool gestureIsSupposedToBeActive = (likelihoodSetter->thresholdExceeded() && smoothnessSetter->thresholdExceeded());

	bool sendIsNeeded = false;
	if (gestureIsSupposedToBeActive!=gestureIsActive)
	{
		gestureIsActive = gestureIsSupposedToBeActive;
		sendIsNeeded = true;
	}

	if (sendIsNeeded)
	{
		osc::OutboundPacketStream p( buffer, 1024 );

		p << osc::BeginMessage( activationAddressEditor->getText().toUTF8() );
		p << (float)gestureIsActive;
		p << osc::EndMessage;

		activationSocket->write(p.Data(), p.Size());
	}
}

void TimeLineController::resetFollowing()
{
	saveCurrentValues();

	slider->setValue(0);
	HMM.setCurrentIndex(0);
	HMM.setWindow(windowKnob->getValue());
	HMM.transitionVariance = speedToleranceKnob->getValue();
	HMM.initialise();
}

void TimeLineController::startFollowing()
{
	followToggleButton->setToggleState(true, true);
}

void TimeLineController::stopFollowing()
{
	followToggleButton->setToggleState(false, true);
}

void TimeLineController::saveCurrentValues()
{
	lastValues.clear();
	bestValuesAtFollowingPosition.clear();

	double currentIndex = timeToHmmIndex(slider->getValue());

	for (int i=0; i<currentValues.size(); i++)
	{
		lastValues.push_back(*currentValues[i]);
		bestValuesAtFollowingPosition.push_back(HMM.samples[currentIndex].values[i]);
	}
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Jucer information section --

    This is where the Jucer puts all of its metadata, so don't change anything in here!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="TimeLineController" componentName=""
                 parentClasses="public Component, public Timer, public TextEditorListener, public ChangeListener"
                 constructorParams="" variableInitialisers="" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330000013" fixedSize="1" initialWidth="640"
                 initialHeight="620">
  <BACKGROUND backgroundColour="ffdbdbdb">
    <PATH pos="0 0 100 100" fill="solid: ffababab" hasStroke="0" nonZeroWinding="1">s 576 69 l 584 96 l 576 117 x</PATH>
  </BACKGROUND>
  <GROUPCOMPONENT name="new group" id="6e897800f2a1d5f6" memberName="groupComponent"
                  virtualName="" explicitFocusOrder="0" pos="8 368 626 48" title="Follow parameters"/>
  <TEXTBUTTON name="new button" id="5ffab1948bfa4079" memberName="recordButton"
              virtualName="" explicitFocusOrder="0" pos="552 8 80 24" bgColOff="fffd826b"
              bgColOn="fff23c3c" buttonText="Record" connectedEdges="0" needsCallback="1"
              radioGroupId="0"/>
  <LABEL name="new label" id="32014d3f5a7587f2" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="88 8 72 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Duration" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <TEXTEDITOR name="new text editor" id="2f8a0268cc111f8c" memberName="durationEditor"
              virtualName="" explicitFocusOrder="0" pos="152 8 40 24" initialText="1.0"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <COMBOBOX name="new combo box" id="5877e0b30324a39a" memberName="recordingComboBox"
            virtualName="" explicitFocusOrder="0" pos="504 8 40 24" editable="0"
            layout="33" items="1&#10;2&#10;3&#10;4&#10;5&#10;6&#10;7&#10;8"
            textWhenNonSelected="0" textWhenNoItems="(no choices)"/>
  <SLIDER name="new slider" id="a7d4de3b4326c374" memberName="slider" virtualName=""
          explicitFocusOrder="0" pos="3 316 634 24" min="0" max="1" int="0"
          style="LinearHorizontal" textBoxPos="NoTextBox" textBoxEditable="1"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <TOGGLEBUTTON name="new toggle button" id="1776dec62ff27eb0" memberName="followToggleButton"
                virtualName="" explicitFocusOrder="0" pos="560 337 72 24" buttonText="Follow"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <LABEL name="new label" id="ee621b78b9e6dafe" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="8 8 40 24" edTextCol="ff000000" edBkgCol="0"
         labelText="FPS:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <TEXTEDITOR name="new text editor" id="e2f9fb7f42969672" memberName="fpsEditor"
              virtualName="" explicitFocusOrder="0" pos="48 8 39 24" initialText="50"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <LABEL name="new label" id="1046148a1d42cf38" memberName="label5" virtualName=""
         explicitFocusOrder="0" pos="8 287 48 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Host:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <TEXTEDITOR name="new text editor" id="70d9fcfd78ba9d09" memberName="hostEditor"
              virtualName="" explicitFocusOrder="0" pos="48 287 96 24" initialText="127.0.0.1"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <LABEL name="new label" id="45951e811295766" memberName="label6" virtualName=""
         explicitFocusOrder="0" pos="152 287 48 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Port:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <TEXTEDITOR name="new text editor" id="616577dda89ecc3f" memberName="portEditor"
              virtualName="" explicitFocusOrder="0" pos="191 287 49 24" initialText="3334"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <LABEL name="new label" id="790a41c663551859" memberName="label7" virtualName=""
         explicitFocusOrder="0" pos="257 287 64 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Address:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <TEXTEDITOR name="new text editor" id="b3dce6fdefe48402" memberName="addressEditor"
              virtualName="" explicitFocusOrder="0" pos="320 287 312 24" initialText="/timeline"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <LABEL name="new label" id="157b9369394ae6d2" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="424 8 87 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Recordings" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="23a3a081e73d9f18" memberName="label8" virtualName=""
         explicitFocusOrder="0" pos="421 337 40 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Type" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <COMBOBOX name="new combo box" id="f0daa0363c8d83d1" memberName="typeComboBox"
            virtualName="" explicitFocusOrder="0" pos="461 337 96 24" editable="0"
            layout="33" items="One Shot&#10;Ping Pong" textWhenNonSelected="0"
            textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="700c493adf05d675" memberName="label9" virtualName=""
         explicitFocusOrder="0" pos="246 384 64 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Window" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <SLIDER name="windowKnob" id="58a97716a2ac3da7" memberName="windowKnob"
          virtualName="" explicitFocusOrder="0" pos="303 384 24 24" min="0"
          max="1" int="0" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <LABEL name="new label" id="bec297a016f1c41" memberName="label10" virtualName=""
         explicitFocusOrder="0" pos="333 384 147 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Trajectory tolerance" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <SLIDER name="positionKnob" id="80a23f70a8d29505" memberName="trajectoryToleranceKnob"
          virtualName="" explicitFocusOrder="0" pos="466 384 24 24" min="0.01"
          max="0.4" int="0" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <GROUPCOMPONENT name="new group" id="19bc8deaeb6691ca" memberName="groupComponent2"
                  virtualName="" explicitFocusOrder="0" pos="8 426 625 112" title="Following activation"/>
  <LABEL name="new label" id="ca96da206109d5f" memberName="label14" virtualName=""
         explicitFocusOrder="0" pos="18 502 48 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Host:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <TEXTEDITOR name="new text editor" id="4f1cdbb79b4f8a37" memberName="activationHostEditor"
              virtualName="" explicitFocusOrder="0" pos="58 502 96 24" initialText="127.0.0.1"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <LABEL name="new label" id="13f3476eb8d22c87" memberName="label15" virtualName=""
         explicitFocusOrder="0" pos="162 502 48 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Port:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <TEXTEDITOR name="new text editor" id="83bef0a6bcc0e685" memberName="activationPortEditor"
              virtualName="" explicitFocusOrder="0" pos="201 502 41 24" initialText="3334"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <LABEL name="new label" id="34a43261bb46bde2" memberName="label16" virtualName=""
         explicitFocusOrder="0" pos="250 502 64 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Address:" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <TEXTEDITOR name="new text editor" id="3df960a2f0ce2430" memberName="activationAddressEditor"
              virtualName="" explicitFocusOrder="0" pos="314 502 102 24" initialText="/activate"
              multiline="0" retKeyStartsLine="0" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <LABEL name="new label" id="5aa788df583413d4" memberName="label" virtualName=""
         explicitFocusOrder="0" pos="19 443 150 16" edTextCol="ff000000"
         edBkgCol="0" labelText="Likelihood" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="15"
         bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="bfc16bf22ed14562" memberName="label17" virtualName=""
         explicitFocusOrder="0" pos="19 472 150 16" edTextCol="ff000000"
         edBkgCol="0" labelText="Following smoothness" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <LABEL name="new label" id="75bc934de93454d4" memberName="speedToleranceKnobLabel"
         virtualName="" explicitFocusOrder="0" pos="487 383 112 24" edTextCol="ff000000"
         edBkgCol="0" labelText="Speed tolerance" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default font"
         fontsize="15" bold="0" italic="0" justification="33"/>
  <SLIDER name="positionKnob" id="32e3b2d0e2ac1fe6" memberName="speedToleranceKnob"
          virtualName="" explicitFocusOrder="0" pos="595 383 24 24" min="0"
          max="1" int="0" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="1" textBoxWidth="80" textBoxHeight="20" skewFactor="1"/>
  <VIEWPORT name="new viewport" id="4ede3b1f7c36fa79" memberName="signalViewport"
            virtualName="" explicitFocusOrder="0" pos="10 133 622 138" vscroll="0"
            hscroll="1" scrollbarThickness="10" contentType="1" jucerFile="SignalTimeLine.cpp"
            contentClass="" constructorParams=""/>
  <TEXTEDITOR name="new text editor" id="c4e6256382b5db00" memberName="receivingAddressesEditor"
              virtualName="" explicitFocusOrder="0" pos="9 62 567 63" initialText=""
              multiline="1" retKeyStartsLine="1" readonly="0" scrollbars="1"
              caret="1" popupmenu="1"/>
  <LABEL name="new label" id="17f4ad862001e243" memberName="label11" virtualName=""
         explicitFocusOrder="0" pos="9 38 496 24" edTextCol="ff000000"
         edBkgCol="0" labelText="OSC receiving addresses     Format: &lt;port&gt; &lt;address&gt; &lt;parameter index&gt; "
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15" bold="0" italic="0" justification="33"/>
  <JUCERCOMP name="" id="c4e3bd2be0b048e2" memberName="likelihoodSetter" virtualName=""
             explicitFocusOrder="0" pos="24 460 600 10" sourceFile="ThresholdSetter.cpp"
             constructorParams=""/>
  <JUCERCOMP name="" id="ffce95e56c564a33" memberName="smoothnessSetter" virtualName=""
             explicitFocusOrder="0" pos="24 488 600 10" sourceFile="ThresholdSetter.cpp"
             constructorParams=""/>
  <TOGGLEBUTTON name="new toggle button" id="e856f05d92134849" memberName="relativeToggleButton"
                virtualName="" explicitFocusOrder="0" pos="20 384 212 24" buttonText="Relative Coordinate Following"
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TEXTBUTTON name="new button" id="a8063c2ca2ebc10e" memberName="setButton"
              virtualName="" explicitFocusOrder="0" pos="586 84 46 24" buttonText="Set"
              connectedEdges="0" needsCallback="1" radioGroupId="0"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif
