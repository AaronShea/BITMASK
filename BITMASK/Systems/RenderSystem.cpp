#include "Components/DrawableComponent.h"
#include "RenderSystem.h"
#include "SFML/Graphics.hpp"

bit::RenderSystem::RenderSystem(SystemManager* manager, sf::RenderTarget* renderTarget)
	: System(manager),
	target(renderTarget)
{

}

bit::RenderSystem::~RenderSystem()
{
	
}

void bit::RenderSystem::update(sf::Time deltaTime)
{
	// used to keep drawables
	std::vector<DrawableComponent*> drawables;

	// Grab all the drawable components
	for (auto& obj : objects)
	{
		obj->getComponents<DrawableComponent>(drawables);
	}

	// Now draw all the drawable data
	for (auto& dr : drawables)
	{
		target->draw(dr->getDrawData());
	}
}

void bit::RenderSystem::processEvent(sf::Event& eEvent) { }

void bit::RenderSystem::addObj(GameObject* objToAdd)
{
	// Ensure we have the required components
	if (!objToAdd->componentBitset.test(ComponentIndex::RENDERABLE_COMPONENT))
	{
		// We don't care about this object
		return;
	}

	// Add the object to the vector
	objects.push_back(objToAdd);
};

void bit::RenderSystem::removeObj(const GameObject* obj)
{
	// TODO - Need to remove components, not the the actual object!
	// Remove an object from being updated in this system
	auto t = find_if(objects.begin(), objects.end(), [obj](GameObject*& element){ return element == obj; });

	// If we actually found a result
	if (!(t == objects.end()))
	{
	 	objects.erase(t);
	}
}

void bit::RenderSystem::added()
{
	// This system was added to the update loop
}

void bit::RenderSystem::removed()
{
	// Removed from the update loop
}