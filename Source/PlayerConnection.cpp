/*
  ==============================================================================

    PlayerConnection.cpp
    Created: 12 Dec 2014 11:15:52pm
    Author:  Luke Snape

  ==============================================================================
*/

#include "PlayerConnection.h"

PlayerConnection::PlayerConnection()
{
    
}

PlayerConnection::~PlayerConnection()
{
    
}

void PlayerConnection::connectionMade()
{
    std::cout << "Connection Made!\n";
}

void PlayerConnection::connectionLost()
{
    std::cout << "Connection Lost!\n";
}

void PlayerConnection::messageReceived (const MemoryBlock& message)
{
    std::cout << "Message Received!\n";
}