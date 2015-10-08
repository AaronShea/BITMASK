#include "GameObject.h"
#include "GameObjectManager.h"

GameObject* GameObjectManager::createObject()
{
	// Make a new empty game object
	auto tempObj = new GameObject();
	tempObj->objectId = objectIdCounter;

	// Add it to the vector
	objList.push_back(std::pair<int, GameObject*>(objectIdCounter, tempObj));

	// Inc the objectIdCounter for the next insert
	objectIdCounter++;

	return tempObj;
}

GameObject* GameObjectManager::findObjectById(int id)
{
	auto t = find_if(objList.begin(), objList.end(), [id](const std::pair<int, GameObject*>& element){ return element.first == id; });
	return t->second;
}

void GameObjectManager::removeObject(int id)
{
	// Find it based on the component id
	auto t = find_if(objList.begin(), objList.end(), [id](const std::pair<int, GameObject*>& element){ return element.first == id; });

	// Call deconstructor on the object
	delete t->second;

	// Remove pointer pair from the vector
	objList.erase(t);
}