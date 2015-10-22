#pragma once
#include "Box2D/Box2D.h"
#include "Component.h"

namespace bit
{
	class PhysicsBodyComponent : public Component
	{
		private:
			b2Body* physBody;

		public:
			PhysicsBodyComponent();
			~PhysicsBodyComponent() override;

			b2Body* getPhysBody();
	};
}