/*
  ==============================================================================

    GameEngine.cpp
    Created: 13 Dec 2014 12:30:54pm
    Author:  Luke Snape

  ==============================================================================
*/

#include "GameEngine.h"

GameEngine::GameEngine() : mazeWidth(10), mazeHeight(10), listener (nullptr)
{
    generateMaze (mazeWidth, mazeHeight);
}

void GameEngine::createPlayer (const String& playerName) noexcept
{
    players.add (Player (playerName));
    
    if (listener != nullptr)
        listener->playerCreated (playerName);
}

void GameEngine::removePlayer (const String& playerName) noexcept
{
    // TODO - search for and remove player
}


int GameEngine::indexOfArrayContainingCell (const Array <Array <Cell> >& cellArrays, const Cell& cell) const noexcept
{
    int cellArrayIndex = -1;
    
    for (int i = 0; i < cellArrays.size(); ++i)
    {
        if (cellArrays[i].contains (cell))
        {
            cellArrayIndex = i;
            break;
        }
    }
    
    return cellArrayIndex;
}

int GameEngine::getMazeWidth() const noexcept
{
    return mazeWidth;
}

int GameEngine::getMazeHeight() const noexcept
{
    return mazeHeight;
}

void GameEngine::generateMaze (int numberOfCellsX, int numberOfCellsY)
{
    mazeWidth = numberOfCellsX;
    mazeHeight = numberOfCellsY;
    
    Array <Array <Cell> > cellArrays;
    
    for (int i = 0; i < numberOfCellsX; ++i)
    {
        for (int j = 0; j < numberOfCellsY; ++j)
        {
            Cell cell (i, j);
            Array <Cell> cellArray;
            cellArray.add (cell);
            cellArrays.add (cellArray);
            
            if (i < (numberOfCellsX - 1))
                edges.add (Edge (cell, cell.translated (1, 0)));
                
            if (j < (numberOfCellsY - 1))
                edges.add (Edge (cell, cell.translated (0, 1)));
        }
    }
    
    // Kruskal's randomised MST maze generation algorithm
    // This is a slow, naieve implementation: union find data structure is needed here really
    
    std::random_shuffle (edges.begin(), edges.end());
    
    for (auto& edge : edges)
    {
        int cell1ArrayIndex = indexOfArrayContainingCell (cellArrays, edge.cell1),
            cell2ArrayIndex = indexOfArrayContainingCell (cellArrays, edge.cell2);
        
        if (cell1ArrayIndex != cell2ArrayIndex)
        {
            Array <Cell>& cell1Array = cellArrays.getReference (cell1ArrayIndex);
            const Array <Cell>& cell2Array = cellArrays[cell2ArrayIndex];
            
            cell1Array.addArray (cell2Array);
            cellArrays.remove (cell2ArrayIndex);
        }
    }
}

const Player& GameEngine::getPlayerAtIndex (int index) const noexcept
{
    return players.getReference (index);
}

int GameEngine::getNumPlayers() const noexcept
{
    return players.size();
}

const Array <Edge>& GameEngine::getEdges() const noexcept
{
    return edges;
}

void GameEngine::setListener (GameListener* listener_)
{
    listener = listener_;
}
