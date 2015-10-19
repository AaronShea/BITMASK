#pragma once
#include "System.h"

class DrawableComponent;

class RenderSystem : public System
{
	private:
		std::vector<DrawableComponent*> comps;
		sf::RenderTarget* target;

	public:
		RenderSystem(SystemManager* manager, sf::RenderTarget* renderTarget);
		~RenderSystem();

		void added() override;
		void removed() override;

		void addObj(GameObject* obj) override;
		void removeObj(const GameObject* obj) override;

		void update(sf::Time deltaTime) override;
		void processEvent(sf::Event& eEvent) override;
};