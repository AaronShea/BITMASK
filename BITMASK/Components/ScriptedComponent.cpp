#include "ScriptedComponent.h"
#include "chaiscript/chaiscript.hpp"
#include "Resources/ScriptManager.h"


bit::ScriptedComponent::ScriptedComponent(const std::string& moduleConstructor)
	: scriptEngine(nullptr)
{
	// Set the modulePath
	this->moduleConstructor = moduleConstructor;

	this->componentType = ComponentIndex::SCRIPT_COMPONENT;
}

bit::ScriptedComponent::~ScriptedComponent()
{
	
}

void bit::ScriptedComponent::added() {}
void bit::ScriptedComponent::removed() {}

void bit::ScriptedComponent::init(chaiscript::ChaiScript* scriptEngine)
{
	this->scriptEngine = scriptEngine;

	// The scripting engine cannot be null
	assert(this->scriptEngine != nullptr);

	// Call and store an instance of this module class
	scriptInstance = &scriptEngine->eval(moduleConstructor);
}

std::function<void()> bit::ScriptedComponent::getScriptFunction(std::string functionName) const
{
	// Load the requested function from the script context
	// std::function<void()> f = scriptEngine->eval<std::function<void()>>(functionName);

	// Return it for later calling
	// TODO
	return nullptr;
}
