#pragma once
#include "SFML/Graphics.hpp"
#include "Systems/System.h"
#include <memory>
#include <vector>

namespace bit
{
	class SystemManager
	{
		private:
			std::vector<std::unique_ptr<System>> systems;
			std::vector<System*> eventListeners;

		public:
			SystemManager();
			~SystemManager();

			/**
			* Creates a new System and adds it to the update loop
			*/
			template<typename SystemType, typename ... Args>
			SystemType* addSystem(Args ... args)
			{
				// Make a new owner pointer and add it to the vector
				systems.push_back(std::make_unique<SystemType>(this, args ...));

				// Get a ref to the added system
				auto added = dynamic_cast<SystemType*>(systems.back().get());

				// Tell the system it was added
				added->added();

				// return plain old pointer
				return added;
			};

			void objAdded(GameObject* adding) const;

			void subscribeToEvents(System* sys);
			void unsubscribeToEvents(System* sys);

			void processEvent(sf::Event eEvent);
			void update(sf::Time deltaTime);
	};
}
