#pragma once
#include "SFML/System.hpp"
#include "ComponentIndex.h"

namespace bit
{
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

			bool dirty = false;
	};
}
