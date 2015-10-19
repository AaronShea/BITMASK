#pragma once
#include "SFML/Graphics.hpp"
#include "Component.h"

class TransformComponent : public Component
{
	private:
		sf::Vector2f pos;
		float rot;

	public:
		TransformComponent(float x, float y, float rot);
		~TransformComponent() override;
};