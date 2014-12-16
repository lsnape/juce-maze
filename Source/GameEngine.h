/*
  ==============================================================================

    GameEngine.h
    Created: 13 Dec 2014 12:30:54pm
    Author:  Luke Snape

  ==============================================================================
*/

#ifndef GAMEENGINE_H_INCLUDED
#define GAMEENGINE_H_INCLUDED

#include "JuceHeader.h"
#include "Player.h"
#include "PlayerConnectionListener.h"

class GameListener
{
public:
    virtual ~GameListener()
    {
    }
    
    virtual void playerCreated (const Player& newPlayer) = 0;
};

typedef Point <int> Cell;

struct Edge
{
    Edge (Cell cell1_, Cell cell2_) : cell1(cell1_), cell2(cell2_)
    {
    }
    
    bool operator== (const Edge& other) const noexcept
    {
        return (cell1 == other.cell1 &&
                cell2 == other.cell2);
    }
    
    Cell cell1;
    Cell cell2;
};

class GameEngine : public PlayerConnectionListener
{
public:
    GameEngine();
    virtual ~GameEngine() {}

    void createPlayer (const String& playerName) noexcept;
    void removePlayer (const String& playerName) noexcept;
    
    const Player& getPlayerAtIndex (int index) const noexcept;
    int getNumPlayers() const noexcept;
    
    void generateMaze (int numberOfCellsX, int numberOfCellsY);
    const Array <Edge>& getEdges() const noexcept;
    
    void setListener (GameListener* listener);
    
    int getMazeWidth() const noexcept;
    int getMazeHeight() const noexcept;
    
private:
    int indexOfArrayContainingCell (const Array <Array <Cell> >& cellSets, const Cell& cell) const noexcept;
    
    int mazeWidth,
        mazeHeight;
    
    Array <Edge> edges;
    Array <Player> players;
    
    GameListener* listener;
};

#endif  // GAMEENGINE_H_INCLUDED
