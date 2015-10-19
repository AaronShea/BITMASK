#pragma once
#include "SFML/Graphics.hpp"

class DrawableComponent
{
	public:
		virtual ~DrawableComponent() {};
		virtual sf::Drawable& getDrawData() = 0;
};