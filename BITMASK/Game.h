#pragma once
#include "SFML/Graphics.hpp"

#include "Resources/ResourceManager.h"
#include "GameObjects/GameObject.h"
#include "Components/TransformComponent.h"

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

		void handlePlayerInput(sf::Keyboard::Key key,bool isPressed);

		sf::RenderWindow mWindow;
};