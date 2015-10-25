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

			void added() override;
			void removed() override;

			sf::Drawable& getDrawData() override;
			sf::Shape& getShape();
	};
}
