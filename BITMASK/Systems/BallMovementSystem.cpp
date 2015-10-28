#include "BallMovementSystem.h"
#include "GameObjects/GameObject.h"
#include "Components/ShapeComponent.h"
#include "Components/TransformComponent.h"

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
		TransformComponent* trans = obj->getSingleComponent<TransformComponent>();

		shape->getShape().setPosition(trans->pos);
		shape->getShape().setRotation(trans->rot);
		sf::err() << "Updated position to " << shape->getShape().getPosition().x << ":" << shape->getShape().getPosition().y << std::endl;
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