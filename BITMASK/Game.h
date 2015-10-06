#pragma once
#define SFML_STATIC
#include "SFML/Graphics.hpp"

#include "Resources/ResourceManager.h"
#include "GameObjects/GameObject.h"
#include "Components/GraphicComponent.h"
#include "Components/TransformComponent.h"

class Game {

	public:
		Game();
		void run();

	private:
		void processEvents();
		void render();
		void update(sf::Time deltaTime);

		// Fixed max framerate is here
		sf::Time timePerFrame = sf::seconds(1.f / 120.f);

		void handlePlayerInput(sf::Keyboard::Key key,bool isPressed);

		sf::RenderWindow mWindow;

		GameObject* mPlayer;

		float playerSpeed = 100.f;
		
		bool pUp = false;
		bool pDown = false;
		bool pLeft = false;
		bool pRight = false;

};