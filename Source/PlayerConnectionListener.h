/*
  ==============================================================================

    PlayerConnectionListener.h
    Created: 13 Dec 2014 1:11:29pm
    Author:  Luke Snape

  ==============================================================================
*/

#ifndef PLAYERCONNECTIONLISTENER_H_INCLUDED
#define PLAYERCONNECTIONLISTENER_H_INCLUDED

class PlayerConnectionListener
{
public:
    virtual ~PlayerConnectionListener()
    {
    }
    
    virtual void createPlayer(const String& playerName) = 0;
    virtual void removePlayer(const String& playerName) = 0;
};

#endif  // PLAYERLISTENER_H_INCLUDED
