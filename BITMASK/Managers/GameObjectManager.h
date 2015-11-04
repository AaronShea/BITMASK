#pragma once
#include <vector>
#include <memory>

namespace bit 
{
	class GameObject;
	class SystemManager;

	class GameObjectManager
	{
		private:
			SystemManager* manager;
			std::vector<std::unique_ptr<GameObject>> objects;
			unsigned int objectCounter = 0;

		public:
			explicit GameObjectManager(SystemManager* manager);
			~GameObjectManager();

			GameObject* createNewObject();
			void registerObjectWithSystems(GameObject* obj) const;
			bool removeObject(int idToRemove);
	};
}