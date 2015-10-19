#pragma once
#include "SFML/Graphics.hpp"

#include "Resources/ResourceManager.h"
#include "GameObjects/GameObject.h"
#include "Components/TransformComponent.h"
#include "Components/ShapeComponent.h"

class SystemManager;

class Game 
{
	public:
		Game();
		void run();

	private:
		void processEvents();
		void render();
		void update(sf::Time deltaTime);

		// Fixed max framerate is set here
		sf::Time timePerFrame = sf::seconds(1.f / 120.f);

		sf::RenderWindow mWindow;

		SystemManager* sysm;
};