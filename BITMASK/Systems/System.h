#pragma once
#include "SFML/Graphics.hpp"
#include "GameObjects/GameObject.h"
#include <vector>

class SystemManager;

class System
{
	protected:
		SystemManager* manager;

	public:
		System(SystemManager* manager)
		{
			this->manager = manager;
		};

		virtual void added() = 0;
		virtual void removed() = 0;

		virtual void addObj(GameObject* obj) = 0;
		virtual void removeObj(const GameObject* obj) = 0;

		virtual void update(sf::Time deltaTime) = 0;
		virtual void processEvent(sf::Event& eEvent) = 0;
};