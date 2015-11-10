#include "ScriptedComponent.h"
#include "chaiscript/chaiscript.hpp"


bit::ScriptedComponent::ScriptedComponent(const std::string& modulePath)
	: scriptEngine(nullptr)
{
	// Set the modulePath
	this->modulePath = modulePath;

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

	// TODO - Load script from archive/disk
	std::string scriptSource = "";

	// Eval the source into the engine
	internalModule->eval(scriptSource);

	// Register this module with the global scripting engine
	internalModule->apply(*scriptEngine, *scriptEngine);
}

std::function<void()> bit::ScriptedComponent::getScriptFunction(std::string functionName) const
{
	// Load the requested function from the script context
	std::function<void()> f = scriptEngine->eval<std::function<void()>>(functionName);

	// It cannot be null
	assert(f != nullptr);

	// Return it for later calling
	return f;
}
