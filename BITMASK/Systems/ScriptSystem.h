#pragma once
#include "System.h"

namespace chaiscript
{
	class ChaiScript;
	class Module;
}

namespace bit
{
	class ScriptSystem : public System
	{
		private:
			chaiscript::ChaiScript* scriptEngine;

		public:
			explicit ScriptSystem(SystemManager* manager, chaiscript::ChaiScript* scriptEngine);
			~ScriptSystem();

			void added() override;
			void removed() override;

			void addObj(GameObject* obj) override;
			void removeObj(const GameObject* obj) override;

			void update(sf::Time deltaTime) override;
			void processEvent(sf::Event& eEvent) override;
	};
}
