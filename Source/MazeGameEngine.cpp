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

void MazeGameEngine::insertIncidentEdges (Array <Edge>& edges, const Cell& cell,
                                          int numberOfCellsX, int numberOfCellsY) noexcept
{
    static const int numAdjacentCells = 4;
    
    Cell adjacentCellsTemp [] =
    {
        cell.translated (-1, 0),
        cell.translated (0, -1),
        cell.translated (1, 0),
        cell.translated (0, 1)
    };
    
    Array <Cell> adjacentCells (adjacentCellsTemp, numAdjacentCells);
    
    for (auto& adjCell : adjacentCells)
    {
        if (adjCell.x >= 0 &&
            adjCell.y >= 0 &&
            adjCell.x < numberOfCellsX &&
            adjCell.y < numberOfCellsY)
        {
            edges.addIfNotAlreadyThere (Edge (cell, adjCell));
        }
    }
}

void MazeGameEngine::generateMaze (int numberOfCellsX, int numberOfCellsY) const noexcept
{
    Array<Edge> edges;
    Array <Cell> cells;
    
    for (int i = 0; i < numberOfCellsX; ++i)
    {
        for (int j = 0; j < numberOfCellsY; ++j)
        {
            // calculate all angles incident on each cell > 0
            // and add them to the edges set
            Cell cell (i, j);
            cells.add (cell);
            
            insertIncidentEdges (edges, cell, numberOfCellsX, numberOfCellsY);
        }
    }
    
    // for (auto& edge : edges)
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
