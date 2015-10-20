#include "Game.h"
#include "Managers/SystemManager.h"
#include "Systems/InputSystem.h"
#include "Systems/RenderSystem.h"
#include "Resources/ResourceManager.h"
#include "physfs.h"

bit::Game::Game()
	: mWindow(sf::VideoMode(1280, 720), "SFML Application")
{
	// Limit the framerate of the window to 200
	mWindow.setFramerateLimit(200);

	sysm = new SystemManager();

	// Add input system
	sysm->subscribeToEvents(sysm->addSystem<InputSystem>());
}

void bit::Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (mWindow.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents();
			update(timePerFrame);
		}
		render();
	}
}

void bit::Game::processEvents()
{
	sf::Event wEvent;
	while (mWindow.pollEvent(wEvent))
	{
		sysm->processEvent(wEvent);

		if (wEvent.type == sf::Event::Closed)
		{
			mWindow.close();
		}
	}
}

void bit::Game::update(sf::Time deltaTime)
{
	sysm->update(deltaTime);
}

void bit::Game::render()
{
	mWindow.display();
}