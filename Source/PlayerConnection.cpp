/*
  ==============================================================================

    PlayerConnection.cpp
    Created: 12 Dec 2014 11:15:52pm
    Author:  Luke Snape

  ==============================================================================
*/

#include "PlayerConnection.h"

PlayerConnection::PlayerConnection (PlayerConnectionListener* listener_) : listener (listener_)
{
}

PlayerConnection::~PlayerConnection()
{
    
}

void PlayerConnection::connectionMade()
{
    std::cout << "Connection Made!\n";
    sendStringMessage ("Welcome! Please enter your name:\n");
}

void PlayerConnection::connectionLost()
{
    std::cout << "Connection Lost!\n";
}

void PlayerConnection::messageReceived (const MemoryBlock& message)
{
    std::cout << "Message Received!\n";
    
    if (listener != nullptr)
    {
        listener->createPlayer (message.toString());
    }
}

void PlayerConnection::sendStringMessage (const String& message)
{
    MemoryBlock memoryBlock (message.toRawUTF8(), message.toUTF8().sizeInBytes());
    sendMessage (memoryBlock);
}
