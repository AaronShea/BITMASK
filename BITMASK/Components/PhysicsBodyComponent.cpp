#include "PhysicsBodyComponent.h"

bit::PhysicsBodyComponent::PhysicsBodyComponent(b2BodyType bodyType, float x, float y, float rot)
	: Component()
{
	// Set component type
	this->componentType = ComponentIndex::PHYSBODY_COMPONENT;

	// Setup the body def
	physBodyDef.type = bodyType;
	physBodyDef.position.x = x;
	physBodyDef.position.y = y;
	physBodyDef.angle = rot;
}

b2BodyDef* bit::PhysicsBodyComponent::getPhysBodyDef()
{
	return &physBodyDef;
}

b2Body* bit::PhysicsBodyComponent::getPhysBody() const
{
	return physBody;
}

void bit::PhysicsBodyComponent::setPhysBody(b2Body* newBody)
{
	this->physBody = newBody;
}

b2Fixture* bit::PhysicsBodyComponent::addFixtureToBody(const float32& density, b2Shape* shape) const
{
	if (this->physBody == nullptr)
	{
		throw std::runtime_error("PhysicsBodyComponent::addFixtureToBody No body to this component yet!");
	}
	return this->physBody->CreateFixture(shape, density);
}

bit::PhysicsBodyComponent::~PhysicsBodyComponent()
{
	// Deconstructor for body component
}

void bit::PhysicsBodyComponent::added()
{

}

void bit::PhysicsBodyComponent::removed()
{

}