/*
  ==============================================================================

    PlayerConnectionServer.h
    Created: 12 Dec 2014 10:58:59pm
    Author:  Luke Snape

  ==============================================================================
*/

#ifndef PLAYERCONNECTIONSERVER_H_INCLUDED
#define PLAYERCONNECTIONSERVER_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "PlayerConnectionListener.h"

class PlayerConnectionServer : public InterprocessConnectionServer
{
public:
    PlayerConnectionServer() noexcept;
    ~PlayerConnectionServer();
    
    void setListener (PlayerConnectionListener* listener);
    
private:
    InterprocessConnection* createConnectionObject();
    
    static const int portNumber = 8080;
    PlayerConnectionListener* listener;
};

#endif  // PLAYERCONNECTIONSERVER_H_INCLUDED
