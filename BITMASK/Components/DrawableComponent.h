#pragma once
#include "SFML/Graphics/Shader.hpp"
#include "SFML/Graphics.hpp"
#include "Component.h"

namespace bit
{
	class DrawableComponent : public Component
	{
		public:
			virtual ~DrawableComponent() {};
			virtual sf::Drawable& getDrawData() = 0;

			virtual void added() override = 0;
			virtual void removed() override = 0;

			sf::Shader* shader;
	};

	// Just a mark or "flag" component. No data, just to let the render system know we can render stuff in this object
	class RenderableComponent : public Component
	{
		public:
			RenderableComponent()
				: Component()
			{
				this->componentType = RENDERABLE_COMPONENT;
			};

			void added() override {};
			void removed() override {};
	};
}