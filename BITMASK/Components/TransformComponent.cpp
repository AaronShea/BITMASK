#include "TransformComponent.h"
#include "GameObjects/GameObject.h"

TransformComponent::TransformComponent(float x, float y, float rot)
	: Component()
{
	this->pos.x = x;
	this->pos.y = y;
	this->rot = rot;

	this->componentType = ComponentIndex::TRANSFORM_COMPONENT;
}

TransformComponent::~TransformComponent()
{
	// Deconstructor Transform
}
