#pragma once
#include "Box2D/Box2D.h"
#include "System.h"

#define RATIO 1.f

namespace bit
{
	class PhysicsSystem : public System
	{
		private:
			b2World* physicsWorld;

		public:
			explicit PhysicsSystem(SystemManager* manager, float gravityX = 0.f, float gravityY = 9.8f);
			~PhysicsSystem();

			void added() override;
			void removed() override;

			void addObj(GameObject* obj) override;
			void removeObj(const GameObject* obj) override;

			void update(sf::Time deltaTime) override;
			void processEvent(sf::Event& eEvent) override;

			b2World* getPhysWorld();
	};
}