#include "DrawDebug/BoxDebugrender.h"
#include "DebugDrawSystem.h"
#include "PhysicsSystem.h"

bit::DebugDrawSystem::DebugDrawSystem(SystemManager* manager, PhysicsSystem* physSystem, sf::RenderWindow* drawTarget, bool enabledByDefault)
	: System(manager)
{
	// Set if this should be draw by default
	this->enabled = enabledByDefault;

	// Grab the physics world
	this->physWorld = physSystem->getPhysWorld();

	// Now make a new Debug Draw
	this->dbgDrawer = new DebugDraw(*drawTarget);

	// Set the draw flags
	this->dbgDrawer->SetFlags(b2Draw::e_aabbBit | b2Draw::e_centerOfMassBit | b2Draw::e_jointBit | b2Draw::e_pairBit | b2Draw::e_shapeBit);

	// Set the world debug draw
	this->physWorld->SetDebugDraw(this->dbgDrawer);
}

bit::DebugDrawSystem::~DebugDrawSystem()
{
	// Deconstructor
}

void bit::DebugDrawSystem::update(sf::Time deltaTime)
{
	if (this->enabled)
	{
		this->physWorld->DrawDebugData();
	}
}

void bit::DebugDrawSystem::processEvent(sf::Event& eEvent)
{
	switch (eEvent.type)
	{
		case sf::Event::KeyPressed:
			if (eEvent.key.code == 54)
			{
				this->enabled = !this->enabled;
			}
			break;
		default:
			break;
	}
}

void bit::DebugDrawSystem::added()
{
	// When this system is added to the world
}

void bit::DebugDrawSystem::removed()
{
	// When this system is removed from the world
}

// This system does not care about game objects
void bit::DebugDrawSystem::addObj(GameObject* objToAdd) {}
void bit::DebugDrawSystem::removeObj(const GameObject* obj) {}