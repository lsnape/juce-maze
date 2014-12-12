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

class PlayerConnectionServer : public InterprocessConnectionServer
{
public:
    PlayerConnectionServer() noexcept;
    ~PlayerConnectionServer();
    
private:
    InterprocessConnection* createConnectionObject();
    
    static const int portNumber = 8080;
};

#endif  // PLAYERCONNECTIONSERVER_H_INCLUDED
