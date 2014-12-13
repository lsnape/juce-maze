/*
  ==============================================================================

    PlayerConnectionServer.cpp
    Created: 12 Dec 2014 10:58:59pm
    Author:  Luke Snape

  ==============================================================================
*/

#include "PlayerConnectionServer.h"
#include "PlayerConnection.h"

PlayerConnectionServer::PlayerConnectionServer() noexcept : listener (nullptr)
{
    std::cout << "Starting server on port:" << portNumber << '\n';
    beginWaitingForSocket (portNumber);
}

PlayerConnectionServer::~PlayerConnectionServer()
{
    std::cout << "Stopping server on port:" << portNumber << '\n';
}

InterprocessConnection* PlayerConnectionServer::createConnectionObject()
{
    return new PlayerConnection (listener);
}

void PlayerConnectionServer::setListener (PlayerConnectionListener* listener_)
{
    listener = listener_;
}