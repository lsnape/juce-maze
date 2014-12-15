/*
  ==============================================================================

    MazeGameEngine.cpp
    Created: 13 Dec 2014 12:30:54pm
    Author:  Luke Snape

  ==============================================================================
*/

#include "MazeGameEngine.h"

MazeGameEngine::MazeGameEngine() : listener (nullptr)
{
    generateMaze (10, 10);
}

void MazeGameEngine::createPlayer (const String& playerName) noexcept
{
    players.add (Player (playerName));
    
    if (listener != nullptr)
        listener->playerCreated (playerName);
}

void MazeGameEngine::removePlayer (const String& playerName) noexcept
{
    // TODO - search for and remove player
}


int MazeGameEngine::indexOfArrayContainingCell (const Array <Array <Cell> >& cellSets, const Cell& cell) const noexcept
{
    int cellSetIndex = -1;
    
    for (int i = 0; i < cellSets.size(); ++i)
    {
        if (cellSets[i].contains (cell))
        {
            cellSetIndex = i;
            break;
        }
    }
    
    return cellSetIndex;
}

void MazeGameEngine::generateMaze (int numberOfCellsX, int numberOfCellsY) const
{
    Array <Edge> edges;
    Array <Array <Cell> > cellSets;
    
    for (int i = 0; i < numberOfCellsX; ++i)
    {
        for (int j = 0; j < numberOfCellsY; ++j)
        {
            Cell cell (i, j);
            Array <Cell> cellSet;
            cellSet.add (cell);
            cellSets.add (cellSet);
            
            if (i < (numberOfCellsX - 1))
                edges.add (Edge (cell, cell.translated (1, 0)));
                
            if (j < (numberOfCellsY - 1))
                edges.add (Edge (cell, cell.translated (0, 1)));
        }
    }
    
    std::random_shuffle (edges.begin(), edges.end());
    {
        // if cell 1 and cell 2 belong to the same set
    }
}

const Player& MazeGameEngine::getPlayerAtIndex (int index) const noexcept
{
    return players.getReference (index);
}

int MazeGameEngine::getNumPlayers() const noexcept
{
    return players.size();
}

void MazeGameEngine::setListener (MazeGameListener* listener_)
{
    listener = listener_;
}
