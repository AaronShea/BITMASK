#pragma once
#include <vector>

class GameObject;

class GameObjectManager
{
	private:
		// Vector of all game objects currently being updated
		std::vector<std::pair<int, GameObject*>> objList;
		int objectIdCounter = 0;

	public:
		/**
		* Create an empty object, push it onto the vector and return the pointer for further modification
		*/
		GameObject* createObject();

		/**
		* Remove an eneity from the Vector via its objectId
		*/
		void removeObject(int id);
		
		/**
		* Finds and returns an object that matches the requested id
		* Returns nullptr if no result is found
		*/
		GameObject* findObjectById(int id);
};