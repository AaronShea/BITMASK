#include "PhysicsBodyComponent.h"

bit::PhysicsBodyComponent::PhysicsBodyComponent()
{
	// Set component type
	this->componentType = ComponentIndex::PHYSBODY_COMPONENT;
}

b2Body* bit::PhysicsBodyComponent::getPhysBody()
{
	return physBody;
}

bit::PhysicsBodyComponent::~PhysicsBodyComponent()
{
	// Deconstructor for body component
}