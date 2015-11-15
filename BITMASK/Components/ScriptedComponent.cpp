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
	auto t = scriptEngine->eval(moduleConstructor);
	scriptInstance = t;
}

void bit::ScriptedComponent::callFunction(std::string functionName) const
{
	// Load the requested function from the script context
	auto caller = scriptEngine->eval<std::function<void(chaiscript::Boxed_Value&)>>(functionName);
	if (caller != nullptr)
	{
		caller(static_cast<chaiscript::Boxed_Value>(scriptInstance));
	}
}
