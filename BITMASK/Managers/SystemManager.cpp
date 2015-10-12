#include "Systems/System.h"
#include "SystemManager.h"

SystemManager::SystemManager()
{

}

SystemManager::~SystemManager()
{
	
}

void SystemManager::update(sf::Time deltaTime)
{
	for (auto& sys : systems)
	{
		sys->update(deltaTime);
	}
}

void SystemManager::processEvent(sf::Event eEvent)
{
	for (auto& sys : eventListeners)
	{
		sys->processEvent(eEvent);
	}
}

void SystemManager::subscribeToEvents(System* sys)
{
	eventListeners.push_back(sys);
}

void SystemManager::unsubscribeToEvents(System* sys)
{
	// Remove a system from listening to events
	auto t = find_if(eventListeners.begin(), eventListeners.end(), [sys](System*& element){ return element == sys; });

	// If we actually found a result
	if (!(t == eventListeners.end()))
	{
		eventListeners.erase(t);
	}
}