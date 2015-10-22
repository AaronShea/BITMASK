#pragma once
#include "SFML/Graphics.hpp"

namespace bit
{
	class DrawableComponent
	{
		public:
			virtual ~DrawableComponent() {};
			virtual sf::Drawable& getDrawData() = 0;

			virtual void added() = 0;
			virtual void removed() = 0;
	};
}