#pragma once
#include "SFML/System.hpp"
#include "ComponentIndex.h"

class GameObject;
class ComponentMessage;

class Component
{

	private:

	public:

		Component() {};

		virtual ~Component() {};

		int id = 0;

		int componentType = 0;
};