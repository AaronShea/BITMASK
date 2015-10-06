#pragma once
#include "SFML/System.hpp"
#include "GameObjects/Component.h"
#include <map>

class System
{
	public:
		System();
		virtual ~System() = 0;

		// Update this System per tick, pass in the delta time as well
		virtual void update(sf::Time deltaTime) = 0;
		
		// Used to add and remove components from this system
		virtual void addComponent(int objectId, Component* comp);
		virtual void removeComponent(Component* comp);

	private:
		// The bitmask of components needed on objects for us to update them with
		unsigned long requiredMask = 0;

		// Map of all components we actually care about in this System
		// <owningObjectID, Component Pointer>
		std::map<int, Component*> objects;
};