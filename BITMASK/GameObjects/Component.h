#pragma once
#include "Components/ComponentIndex.h"

class Component
{
	public:

		Component()
		{
			// STUB
		};

		virtual ~Component()
		{
			// STUB
		};

		unsigned long mask = 0;
		int id = 0;
};