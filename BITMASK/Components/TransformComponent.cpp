#include "TransformComponent.h"
#include "GameObjects/GameObject.h"
#include "ComponentMessage.h"

TransformComponent::TransformComponent(float x, float y, float rot, GameObject* owner)
	: Component(owner)
{
	this->pos.x = x;
	this->pos.y = y;
	this->rot = rot;

	auto msgt = new ComponentMessage(0);
	msgt->setData<int>(123);
	owner->sendMessage(this, msgt);
}

TransformComponent::~TransformComponent()
{
	// Deconstructor Transform
}

void TransformComponent::update(sf::Time deltaTime) {}

void TransformComponent::receiveMessage(ComponentMessage* msg)
{

}