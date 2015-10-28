#pragma once
#include "SFML/Graphics.hpp"

#include "Resources/ResourceManager.h"
#include "GameObjects/GameObject.h"

#include "Systems/RenderSystem.h"

#include "Components/TransformComponent.h"
#include "Components/ShapeComponent.h"
#include "Components/PhysicsBodyComponent.h"

namespace bit
{
	class SystemManager;
	class DebugDrawSystem;

	class Game
	{
		public:
			Game();
			void run();

		private:
			void processEvents();
			void render();
			void update(sf::Time deltaTime);

			// Fixed timestep is set here
			sf::Time timePerFrame = sf::seconds(1.f / 199.f);

			sf::RenderWindow mWindow;

			SystemManager* sysm;
			RenderSystem* renderSys;
			DebugDrawSystem* debugSys;
	};
}
