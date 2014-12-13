/*
  ==============================================================================

    Player.h
    Created: 13 Dec 2014 2:29:33pm
    Author:  Luke Snape

  ==============================================================================
*/

#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include "JuceHeader.h"

struct Player
{
    Player()
    {
    }
    
    Player(const String& playerName) : name(playerName)
    {
    }
    
    Player& operator= (const Player& other) noexcept
    {
        this->name = other.name;
        return *this;
    }
    
    String name;
    Point<int> position;
};

#endif  // PLAYER_H_INCLUDED
