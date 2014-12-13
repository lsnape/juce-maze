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
    
    void setListener (MazeGameListener* listener);
    
private:
    Array<Player> players;
    MazeGameListener* listener;
};

#endif  // MAZEGAMEENGINE_H_INCLUDED
