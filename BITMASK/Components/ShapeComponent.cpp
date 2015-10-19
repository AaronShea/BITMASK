#include "ShapeComponent.h"

ShapeComponent::ShapeComponent(sf::Shape* constrShape)
	: DrawableComponent(),
	Component()
{
	// Set constructor shape data
	this->shapeData = constrShape;

	this->componentType = ComponentIndex::DRAWABLE_COMPONENT;
}

ShapeComponent::~ShapeComponent()
{

}

sf::Drawable& ShapeComponent::getDrawData()
{
	return *shapeData;
}