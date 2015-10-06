#pragma once
#include "Component.h"
#include <map>

class GameObject
{
	private:
		// Map containing actual entity components
		std::map<int, Component*> components;

		// Bitmask used to know what kind of components this entity contains
		unsigned long componentMask = 0;

		// Current index for next component space in map
		int compIndex = 0;

	public:

		int objectId = 0;

		/**
		* Finds the first component in the map that matches the type given in the template argument
		*/
		template<typename CompType>
		CompType* getSingleComponent()
		{
			// Loop through all components
			for (auto comp : components)
			{
			    // Make sure this is the right type of component we are looking for
				auto testPtr = dynamic_cast<CompType*>(comp.second);
				if (testPtr)
				{
					return testPtr;
				}
			}
			sf::err() << "Component type " << typeid(CompType).name() << " not found in entity!";
			return nullptr;
		}

		/**
		* Add a component to this entity
		*/
		void addComponent(Component* compToAdd)
		{
			// Do we already have this component in our bitmask?
			if (!(componentMask & compToAdd->mask))
			{
				// Add it to the bitmask
				componentMask |= compToAdd->mask;
			}

			// Set the compId
			compToAdd->id = compIndex;

			// Append it to the component vector
			components.insert(std::pair<int, Component*>(compIndex, compToAdd));

			// Increment for the next component to insert
			compIndex++;
		};

		/**
		* Remove a component from this entity based on the component id (local map key)
		*/
		void removeComponent(int componentId)
		{
			// Get the component we want to remove
			Component* removedComp = components[componentId];

			// Remove it from our bitmask
			componentMask &= ~removedComp->mask;

			// Remove it from the map
			components.erase(componentId);
		};



};