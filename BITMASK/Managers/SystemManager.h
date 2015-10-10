#pragma once
#include "Systems/System.h"

class SystemManager
{
	private:
		std::vector<System*> systems;

	public:
		SystemManager();
		~SystemManager();

		void addSystem(System* sys);
		void removeSystem(System* sys);

		void update(sf::Time deltaTime);
};