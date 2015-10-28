#pragma once
#include "Box2D/Box2D.h"
#include "Component.h"

namespace bit
{
	class PhysicsBodyComponent : public Component
	{
		private:
			b2BodyDef physBodyDef;
			b2Body* physBody;

		public:
			PhysicsBodyComponent(b2BodyType bodyType, float x, float y, float rot);
			~PhysicsBodyComponent() override;

			void added() override;
			void removed() override;

			b2BodyDef* getPhysBodyDef();
			b2Body* getPhysBody() const;

			void setPhysBody(b2Body* newBody);
			b2Fixture* addFixtureToBody(b2FixtureDef* fixDef) const;
	};
}