#include "Game.h"

Game::Game()
	: mWindow(sf::VideoMode(640, 480), "SFML Application")
{
	auto thing = new GameObject();
	thing->addComponent(new TransformComponent(0.f, 0.f, 0.f, thing));
	thing->removeComponent(0);
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
	if (key == sf::Keyboard::W)
	{
		pUp = isPressed;
	}

	if (key == sf::Keyboard::S)
	{
		pDown = isPressed;
	}
	
	if (key == sf::Keyboard::A)
	{
		pLeft = isPressed;
	}
	
	if (key == sf::Keyboard::D)
	{
		pRight = isPressed;
	}
}

void Game::update(sf::Time deltaTime)
{
	sf::Vector2f movement(0.f, 0.f);
	if (pUp)
	{
		movement.y -= playerSpeed;
	}

	if (pDown)
	{
		movement.y += playerSpeed;
	}

	if (pLeft)
	{
		movement.x -= playerSpeed;
	}

	if (pRight)
	{
		movement.x += playerSpeed;
	}

	// mPlayer.move(movement * deltaTime.asSeconds());
}

void Game::render()
{
	mWindow.clear();
	mWindow.display();
}