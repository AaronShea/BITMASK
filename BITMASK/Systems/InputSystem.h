#pragma once
#include "System.h"

class InputSystem : public System
{
	public:
		InputSystem(SystemManager* manager);
		~InputSystem();

		void added() override;
		void removed() override;
		void addObj(GameObject* obj) override;
		void removeObj(const GameObject* obj) override;

		void update(sf::Time deltaTime) override;
};