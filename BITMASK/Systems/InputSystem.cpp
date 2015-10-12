#include "Managers/SystemManager.h"
#include "InputSystem.h"
#include <iostream>

InputSystem::InputSystem(SystemManager* manager)
	: System(manager)
{
	// Constructor
}

InputSystem::~InputSystem()
{
	// Deconstructor
}

void InputSystem::update(sf::Time deltaTime)
{
	// Called once per tick
}

void InputSystem::processEvent(sf::Event& eEvent)
{
	switch (eEvent.type)
	{
		case sf::Event::KeyPressed:
			std::cout << "KeyPressed: " << eEvent.key.code << std::endl;
			break;
		default:
			break;
	}
}

void InputSystem::added()
{
	// This system was added to the update loop
}

void InputSystem::removed()
{
	// Removed from the update loop
}

void InputSystem::addObj(GameObject* obj)
{
	// Ensure we have the required components
	if (!obj->componentBitset.test(ComponentIndex::TRANSFORM_COMPONENT))
	{
		// We don't care about this object
		return;
	}

	// Otherwise add it to the list
	objects.push_back(obj);
}

void InputSystem::removeObj(const GameObject* obj)
{
	// Remove an object from being updated in this system
	auto t = find_if(objects.begin(), objects.end(), [obj](GameObject*& element){ return element == obj; });

	// If we actually found a result
	if (!(t == objects.end()))
	{
		objects.erase(t);
	}
}