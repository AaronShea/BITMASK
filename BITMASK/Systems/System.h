#pragma once
#include "GameObjects/GameObject.h"
#include <vector>

class System
{
	protected:
		std::vector<GameObject*> objects;

	public:
		virtual void added() = 0;
		virtual void removed() = 0;
		virtual void addObj(GameObject* obj) = 0;
		virtual void removeObj(const GameObject* obj) = 0;

		virtual void update(sf::Time deltaTime) = 0;
};