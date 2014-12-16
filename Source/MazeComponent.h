/*
  ==============================================================================

    MazeComponent.h
    Created: 16 Dec 2014 10:03:25pm
    Author:  Luke Snape

  ==============================================================================
*/

#ifndef MAZECOMPONENT_H_INCLUDED
#define MAZECOMPONENT_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class MazeComponent : public Component
{
public:
    MazeComponent();
    ~MazeComponent();

    void paint (Graphics&);
    void resized();

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MazeComponent)
};


#endif  // MAZECOMPONENT_H_INCLUDED
