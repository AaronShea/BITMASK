#include "TransformComponent.h"

bit::TransformComponent::TransformComponent(float x, float y, float rot)
	: Component()
{
	this->pos.x = x;
	this->pos.y = y;
	this->rot = rot;

	this->componentType = ComponentIndex::TRANSFORM_COMPONENT;
}

bit::TransformComponent::~TransformComponent()
{
	// Deconstructor Transform
}
