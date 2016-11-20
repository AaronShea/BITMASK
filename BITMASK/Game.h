#pragma once
#include "SFML/Graphics.hpp"

namespace chaiscript
{
	class ChaiScript;
}

namespace bit
{
	class SystemManager;
	class DebugDrawSystem;
	class RenderSystem;
	class PhysicsSystem;
	class GameObjectManager;

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
			PhysicsSystem* physSys;
			GameObjectManager* objManager;
			
			chaiscript::ChaiScript* chai;
	};
}
