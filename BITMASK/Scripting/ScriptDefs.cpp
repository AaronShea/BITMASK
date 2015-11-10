#include "ScriptDefs.h"
#include "chaiscript/chaiscript.hpp"

#include "Box2D/Box2D.h"

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
#include "Components/ScriptedComponent.h"

void bit::ScriptDefs::registerTypes(chaiscript::ChaiScript* engine)
{
	// ----------------------------
	// Physics
	// ----------------------------
	// b2Vec2
	engine->add(chaiscript::user_type<b2Vec2>(), "b2Vec2");
	engine->add(chaiscript::constructor<b2Vec2()>(), "b2Vec2");
	engine->add(chaiscript::constructor<b2Vec2 (const float32&, const float32&)>(), "b2Vec2");
	engine->add(chaiscript::fun(&b2Vec2::x), "x");
	engine->add(chaiscript::fun(&b2Vec2::y), "y");

	// b2Body
	engine->add(chaiscript::user_type<b2Body>(), "b2Body");
	engine->add(chaiscript::fun(&b2Body::ApplyAngularImpulse), "applyAngularImpulse");
	engine->add(chaiscript::fun(&b2Body::ApplyForce), "applyForce");
	engine->add(chaiscript::fun(&b2Body::ApplyLinearImpulse), "applyLinearImpulse");
	engine->add(chaiscript::fun(&b2Body::ApplyForceToCenter), "applyForceToCenter");
	engine->add(chaiscript::fun(&b2Body::ApplyTorque), "applyTorque");
	engine->add(chaiscript::fun(&b2Body::SetLinearVelocity), "setLinearVelocity");
	engine->add(chaiscript::fun(&b2Body::SetGravityScale), "setGravityScale");

	// b2Shape
	engine->add(chaiscript::user_type<b2Shape>(), "b2Shape");
	engine->add(chaiscript::base_class<b2Shape, b2CircleShape>());
	engine->add(chaiscript::base_class<b2Shape, b2PolygonShape>());
	engine->add(chaiscript::base_class<b2Shape, b2EdgeShape>());

	// b2CircleShape
	engine->add(chaiscript::user_type<b2CircleShape>(), "b2CircleShape");
	engine->add(chaiscript::constructor<b2CircleShape()>(), "b2CircleShape");
	engine->add(chaiscript::fun(&b2CircleShape::m_p), "localPos");
	engine->add(chaiscript::fun(&b2CircleShape::m_radius), "radius");

	// b2FixtureDef
	engine->add(chaiscript::user_type<b2FixtureDef>(), "b2FixtureDef");
	engine->add(chaiscript::constructor<b2FixtureDef()>(), "b2FixtureDef");
	engine->add(chaiscript::fun(&b2FixtureDef::density), "density");
	engine->add(chaiscript::fun(&b2FixtureDef::friction), "friction");
	engine->add(chaiscript::fun(&b2FixtureDef::restitution), "restitution");
	engine->add(chaiscript::fun(&b2FixtureDef::isSensor), "isSensor");
	engine->add(chaiscript::var(&b2FixtureDef::shape), "shape");

	// Body Types
	engine->add_global_const(chaiscript::const_var(b2BodyType::b2_dynamicBody), "b2_dynamicBody");
	engine->add_global_const(chaiscript::const_var(b2BodyType::b2_staticBody), "b2_staticBody");
	engine->add_global_const(chaiscript::const_var(b2BodyType::b2_kinematicBody), "b2_kinematicBody");
	engine->add(chaiscript::user_type<b2BodyType>(), "b2BodyType");

	// Shape Types
	engine->add_global_const(chaiscript::const_var(b2Shape::Type::e_circle), "e_circle");
	engine->add_global_const(chaiscript::const_var(b2Shape::Type::e_chain), "e_chain");
	engine->add_global_const(chaiscript::const_var(b2Shape::Type::e_edge), "e_edge");
	engine->add_global_const(chaiscript::const_var(b2Shape::Type::e_polygon), "e_polygon");
	engine->add_global_const(chaiscript::const_var(b2Shape::Type::e_typeCount), "e_typeCount");
	engine->add(chaiscript::user_type<b2Shape::Type>(), "b2ShapeType");

	// ----------------------------
	// GameObjects
	// ----------------------------
	engine->add(chaiscript::user_type<GameObject>(), "GameObject");
	engine->add(chaiscript::fun(&GameObject::enabled), "enabled");
	engine->add(chaiscript::fun(&GameObject::objectId), "objectId");
	engine->add(chaiscript::fun(&GameObject::getComponentById), "getComponentById");

	// Adding component methods
	engine->add(chaiscript::fun(&GameObject::addComponent<PhysicsBodyComponent, b2BodyType, const float&, const float&, const float&>), "addPhysicsBodyComponent");
	engine->add(chaiscript::fun(&GameObject::getSingleComponent<PhysicsBodyComponent>), "getPhysicsBodyComponent");

	// ----------------------------
	// Managers
	// ----------------------------
	engine->add(chaiscript::user_type<GameObjectManager>(), "GameObjectManager");
	engine->add(chaiscript::fun(&GameObjectManager::createNewObject), "createNewObject");
	engine->add(chaiscript::fun(&GameObjectManager::registerObjectWithSystems), "registerObject");

	// ----------------------------
	// Components
	// ----------------------------
	engine->add(chaiscript::user_type<Component>(), "Component");
	engine->add(chaiscript::fun(&Component::id), "id");
	engine->add(chaiscript::fun(&Component::dirty), "dirty");
	engine->add(chaiscript::fun(&Component::componentType), "componentType");

	// Component Index List
	engine->add_global_const(chaiscript::const_var(ComponentIndex::PHYSBODY_COMPONENT), "PHYSBODY_COMPONENT");
	engine->add_global_const(chaiscript::const_var(ComponentIndex::RENDERABLE_COMPONENT), "RENDERABLE_COMPONENT");
	engine->add_global_const(chaiscript::const_var(ComponentIndex::SHAPE_COMPONENT), "SHAPE_COMPONENT");
	engine->add_global_const(chaiscript::const_var(ComponentIndex::TRANSFORM_COMPONENT), "TRANSFORM_COMPONENT");
	engine->add_global_const(chaiscript::const_var(ComponentIndex::SCRIPT_COMPONENT), "SCRIPT_COMPONENT"); 
	engine->add(chaiscript::user_type<ComponentIndex>(), "ComponentIndex");
	
	// Drawable
	engine->add(chaiscript::base_class<Component, DrawableComponent>());

	// PhysBody
	engine->add(chaiscript::base_class<Component, PhysicsBodyComponent>());
	engine->add(chaiscript::user_type<PhysicsBodyComponent>(), "PhysicsBodyComponent");
	engine->add(chaiscript::fun(&PhysicsBodyComponent::getPhysBody), "getPhysBody");
	engine->add(chaiscript::fun(&PhysicsBodyComponent::addFixtureToBody), "addFixture");

	// Shape
	engine->add(chaiscript::base_class<DrawableComponent, ShapeComponent>());

	// Script Component
	engine->add(chaiscript::base_class<Component, ScriptedComponent>());
	engine->add(chaiscript::user_type<ScriptedComponent>(), "ScriptedComponent");
	engine->add(chaiscript::constructor<ScriptedComponent(const std::string&)>(), "ScriptedComponent");
}