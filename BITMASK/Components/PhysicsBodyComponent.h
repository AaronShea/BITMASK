#pragma once
#include "Box2D/Box2D.h"
#include "Component.h"

namespace bit
{
	class PhysicsBodyComponent : public Component
	{
		private:
			b2BodyDef physBodyDef;

		public:
			PhysicsBodyComponent(b2BodyType bodyType);
			~PhysicsBodyComponent() override;

			void added() override;
			void removed() override;

			b2BodyDef* getPhysBody();
	};
}