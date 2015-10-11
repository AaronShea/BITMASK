#pragma once
#include "SFML/Graphics.hpp"
#include <memory>
#include <vector>

class System;

class SystemManager
{
	private:
		std::vector<std::unique_ptr<System>> systems;
		std::vector<std::unique_ptr<System>> eventListeners;

	public:
		SystemManager();
		~SystemManager();

		void addSystem(System* sys);
		void removeSystem(System* sys);

		void subscribeToEvents(System* sys);
		void unsubscribeToEvents(System* sys);

		void processEvent(sf::Event eEvent);
		void update(sf::Time deltaTime);
};