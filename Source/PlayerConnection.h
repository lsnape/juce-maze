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

class PlayerConnection : public InterprocessConnection
{
public:
    PlayerConnection();
    ~PlayerConnection();
    
private:
    void connectionMade();
    void connectionLost();
    
    void messageReceived (const MemoryBlock& message);
};

#endif  // PLAYERCONNECTION_H_INCLUDED
