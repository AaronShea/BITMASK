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
	for (auto& bodyPair : bodyComps)
	{
		// Check each pair to make sure we have up to date locations of the bodies
		if (bodyPair.second->dirty)
		{
			// If the transform component is already dirty, we need to update the physics body
			bodyPair.first->getPhysBody()->SetTransform(
				b2Vec2(bodyPair.second->pos.x / RATIO, bodyPair.second->pos.y / RATIO),
				bodyPair.second->rot
			);
		}
	}

	// Step the physics world (simulation)
	physicsWorld->Step(static_cast<float32>(deltaTime.asMilliseconds()), 6, 2);

	// Update all pairs of components
	for (auto& bodyPair : bodyComps)
	{
		if (bodyPair.first->getPhysBody()->IsAwake())
		{
			// Apply the position of the PhysicsBody to the transform component
			bodyPair.second->pos.x = bodyPair.first->getPhysBody()->GetPosition().x * RATIO;
			bodyPair.second->pos.y = bodyPair.first->getPhysBody()->GetPosition().y * RATIO;

			// Also apply the rotation/angle
			bodyPair.second->rot = bodyPair.first->getPhysBody()->GetAngle();

			// The transform component is now ditry
			bodyPair.second->dirty = true;

			sf::err() << "x=" << bodyPair.second->pos.x << " y=" << bodyPair.second->pos.y << " r=" << bodyPair.second->rot << std::endl;
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
	TransformComponent* transformComp = objToAdd->getSingleComponent<TransformComponent>();

	// TODO - Add them to an std::pair
	auto newPair = std::pair<PhysicsBodyComponent*, TransformComponent*>(physComp, transformComp);
	bodyComps.push_back(newPair);

	// Create a new body based on the def
	b2Body* body = physicsWorld->CreateBody(physComp->getPhysBodyDef());

	// Now set the component physBody pointer to the actual physBody
	physComp->setPhysBody(body);
}

void bit::PhysicsSystem::removeObj(const GameObject* obj)
{
}