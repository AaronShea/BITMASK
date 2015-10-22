#include "ShapeComponent.h"

bit::ShapeComponent::ShapeComponent(sf::Shape* constrShape)
	: DrawableComponent(),
	Component()
{
	// Set constructor shape data
	this->shapeData = constrShape;

	this->componentType = ComponentIndex::DRAWABLE_COMPONENT;
}

bit::ShapeComponent::~ShapeComponent()
{

}

void bit::ShapeComponent::added()
{

}

void bit::ShapeComponent::removed()
{

}

sf::Drawable& bit::ShapeComponent::getDrawData()
{
	return *shapeData;
}