#pragma once
#include "DrawableComponent.h"
#include "Component.h"

namespace bit
{
	class ShapeComponent : public DrawableComponent, public Component
	{
		private:
			sf::Shape* shapeData;

		public:
			ShapeComponent(sf::Shape* constrShape);
			~ShapeComponent() override;
			sf::Drawable& getDrawData() override;
	};
}
