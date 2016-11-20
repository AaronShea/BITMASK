#include "PhysicsSystem.h"
#include "Components/PhysicsBodyComponent.h"
#include "Components/TransformComponent.h"

bit::PhysicsSystem::PhysicsSystem(SystemManager* manager, float gravityX, float gravityY)
	: System(manager)
{
	// Construct a new Physics World
	physicsWorld = new b2World(b2Vec2(gravityX, gravityY));

	// Set a new contact listener for collision events
	PhysicsSystemContactListener* contactor = new PhysicsSystemContactListener();
	physicsWorld->SetContactListener(contactor);

	// Enable sleeping within this world
	physicsWorld->SetAllowSleeping(true);
}

bit::PhysicsSystem::~PhysicsSystem()
{

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
	// We need both a transform component AND a physics component
	if (!objToAdd->componentBitset.test(ComponentIndex::PHYSBODY_COMPONENT) && !objToAdd->componentBitset.test(ComponentIndex::TRANSFORM_COMPONENT))
	{
		// We don't care about this object
		return;
	}

	// Grab the phys and transform component pointers
	auto physComp = objToAdd->getSingleComponent<PhysicsBodyComponent>(ComponentIndex::PHYSBODY_COMPONENT);

	// Create a new body based on the def
	auto body = physicsWorld->CreateBody(physComp->getPhysBodyDef());

	// Now set the component physBody pointer to the actual physBody
	physComp->setPhysBody(body);

	// Set the userdata as a pointer to the owning physics component
	physComp->getPhysBody()->SetUserData(physComp);

	// Add object to the vector
	objects.push_back(objToAdd);
}

void bit::PhysicsSystem::removeObj(const GameObject* obj)
{
}

b2World* bit::PhysicsSystem::getPhysWorld()
{
	return physicsWorld;
}

//// Box2D Contact Listeners

void bit::PhysicsSystemContactListener::BeginContact(b2Contact* contact)
{
	auto a = (PhysicsBodyComponent*)contact->GetFixtureA()->GetBody()->GetUserData();
	auto b = (PhysicsBodyComponent*)contact->GetFixtureB()->GetBody()->GetUserData();
	a->onCollideStart(b);
	b->onCollideStart(a);
}

void bit::PhysicsSystemContactListener::EndContact(b2Contact* contact)
{
	auto a = (PhysicsBodyComponent*)contact->GetFixtureA()->GetBody()->GetUserData();
	auto b = (PhysicsBodyComponent*)contact->GetFixtureB()->GetBody()->GetUserData();
	a->onCollideEnd(b);
	b->onCollideEnd(a);
}