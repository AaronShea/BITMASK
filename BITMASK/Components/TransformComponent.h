#pragma once
#include "Component.h"
#include "SFML/Graphics.hpp"

class TransformComponent : public Component
{
	private:
		sf::Vector2f pos;
		float rot;

	public:
		TransformComponent(float x, float y, float rot);
		~TransformComponent() override;
};