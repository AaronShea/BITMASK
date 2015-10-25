#pragma once
#include "System.h"

namespace bit
{

	class TransformComponent;
	class ShapeComponent;

	class BallMovementSystem : public System
	{
		private:
			std::vector<std::pair<ShapeComponent*, TransformComponent*>> ballPairs;

		public:
			BallMovementSystem(SystemManager* manager);
			~BallMovementSystem();

			void added() override;
			void removed() override;

			void addObj(GameObject* obj) override;
			void removeObj(const GameObject* obj) override;

			void update(sf::Time deltaTime) override;
			void processEvent(sf::Event& eEvent) override;
	};
}