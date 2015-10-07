#pragma once
#include "Component.h"
#include "SFML/Graphics.hpp"

class TransformComponent : public Component
{
	private:
		sf::Vector2f pos;
		float rot;

	public:
		TransformComponent(float x, float y, float rot, GameObject* owner);
		void receiveMessage(ComponentMessage* msg) override;
		void update(sf::Time deltaTime) override;
};