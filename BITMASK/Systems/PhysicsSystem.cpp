#include "PhysicsSystem.h"
#include "Components/PhysicsBodyComponent.h"

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
	if (!objToAdd->componentBitset.test(ComponentIndex::PHYSBODY_COMPONENT))
	{
		// We don't care about this object
		return;
	}

	std::vector<PhysicsBodyComponent*> tempVec;

	objToAdd->getComponents<PhysicsBodyComponent>(tempVec);

	for (auto& bodyComp : tempVec)
	{
		// Create a new body based on the def
		b2Body* body = physicsWorld->CreateBody(bodyComp->getPhysBodyDef());

		// Now set the component physBody pointer to the actual physBody
		bodyComp->setPhysBody(body);

		// Add to the system vector
		bodyComps.push_back(bodyComp);
	}
	
	// Now get its body def and add it to the world
	
}

void bit::PhysicsSystem::removeObj(const GameObject* obj)
{
}