#pragma once
#include "GameObjects/Component.h"
#include "SFML/Graphics.hpp"
#include <string>

class GraphicComponent : public Component
{
	public:
		GraphicComponent(std::string imgPath)
			: Component()
		{
			this->mask = ComponentMask::GRAPHIC;
		};
		sf::Texture mTexture;
		sf::Sprite mSprite;
};