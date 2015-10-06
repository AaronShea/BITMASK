#pragma once
#include "GameObjects/Component.h"
#include "SFML/Graphics.hpp"

class KeyboardInputComponent : public Component
{
	public:
		KeyboardInputComponent()
			: Component()
		{
			this->mask = ComponentMask::KEYBOARD_INPUT;
		};
};