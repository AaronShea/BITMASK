#pragma once
#include "SFML/System.hpp"

class GameObject;
class ComponentMessage;

class Component
{

	private:

	public:

		Component() {};

		virtual ~Component() {};

		int id = 0;
};