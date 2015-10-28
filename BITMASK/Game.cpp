#include "Game.h"
#include "Managers/SystemManager.h"
#include "Systems/InputSystem.h"
#include "Systems/PhysicsSystem.h"
#include "Systems/BallMovementSystem.h"
#include "Systems/DebugDrawSystem.h"
#include "Resources/ResourceManager.h"

bit::Game::Game()
	: mWindow(sf::VideoMode(1280, 720), "SFML Application")
{
	// Limit the framerate of the window to 200fps
	mWindow.setFramerateLimit(200);

	// Make a test game object
	GameObject* testCircle = new GameObject();

	// Make a few test systems
	sysm = new SystemManager();
	PhysicsSystem* physSystem = sysm->addSystem<PhysicsSystem>();
	BallMovementSystem* ballMovement = sysm->addSystem<BallMovementSystem>();
	InputSystem* inputSys = sysm->addSystem<InputSystem>();

	// Make a test render system (and a debug draw system)
	renderSys = new RenderSystem(sysm, &mWindow);
	debugSys = new DebugDrawSystem(sysm, physSystem, &mWindow, true);

	// Input needs to listen to window events
	sysm->subscribeToEvents(inputSys);

	// Make a really simple test shape
	sf::Shape* testShape = new sf::CircleShape(40.f);
	testShape->setFillColor(sf::Color::Cyan);

	// Add some components to the circle
	testCircle->addComponent<ShapeComponent>(testShape);
	testCircle->addComponent<RenderableComponent>();
	testCircle->addComponent<TransformComponent>(100.f, 100.f, 0.f);
	testCircle->addComponent<PhysicsBodyComponent>(b2BodyType::b2_dynamicBody, 100.f, 100.f, 0.f);

	// Add the test object to the systems that may care about it
	renderSys->addObj(testCircle);
	physSystem->addObj(testCircle);
	ballMovement->addObj(testCircle);
}

void bit::Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	// Initial tick
	update(timeSinceLastUpdate);

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
	// Clear the window
	mWindow.clear();
	
	// Update the debug draw as well
	renderSys->update(sf::Time().Zero);

	// Update the render system
	debugSys->update(sf::Time().Zero);

	mWindow.display();
}