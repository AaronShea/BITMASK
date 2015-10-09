#pragma once
#include "Components/Component.h"
#include <vector>
#include <memory>

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
			// Set the compId
			compToAdd->id = compIndex;

			// Append it to the component vector
			components.push_back(std::pair<int, std::unique_ptr<Component>>(compIndex, std::unique_ptr<Component>(compToAdd)));

			// Increment for the next component to insert
			compIndex++;
		};

		/**
		* Remove a component from this entity based on the component id (local map key)
		*/
		void removeComponent(int compId)
		{
			// Find it based on the component id
			auto t = find_if(components.begin(), components.end(), [compId](const std::pair<int, std::unique_ptr<Component>>& element){ return element.first == compId; });

			// Remove pointer pair from the vector
			components.erase(t);
		};



};