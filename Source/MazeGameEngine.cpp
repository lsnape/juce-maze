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

void MazeGameEngine::createPlayer (const String& playerName)
{
    players[playerName] = Player (playerName);
    
    if (listener != nullptr)
    {
        listener->playerCreated (playerName, Point<int> (0, 0));
    }
}

void MazeGameEngine::removePlayer (const String& playerName)
{
    players.remove(playerName);
}

void MazeGameEngine::setListener (MazeGameListener* listener_)
{
    listener = listener_;
}