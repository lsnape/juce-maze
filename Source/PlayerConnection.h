/*
  ==============================================================================

    PlayerConnection.h
    Created: 12 Dec 2014 11:15:52pm
    Author:  Luke Snape

  ==============================================================================
*/

#ifndef PLAYERCONNECTION_H_INCLUDED
#define PLAYERCONNECTION_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
#include "PlayerConnectionListener.h"

class PlayerConnection : public InterprocessConnection
{
public:
    PlayerConnection (PlayerConnectionListener* listener);
    ~PlayerConnection();

    void sendStringMessage (const String& message);
    
private:
    void connectionMade();
    void connectionLost();
    void messageReceived (const MemoryBlock& message);

    PlayerConnectionListener* listener;
};

#endif  // PLAYERCONNECTION_H_INCLUDED
