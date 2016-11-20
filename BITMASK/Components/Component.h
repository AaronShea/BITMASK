#pragma once
#include <bitset>
#include "SFML/System.hpp"
#include "ComponentIndex.h"

namespace bit
{
	class GameObject;

	class Component
	{

		private:

		public:

			Component() {};

			virtual ~Component() {};

			virtual void added() = 0;
			virtual void removed() = 0;

			int id = 0;

			int componentType = 0;

			GameObject* parent;

			bool dirty = false;
	};
}
