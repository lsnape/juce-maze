/*
  ==============================================================================

  This is an automatically generated GUI class created by the Introjucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Introjucer version: 3.1.0

  ------------------------------------------------------------------------------

  The Introjucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright 2004-13 by Raw Material Software Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "MazeGameComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
MazeGameComponent::MazeGameComponent ()
{
    addAndMakeVisible (playerListGroup = new GroupComponent ("players",
                                                             TRANS("Players")));
    playerListGroup->setColour (GroupComponent::outlineColourId, Colour (0x66dfdfdf));
    playerListGroup->setColour (GroupComponent::textColourId, Colour (0xffbebcbc));

    addAndMakeVisible (playerNameList = new ListBox());
    playerNameList->setName ("Player Name List");

    addAndMakeVisible (mazeComponent = new Component());
    mazeComponent->setName ("Maze Component");


    //[UserPreSize]
    connectionServer.setListener (&gameEngine);
    gameEngine.setListener (this);
    //[/UserPreSize]

    setSize (800, 600);


    //[Constructor] You can add your own custom stuff here..
    playerNameList->setModel (this);
    //[/Constructor]
}

MazeGameComponent::~MazeGameComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    playerListGroup = nullptr;
    playerNameList = nullptr;
    mazeComponent = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void MazeGameComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colour (0xff2e2e2e));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void MazeGameComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    playerListGroup->setBounds (proportionOfWidth (0.6000f), proportionOfHeight (0.0200f), proportionOfWidth (0.3800f), proportionOfHeight (0.9600f));
    playerNameList->setBounds (proportionOfWidth (0.6000f) + roundFloatToInt (proportionOfWidth (0.3800f) * 0.0493f), proportionOfHeight (0.0600f), roundFloatToInt (proportionOfWidth (0.3800f) * 0.9013f), proportionOfHeight (0.8900f));
    mazeComponent->setBounds (proportionOfWidth (0.0150f), proportionOfHeight (0.0400f), 460, 460);
    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
void MazeGameComponent::playerCreated (const Player& newPlayer)
{
    std::cout << "Player Created: " << newPlayer.name.toRawUTF8() << '\n';

    playerNameList->updateContent();
}

int MazeGameComponent::getNumRows()
{
    return gameEngine.getNumPlayers();
}

void MazeGameComponent::paintListBoxItem (int rowNumber,
                                          Graphics& g,
                                          int width, int height,
                                          bool rowIsSelected)
{
    g.setColour(Colours::blue);

    static const int padding = 5;
    g.drawText (gameEngine.getPlayerAtIndex (rowNumber).name,
                padding, padding,
                width - (2 * padding), height - (2 * padding), Justification::left);
}
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Introjucer information section --

    This is where the Introjucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="MazeGameComponent" componentName=""
                 parentClasses="public Component, public MazeGameListener, public ListBoxModel"
                 constructorParams="" variableInitialisers="" snapPixels="8" snapActive="1"
                 snapShown="1" overlayOpacity="0.330" fixedSize="1" initialWidth="800"
                 initialHeight="600">
  <BACKGROUND backgroundColour="ff2e2e2e"/>
  <GROUPCOMPONENT name="players" id="79f879264b5ffa27" memberName="playerListGroup"
                  virtualName="" explicitFocusOrder="0" pos="60% 2% 38% 96%" outlinecol="66dfdfdf"
                  textcol="ffbebcbc" title="Players"/>
  <GENERICCOMPONENT name="Player Name List" id="8fc82d1c512e5862" memberName="playerNameList"
                    virtualName="" explicitFocusOrder="0" pos="4.934% 6% 90.132% 89%"
                    posRelativeX="79f879264b5ffa27" posRelativeW="79f879264b5ffa27"
                    class="ListBox" params=""/>
  <GENERICCOMPONENT name="Maze Component" id="b10a398557cac1f6" memberName="mazeComponent"
                    virtualName="" explicitFocusOrder="0" pos="1.5% 4% 460 460" class="Component"
                    params=""/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
