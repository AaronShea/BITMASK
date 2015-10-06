#include "SystemManager.h"

SystemManager::SystemManager() {}

SystemManager::~SystemManager() {}

void SystemManager::addSystem(System* s)
{
	systems.push_back(s);
}

void SystemManager::removeSystem(System* s)
{
	systems.erase(std::remove(systems.begin(), systems.end(), s), systems.end());
}

void SystemManager::updateAllSystems(sf::Time deltaTime)
{
	// Run the update method on all systems
	for (auto s : systems)
	{
		s->update(deltaTime);
	}
}