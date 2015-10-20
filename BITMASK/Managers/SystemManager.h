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
			System* addSystem(Args ... args)
			{
				systems.push_back(std::make_unique<SystemType>(this, args ...));
				auto added = systems.back().get();
				return added;
			};

			void subscribeToEvents(System* sys);
			void unsubscribeToEvents(System* sys);

			void processEvent(sf::Event eEvent);
			void update(sf::Time deltaTime);
	};
}
