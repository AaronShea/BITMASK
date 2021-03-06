#pragma once
#include "System.h"

namespace bit
{
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
			void processEvent(sf::Event& eEvent) override;
	};
}
