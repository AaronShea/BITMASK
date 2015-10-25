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
	for (auto& pair : ballPairs)
	{
		pair.first->getShape().setPosition(pair.second->pos);
		pair.first->getShape().setRotation(pair.second->rot);
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

	// Grab the phys and transform component pointers
	ShapeComponent* shapeComp = objToAdd->getSingleComponent<ShapeComponent>();
	TransformComponent* transformComp = objToAdd->getSingleComponent<TransformComponent>();

	auto newPair = std::pair<ShapeComponent*, TransformComponent*>(shapeComp, transformComp);
	ballPairs.push_back(newPair);
}

void bit::BallMovementSystem::removeObj(const GameObject* obj)
{

}