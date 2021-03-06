#include "GameObjectManager.h"
#include "SystemManager.h"
#include "GameObjects/GameObject.h"

bit::GameObjectManager::GameObjectManager(SystemManager* manager)
{
	this->manager = manager;
}

bit::GameObjectManager::~GameObjectManager()
{
	// Deconstructor
}

bit::GameObject* bit::GameObjectManager::createNewObject()
{
	// Make a new GameObject unique and add it to the object vector
	objects.push_back(std::make_unique<GameObject>());

	// Set id
	objects.back()->objectId = objectCounter;

	// Incr the counter for next id
	objectCounter++;

	// Tell all the systems about this new object
	// manager->objAdded(objects.back().get());

	// Grab the newly added object and return a raw ptr
	return objects.back().get();
}

void bit::GameObjectManager::registerObjectWithSystems(GameObject* obj) const
{
	manager->objAdded(obj);
}

bool bit::GameObjectManager::removeObject(int idToRemove)
{
	// Find the object with that id
	auto t = find_if(objects.begin(), objects.end(), [idToRemove](const std::unique_ptr<GameObject>& element){ return element->objectId == idToRemove; });

	// Make sure we actually are removing a real object
	assert(t != objects.end());

	// Erase this pointer
	objects.erase(t);

	return true;
}
