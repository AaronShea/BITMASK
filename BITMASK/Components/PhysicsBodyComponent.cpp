#include "PhysicsBodyComponent.h"

bit::PhysicsBodyComponent::PhysicsBodyComponent(b2BodyType bodyType)
	: Component()
{
	// Set component type
	this->componentType = ComponentIndex::PHYSBODY_COMPONENT;

	// Setup the body def
	physBodyDef.type = bodyType;
}

b2BodyDef* bit::PhysicsBodyComponent::getPhysBodyDef()
{
	return &physBodyDef;
}

b2Body* bit::PhysicsBodyComponent::getPhysBody()
{
	return physBody;
}

void bit::PhysicsBodyComponent::setPhysBody(b2Body* newBody)
{
	this->physBody = newBody;
}

b2Fixture* bit::PhysicsBodyComponent::addFixtureToBody(b2FixtureDef* fixDef)
{
	if (this->physBody == nullptr)
	{
		throw std::runtime_error("PhysicsBodyComponent::addFixtureToBody No body to this component yet!");
	}

	return this->physBody->CreateFixture(fixDef);
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