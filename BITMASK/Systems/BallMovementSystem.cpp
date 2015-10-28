#include "BallMovementSystem.h"
#include "GameObjects/GameObject.h"
#include "Components/ShapeComponent.h"
#include "Components/PhysicsBodyComponent.h"

bit::BallMovementSystem::BallMovementSystem(SystemManager* manager)
	: System(manager)
{

}

bit::BallMovementSystem::~BallMovementSystem()
{
	// STUB
}

void bit::BallMovementSystem::update(sf::Time deltaTime)
{
	for (auto& obj : objects)
	{
		ShapeComponent* shape = obj->getSingleComponent<ShapeComponent>();
		PhysicsBodyComponent* physBody = obj->getSingleComponent<PhysicsBodyComponent>();

		shape->getShape().setPosition(physBody->getPhysBody()->GetPosition().x, physBody->getPhysBody()->GetPosition().y);
		shape->getShape().setRotation(physBody->getPhysBody()->GetAngle());
	}
}

void bit::BallMovementSystem::processEvent(sf::Event& eEvent) {}

void bit::BallMovementSystem::added()
{
	// System added to world
}

void bit::BallMovementSystem::removed()
{
	// System removed from world
}

void bit::BallMovementSystem::addObj(GameObject* objToAdd)
{
	// We need both a transform component AND a physics component
	if (!objToAdd->componentBitset.test(ComponentIndex::PHYSBODY_COMPONENT) && !objToAdd->componentBitset.test(ComponentIndex::SHAPE_COMPONENT))
	{
		// We don't care about this object
		return;
	}

	objects.push_back(objToAdd);
}

void bit::BallMovementSystem::removeObj(const GameObject* obj)
{

}