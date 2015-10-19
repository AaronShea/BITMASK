#include "Game.h"
#include "Managers/SystemManager.h"
#include "Systems/InputSystem.h"
#include "Systems/RenderSystem.h"
#include "Resources/ResourceManager.h"
#include "physfs.h"

Game::Game()
	: mWindow(sf::VideoMode(1280, 720), "SFML Application")
{
	// Limit the framerate of the window to 200
	mWindow.setFramerateLimit(200);

	GameObject* mPlayer = new GameObject();

	sysm = new SystemManager();

	// Add input system
	sysm->subscribeToEvents(sysm->addSystem<InputSystem>());

	sf::Shape* testShape = new sf::CircleShape(40.f);
	testShape->setFillColor(sf::Color::Cyan);
	testShape->setPosition(100.f, 100.f);

	// Add render system
	auto rendersystem = sysm->addSystem<RenderSystem>(&mWindow);
	mPlayer->addComponent<ShapeComponent>(testShape);
	mPlayer->addComponent<TransformComponent>(0.f, 0.f, 0.f);

	rendersystem->addObj(mPlayer);
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
	mWindow.display();
}