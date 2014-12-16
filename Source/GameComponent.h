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

#ifndef __JUCE_HEADER_71E66A8960717C24__
#define __JUCE_HEADER_71E66A8960717C24__

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"

#include "Player.h"
#include "PlayerConnectionServer.h"
#include "GameEngine.h"
#include "MazeComponent.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class GameComponent  : public Component,
                       public GameListener,
                       public ListBoxModel
{
public:
    //==============================================================================
    GameComponent ();
    ~GameComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    void playerCreated (const Player& newPlayer);
    //[/UserMethods]

    void paint (Graphics& g);
    void resized();

private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    void paintListBoxItem (int rowNumber,
                           Graphics& g,
                           int width, int height,
                           bool rowIsSelected);
    
    int getNumRows();
    
    PlayerConnectionServer connectionServer;
    GameEngine gameEngine;
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<GroupComponent> playerListGroup;
    ScopedPointer<ListBox> playerNameList;
    ScopedPointer<MazeComponent> mazeComponent;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (GameComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

#endif   // __JUCE_HEADER_71E66A8960717C24__
