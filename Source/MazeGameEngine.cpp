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
    
}

void MazeGameEngine::createPlayer (const String& playerName) noexcept
{
    players.add (Player (playerName));
    
    if (listener != nullptr)
    {
        listener->playerCreated (playerName);
    }
}

void MazeGameEngine::removePlayer (const String& playerName) noexcept
{
    // TODO - search for and remove player
}

const Player& MazeGameEngine::getPlayerAtIndex (int index) const noexcept
{
    return players.getReference(index);
}

int MazeGameEngine::getNumPlayers() const noexcept
{
    return players.size();
}

void MazeGameEngine::setListener (MazeGameListener* listener_)
{
    listener = listener_;
}
