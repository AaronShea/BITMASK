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

bit::PhysicsSystem::~PhysicsSystem()
{

}

void bit::PhysicsSystem::update(sf::Time deltaTime)
{
	for (auto& obj : objects)
	{
		// Check each pair to make sure we have up to date locations of the bodies
		if (obj->getSingleComponent<TransformComponent>()->dirty)
		{
			// If the transform component is already dirty, we need to update the physics body
			obj->getSingleComponent<PhysicsBodyComponent>()->getPhysBody()->SetTransform(
				b2Vec2(obj->getSingleComponent<TransformComponent>()->pos.x / RATIO, 
				obj->getSingleComponent<TransformComponent>()->pos.y / RATIO),
				obj->getSingleComponent<TransformComponent>()->rot
			);
		}
	}

	// Step the physics world (simulation)
	physicsWorld->Step(static_cast<float32>(deltaTime.asMilliseconds()), 6, 2);

	// Update all pairs of components
	for (auto& obj : objects)
	{
		if (obj->getSingleComponent<PhysicsBodyComponent>()->getPhysBody()->IsAwake())
		{
			// Apply the position of the PhysicsBody to the transform component
			obj->getSingleComponent<TransformComponent>()->pos.x = obj->getSingleComponent<PhysicsBodyComponent>()->getPhysBody()->GetPosition().x * RATIO;
			obj->getSingleComponent<TransformComponent>()->pos.y = obj->getSingleComponent<PhysicsBodyComponent>()->getPhysBody()->GetPosition().y * RATIO;

			// Also apply the rotation/angle
			obj->getSingleComponent<TransformComponent>()->rot = obj->getSingleComponent<PhysicsBodyComponent>()->getPhysBody()->GetAngle();

			// The transform component is now ditry
			obj->getSingleComponent<TransformComponent>()->dirty = true;
		}
	}
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

	// Create a new body based on the def
	b2Body* body = physicsWorld->CreateBody(physComp->getPhysBodyDef());

	// Now set the component physBody pointer to the actual physBody
	physComp->setPhysBody(body);

	// Add object to the vector
	objects.push_back(objToAdd);
}

void bit::PhysicsSystem::removeObj(const GameObject* obj)
{
}