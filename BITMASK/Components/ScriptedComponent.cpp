#include "ScriptedComponent.h"
#include "chaiscript/chaiscript.hpp"
#include "Resources/ScriptManager.h"


bit::ScriptedComponent::ScriptedComponent(const std::string& modulePath)
	: scriptEngine(nullptr)
{
	// Set the modulePath
	this->modulePath = modulePath;
	
	// Create the new internal module
	this->internalModule = std::make_shared<chaiscript::Module>();

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

	// Load script from archive/disk
	std::string scriptSource = bit::ScriptManager::getScriptContent(modulePath);

	// Eval the source into the engine
	internalModule->eval(scriptSource);

	// Register this module with the global scripting engine
	internalModule->apply(*this->scriptEngine, *this->scriptEngine);
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
