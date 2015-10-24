#include "Game.h"
#include "Managers/SystemManager.h"
#include "Systems/InputSystem.h"
#include "Systems/PhysicsSystem.h"
#include "Resources/ResourceManager.h"

bit::Game::Game()
	: mWindow(sf::VideoMode(1280, 720), "SFML Application")
{
	// Limit the framerate of the window to 200
	mWindow.setFramerateLimit(200);

	sysm = new SystemManager();

	GameObject* testCircle = new GameObject();

	// Add input system
	sysm->subscribeToEvents(sysm->addSystem<InputSystem>());
	System* physSystem = sysm->addSystem<PhysicsSystem>();

	// Make a really simple test shape
	sf::Shape* testShape = new sf::CircleShape(40.f);
	testShape->setFillColor(sf::Color::Cyan);
	testShape->setPosition(100.f, 100.f);

	// Make a test render system
	renderSys = new RenderSystem(sysm, &mWindow);

	// Add some components to the circle
	testCircle->addComponent<ShapeComponent>(testShape);
	testCircle->addComponent<TransformComponent>(0.f, 0.f, 0.f);
	testCircle->addComponent<PhysicsBodyComponent>(b2BodyType::b2_dynamicBody);

	// Add the test object to the systems that may care about it
	renderSys->addObj(testCircle);
	physSystem->addObj(testCircle);

}

void bit::Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	while (mWindow.isOpen())
	{
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