#include "TransformComponent.h"
#include "GameObjects/GameObject.h"

TransformComponent::TransformComponent(float x, float y, float rot)
	: Component()
{
	this->pos.x = x;
	this->pos.y = y;
	this->rot = rot;
}

TransformComponent::~TransformComponent()
{
	// Deconstructor Transform
}
