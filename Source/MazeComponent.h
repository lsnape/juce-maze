/*
  ==============================================================================

    MazeComponent.h
    Created: 16 Dec 2014 10:03:25pm
    Author:  Luke Snape

  ==============================================================================
*/

#ifndef MAZECOMPONENT_H_INCLUDED
#define MAZECOMPONENT_H_INCLUDED

#include "JuceHeader.h"
#include "GameEngine.h"

//==============================================================================
/*
*/
class MazeComponent : public Component
{
public:
    MazeComponent (const GameEngine& gameModel);
    ~MazeComponent();

    void paint (Graphics&);
    void resized();
    
    void paintEdge (const Graphics& g, const Edge& edgeToPaint);

private:
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (MazeComponent)
    
    const GameEngine& gameModel;
    
    static const int cellDimensions = 40,
                     edgeDimensions = 2;
};


#endif  // MAZECOMPONENT_H_INCLUDED
