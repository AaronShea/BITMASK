#include "ShapeComponent.h"

bit::ShapeComponent::ShapeComponent(sf::Shape* constrShape)
	: DrawableComponent()
{
	// Set constructor shape data
	this->shapeData = constrShape;

	this->componentType = ComponentIndex::SHAPE_COMPONENT;
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

sf::Shape& bit::ShapeComponent::getShape()
{
	return *shapeData;
}