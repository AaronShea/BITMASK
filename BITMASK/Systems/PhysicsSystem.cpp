#include "PhysicsSystem.h"
#include "Components/PhysicsBodyComponent.h"
#include "Components/TransformComponent.h"

bit::PhysicsSystem::PhysicsSystem(SystemManager* manager, float gravityX, float gravityY)
	: System(manager)
{
	// Construct a new Physics World
	physicsWorld = new b2World(b2Vec2(gravityX, gravityY));

	// Enable sleeping within this world
	physicsWorld->SetAllowSleeping(true);
}

void bit::PhysicsSystem::update(sf::Time deltaTime)
{
	// Step the physics world (simulation)
	physicsWorld->Step(static_cast<float32>(deltaTime.asMilliseconds()), 6, 2);

	// Update all pairs of components
}

void bit::PhysicsSystem::processEvent(sf::Event& eEvent) { }

void bit::PhysicsSystem::added()
{
	// When this system is added to the world
}

void bit::PhysicsSystem::removed()
{
	// When this system is removed from the world
}

void bit::PhysicsSystem::addObj(GameObject* objToAdd)
{
	// We need both a transform component AND a physics component
	if (!objToAdd->componentBitset.test(ComponentIndex::PHYSBODY_COMPONENT) && !objToAdd->componentBitset.test(ComponentIndex::TRANSFORM_COMPONENT))
	{
		// We don't care about this object
		return;
	}

	// Grab the phys and transform component pointers
	PhysicsBodyComponent* physComp = objToAdd->getSingleComponent<PhysicsBodyComponent>();
	TransformComponent* transformComp = objToAdd->getSingleComponent<TransformComponent>();

	// Create a new body based on the def
	b2Body* body = physicsWorld->CreateBody(physComp->getPhysBodyDef());

	// Now set the component physBody pointer to the actual physBody
	physComp->setPhysBody(body);

	// Add to the system vector
	bodyComps.push_back(physComp);
}

void bit::PhysicsSystem::removeObj(const GameObject* obj)
{
}