/*
  ==============================================================================

    MazeGameEngine.h
    Created: 13 Dec 2014 12:30:54pm
    Author:  Luke Snape

  ==============================================================================
*/

#ifndef MAZEGAMEENGINE_H_INCLUDED
#define MAZEGAMEENGINE_H_INCLUDED

#include "JuceHeader.h"
#include "Player.h"
#include "PlayerConnectionListener.h"

class MazeGameListener
{
public:
    virtual ~MazeGameListener()
    {
    }
    
    virtual void playerCreated (const Player& newPlayer) = 0;
};

class MazeGameEngine : public PlayerConnectionListener
{
public:
    MazeGameEngine();
    virtual ~MazeGameEngine() {}

    void createPlayer (const String& playerName) noexcept;
    void removePlayer (const String& playerName) noexcept;
    
    const Player& getPlayerAtIndex (int index) const noexcept;
    int getNumPlayers() const noexcept;
    
    void generateMaze (int numberOfCellsX, int numberOfCellsY) const noexcept;
    
    void setListener (MazeGameListener* listener);
    
private:
    Array <Player> players;
    MazeGameListener* listener;

    typedef Point <int> Cell;
    
    struct Edge
    {
        Edge (Cell cell1_, Cell cell2_) : cell1(cell1_), cell2(cell2_)
        {
        }
        
        Cell cell1;
        Cell cell2;
    };
    
    static void insertIncidentEdges (Array <Edge>& edges, const Cell& cell,
                                     int numberOfCellsX, int numberOfCellsY) noexcept;
};

#endif  // MAZEGAMEENGINE_H_INCLUDED
