#pragma once
#include <vector>
#include "Systems/System.h"

class SystemManager
{
	private:
		std::vector<System*> systems;

	public:
		SystemManager();
		~SystemManager();

		void addSystem(System* s);
		void removeSystem(System* s);
		void updateAllSystems(sf::Time deltaTime);
};