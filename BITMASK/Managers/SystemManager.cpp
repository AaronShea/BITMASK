#include "Systems/System.h"
#include "SystemManager.h"

bit::SystemManager::SystemManager()
{

}

bit::SystemManager::~SystemManager()
{
	
}

void bit::SystemManager::update(sf::Time deltaTime)
{
	for (auto& sys : systems)
	{
		sys->update(deltaTime);
	}
}

void bit::SystemManager::processEvent(sf::Event eEvent)
{
	for (auto& sys : eventListeners)
	{
		sys->processEvent(eEvent);
	}
}

void bit::SystemManager::subscribeToEvents(System* sys)
{
	eventListeners.push_back(sys);
}

void bit::SystemManager::unsubscribeToEvents(System* sys)
{
	// Remove a system from listening to events
	auto t = find_if(eventListeners.begin(), eventListeners.end(), [sys](System*& element){ return element == sys; });

	// If we actually found a result
	if (!(t == eventListeners.end()))
	{
		// Tell the System it will be removed
		sys->removed();
		eventListeners.erase(t);
	}
}