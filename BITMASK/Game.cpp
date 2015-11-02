#include "Game.h"
#include "Managers/SystemManager.h"
#include "Systems/RenderSystem.h"
#include "Systems/PhysicsSystem.h"
#include "Systems/DebugDrawSystem.h"
#include "Systems/InputSystem.h"
#include "Managers/GameObjectManager.h"
#include "chaiscript/chaiscript.hpp"
#include "chaiscript/chaiscript_stdlib.hpp"



bit::Game::Game()
	: mWindow(sf::VideoMode(1280, 720), "BITMASK")
{
	// Limit the framerate of the window to 200fps
	mWindow.setFramerateLimit(200);

	// Managers
	sysm = new SystemManager();
	objManager = new GameObjectManager(sysm);

	// Add physics and input system
	sysm->subscribeToEvents(sysm->addSystem<InputSystem>());
	physSys = sysm->addSystem<PhysicsSystem>();

	// Make a test render system (and a debug draw system)
	renderSys = new RenderSystem(sysm, &mWindow);
	debugSys = new DebugDrawSystem(sysm, physSys, &mWindow, true);

	chai = new chaiscript::ChaiScript(chaiscript::Std_Lib::library());
}

void bit::Game::run()
{
	sf::Clock clock;
	auto timeSinceLastUpdate = sf::Time::Zero;

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
	//debugSys->update(sf::Time().Zero);

	mWindow.display();
}