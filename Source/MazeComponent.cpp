/*
  ==============================================================================

    MazeComponent.cpp
    Created: 16 Dec 2014 10:03:25pm
    Author:  Luke Snape

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "MazeComponent.h"

//==============================================================================
MazeComponent::MazeComponent (const GameEngine& gameModel_) : gameModel (gameModel_)
{
}

MazeComponent::~MazeComponent()
{
}

void MazeComponent::paintEdge (const Graphics& g, const Edge& edgeToPaint)
{
}

void MazeComponent::paint (Graphics& g)
{
    g.fillAll (Colours::white);   // clear the background
    
    g.setColour (Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    g.setColour (Colours::lightblue);
    
    int mazeWidth = gameModel.getMazeWidth(),
        mazeHeight = gameModel.getMazeHeight();
    
    // for now...
    assert (mazeWidth == mazeHeight);
        
    for (auto& edge : gameModel.getEdges())
    {
        int xOffset = cellDimensions + (edge.cell1.x * (cellDimensions + 1)),
            yOffset = cellDimensions + (edge.cell1.y * (cellDimensions + 1));
        
        g.fillRect (Rectangle <int> (xOffset,
                                     yOffset,
                                     cellDimensions + ((cellDimensions + 1) * edge.cell2.x) == xOffset ? edgeDimensions : cellDimensions + (edgeDimensions + 1),
                                     cellDimensions + ((cellDimensions + 1) * edge.cell2.y) == yOffset ? edgeDimensions : cellDimensions + (edgeDimensions + 1)));
    }
}

void MazeComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

}
