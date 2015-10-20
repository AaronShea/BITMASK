#pragma once
#include "SFML/Graphics.hpp"

namespace bit
{
	class DrawableComponent
	{
		public:
			virtual ~DrawableComponent() {};
			virtual sf::Drawable& getDrawData() = 0;
	};
}