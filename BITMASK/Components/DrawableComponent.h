#pragma once
#include "SFML/Graphics.hpp"
#include "Component.h"

namespace bit
{
	class DrawableComponent : public Component
	{
		public:
			virtual ~DrawableComponent() {};
			virtual sf::Drawable& getDrawData() = 0;

			virtual void added() = 0;
			virtual void removed() = 0;
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

			void added() {};
			void removed() {};
	};
}