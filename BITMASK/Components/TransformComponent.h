#pragma once
#include "SFML/Graphics.hpp"

class Component;

class TransformComponent : public Component
{
	private:
		sf::Vector2f pos;
		float rot;

	public:
		TransformComponent(float x, float y, float rot);
		~TransformComponent() override;
};