#include "Game.h"
#include "Managers/SystemManager.h"
#include "Systems/InputSystem.h"
#include "Resources/ResourceManager.h"

bit::Game::Game()
	: mWindow(sf::VideoMode(1280, 720), "SFML Application")
{
	// Limit the framerate of the window to 200
	mWindow.setFramerateLimit(200);

	sysm = new SystemManager();

	GameObject* mPlayer = new GameObject();

	// Add input system
	sysm->subscribeToEvents(sysm->addSystem<InputSystem>());

	sf::Shape* testShape = new sf::CircleShape(40.f);
	testShape->setFillColor(sf::Color::Cyan);
	testShape->setPosition(100.f, 100.f);

	renderSys = new RenderSystem(sysm, &mWindow);
	mPlayer->addComponent<ShapeComponent>(testShape);
	mPlayer->addComponent<TransformComponent>(0.f, 0.f, 0.f);
	mPlayer->addComponent<PhysicsBodyComponent>(b2BodyType::b2_dynamicBody);

	renderSys->addObj(mPlayer);

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
	// Update the render system
	renderSys->update(sf::Time().Zero);

	mWindow.display();
}