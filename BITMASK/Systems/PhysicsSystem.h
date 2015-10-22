#pragma once
#include "Box2D/Box2D.h"
#include "System.h"

namespace bit
{

	class PhysicsBodyComponent;

	class PhysicsSystem : public System
	{
		private:
			std::vector<PhysicsBodyComponent*> bodyComps;
			b2World* physicsWorld;

		public:
			PhysicsSystem(SystemManager* manager, float gravityX = 0.0, float gravityY = -9.8);
			~PhysicsSystem();

			void added() override;
			void removed() override;

			void addObj(GameObject* obj) override;
			void removeObj(const GameObject* obj) override;

			void update(sf::Time deltaTime) override;
			void processEvent(sf::Event& eEvent) override;
	};
}