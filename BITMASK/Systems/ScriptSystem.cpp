#include "ScriptSystem.h"
#include "Components/ScriptedComponent.h"
#include "chaiscript/chaiscript.hpp"

bit::ScriptSystem::ScriptSystem(SystemManager* manager, chaiscript::ChaiScript* scriptEngine)
	: System(manager)
{
	this->scriptEngine = scriptEngine;
}

bit::ScriptSystem::~ScriptSystem() {}

void bit::ScriptSystem::added() {}

void bit::ScriptSystem::removed() {}

void bit::ScriptSystem::addObj(GameObject * obj)
{
	// We only care about objects with script components
	if (!obj->componentBitset.test(ComponentIndex::SCRIPT_COMPONENT))
	{
		return;
	}

	// Register the module of this script with the main script engine
	obj->getSingleComponent<ScriptedComponent>(ComponentIndex::SCRIPT_COMPONENT)->init(this->scriptEngine);
}

void bit::ScriptSystem::removeObj(const GameObject * obj) {}

void bit::ScriptSystem::update(sf::Time deltaTime) {}

void bit::ScriptSystem::processEvent(sf::Event & eEvent) {}
