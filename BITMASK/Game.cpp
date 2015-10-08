#include "Game.h"

Game::Game()
	: mWindow(sf::VideoMode(640, 480), "SFML Application"),
	manager()
{

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

		switch (wEvent.type)
		{
			case sf::Event::Closed:
				mWindow.close();
				break;
			case sf::Event::KeyPressed:
				handlePlayerInput(wEvent.key.code, true);
				break;
			case sf::Event::KeyReleased:
				handlePlayerInput(wEvent.key.code, false);
				break;
		}

		if (wEvent.type == sf::Event::Closed)
		{
			mWindow.close();
		}
	}
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{

}

void Game::update(sf::Time deltaTime)
{

}

void Game::render()
{
	mWindow.clear();
	mWindow.display();
}