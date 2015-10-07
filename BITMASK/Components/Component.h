#pragma once
#include "ComponentMessage.h"
#include "SFML/System.hpp"

class GameObject;

class Component
{

	private:
		GameObject* owner;

	public:

		Component(GameObject* owner)
		{
			this->owner = owner;
		};

		virtual ~Component() {};

		virtual void update(sf::Time deltaTime) = 0;
		virtual void receiveMessage(ComponentMessage* msg) = 0;

		int id = 0;
};