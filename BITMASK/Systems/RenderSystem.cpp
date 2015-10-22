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
	target->clear();
	for (auto& drawable : comps)
	{
		this->target->draw(drawable->getDrawData());
	}
}

void bit::RenderSystem::processEvent(sf::Event& eEvent) { }

void bit::RenderSystem::addObj(GameObject* obj)
{
	// Ensure we have the required components
	if (!obj->componentBitset.test(ComponentIndex::DRAWABLE_COMPONENT))
	{
		// We don't care about this object
		return;
	}

	obj->getComponents<DrawableComponent>(comps);
};

void bit::RenderSystem::removeObj(const GameObject* obj)
{
	// Remove an object from being updated in this system
	//auto t = find_if(objects.begin(), objects.end(), [obj](GameObject*& element){ return element == obj; });

	// If we actually found a result
	//if (!(t == objects.end()))
	//{
	//	objects.erase(t);
	//}
}

void bit::RenderSystem::added()
{
	// This system was added to the update loop
}

void bit::RenderSystem::removed()
{
	// Removed from the update loop
}