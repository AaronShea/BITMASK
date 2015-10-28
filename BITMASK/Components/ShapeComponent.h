#pragma once
#include "DrawableComponent.h"

namespace bit
{
	class ShapeComponent : public DrawableComponent
	{
		private:
			sf::Shape* shapeData;

		public:
			explicit ShapeComponent(sf::Shape* constrShape);
			~ShapeComponent() override;

			void added() override;
			void removed() override;

			sf::Drawable& getDrawData() override;
			sf::Shape& getShape();
	};
}
