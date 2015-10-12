#pragma once
#include "Components/Component.h"
#include <vector>
#include <bitset>
#include <memory>
#include <assert.h>

class GameObject
{
	private:
		// Map containing actual entity components
		std::vector<std::pair<int, std::unique_ptr<Component>>> components;

		// Current index for next component space in map
		int compIndex = 0;

		

	public:

		int objectId = 0;
		bool enabled = false;

		// Bitset used to keep track of the component types this object has
		std::bitset<256> componentBitset;

		/**
		* Finds the first component in the map that matches the type given in the template argument
		*/
		template<typename CompType>
		CompType* getSingleComponent()
		{
			// Loop through all components
			for (auto& comp : components)
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
		* Gets a single component based on ID
		*/
		Component* getComponentById(const int compId)
		{
			auto t = find_if(components.begin(), components.end(), [compId](const std::pair<int, std::unique_ptr<Component>>& element){ return element.first == compId; });
			
			if (t == components.end())
			{
				return nullptr;
			}

			return t->second.get();
		}

		/**
		* Add a component to this entity
		*/
		template<typename CompFactoryType, typename ... Args>
		void addComponent(Args ... args)
		{
			// Append it to the component vector
			components.push_back(std::pair<int, std::unique_ptr<Component>>(compIndex, std::make_unique<CompFactoryType>(args ...)));

			// Set the component index of the last inserted component
			components.back().second->id = compIndex;

			// If we have not set this bit yet
			if (!componentBitset.test(components.back().second->componentType))
			{
				// Set the bit for this component type
				componentBitset.set(components.back().second->componentType, true);
			}

			// Increment for the next component to insert
			compIndex++;
		};

		/**
		* Remove a component from this entity based on the component id (local map key)
		*/
		void removeComponent(const int compId)
		{
			// Find it based on the component id
			auto t = find_if(components.begin(), components.end(), [compId](const std::pair<int, std::unique_ptr<Component>>& element){ return element.first == compId; });

			// Make sure we're not trying to remove a component that does not exist
			assert(t != components.end());

			// Unset this component type bit 
			componentBitset.set(t->second->componentType, false);

			// Remove pointer pair from the vector, this will destroy the component as well
			components.erase(t);
		};
};