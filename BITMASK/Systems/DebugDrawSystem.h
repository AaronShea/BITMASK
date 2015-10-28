#pragma once
#include "Box2D/Box2D.h"
#include "System.h"

class DebugDraw;

namespace bit
{
	class PhysicsSystem;	

	class DebugDrawSystem : public System
	{
		private:
			b2World* physWorld;
			DebugDraw* dbgDrawer;
			bool enabled = false;
			

		public:
			DebugDrawSystem(SystemManager* manager, PhysicsSystem* physSystem, sf::RenderWindow* drawTarget, bool enabledByDefault = false);
			~DebugDrawSystem();

			void added() override;
			void removed() override;

			void addObj(GameObject* obj) override;
			void removeObj(const GameObject* obj) override;

			void update(sf::Time deltaTime) override;
			void processEvent(sf::Event& eEvent) override;
	};
}
