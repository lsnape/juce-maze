/*
  ==============================================================================

    This file was auto-generated!

  ==============================================================================
*/

#include "MainComponent.h"

//==============================================================================
MainContentComponent::MainContentComponent()
{    
    addAndMakeVisible (&gameComponent);
    setSize (800, 600);
}

MainContentComponent::~MainContentComponent()
{
}

void MainContentComponent::paint (Graphics& g)
{
    g.fillAll (Colour (0xff001F36));

    g.setFont (Font (16.0f));
    g.setColour (Colours::white);
}

void MainContentComponent::resized()
{
    // This is called when the MainContentComponent is resized.
    // If you add any child components, this is where you should
    // update their positions.
}
