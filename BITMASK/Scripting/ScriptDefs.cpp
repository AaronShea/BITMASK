#include "ScriptDefs.h"
#include "chaiscript/chaiscript.hpp"

// GameObjects
#include "GameObjects/GameObject.h"

// Managers
#include "Managers/GameObjectManager.h"
#include "Managers/SystemManager.h"

// Components
#include "Components/Component.h"
#include "Components/DrawableComponent.h"
#include "Components/PhysicsBodyComponent.h"
#include "Components/ShapeComponent.h"

void bit::ScriptDefs::registerTypes(chaiscript::ChaiScript* engine)
{
	// Physics
	engine->add_global_const(chaiscript::const_var(b2BodyType::b2_dynamicBody), "b2_dynamicBody");
	engine->add_global_const(chaiscript::const_var(b2BodyType::b2_staticBody), "b2_staticBody");
	engine->add_global_const(chaiscript::const_var(b2BodyType::b2_kinematicBody), "b2_kinematicBody");
	engine->add(chaiscript::user_type<b2BodyType>(), "b2BodyType");

	// GameObject
	engine->add(chaiscript::user_type<GameObject>(), "GameObject");
	engine->add(chaiscript::fun(&GameObject::enabled), "enabled");
	engine->add(chaiscript::fun(&GameObject::objectId), "objectId");
	engine->add(chaiscript::fun(&GameObject::getComponentById), "getComponentById");

	// Adding component methods
	engine->add(chaiscript::fun(&GameObject::addComponent<PhysicsBodyComponent, b2BodyType, const float&, const float&, const float&>), "addPhysicsComponent");

	// Managers
	engine->add(chaiscript::user_type<GameObjectManager>(), "GameObjectManager");
	engine->add(chaiscript::fun(&GameObjectManager::createNewObject), "createNewObject");

	// Components
	engine->add(chaiscript::user_type<Component>(), "Component");
	engine->add(chaiscript::fun(&Component::id), "id");
	engine->add(chaiscript::fun(&Component::dirty), "dirty");
	engine->add(chaiscript::fun(&Component::componentType), "componentType");
	
	// Class derive defs
	engine->add(chaiscript::base_class<Component, DrawableComponent>());
	engine->add(chaiscript::base_class<Component, PhysicsBodyComponent>());
	engine->add(chaiscript::base_class<DrawableComponent, ShapeComponent>());
}