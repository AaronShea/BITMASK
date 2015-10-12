#include "Game.h"
#include "Systems/InputSystem.h"

Game::Game()
	: mWindow(sf::VideoMode(640, 480), "SFML Application")
{
	sysm = new SystemManager();
	sysm->addSystem<InputSystem>();
}

void Game::run()
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

void Game::processEvents()
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

void Game::update(sf::Time deltaTime)
{
	sysm->update(deltaTime);
}

void Game::render()
{
	mWindow.clear();
	mWindow.display();
}