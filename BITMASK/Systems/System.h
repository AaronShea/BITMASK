#pragma once
#include "Components/Component.h"

class System
{
	private:
		std::vector<std::pair<int, Component*>> components;
		unsigned long requiredMask = 0;

	public:
		System();
		virtual ~System();

		virtual void added();
		virtual void addComponent(Component* comp);
		virtual void removeComponent(Component* compToRemove);

		virtual void update(sf::Time deltaTime);
};