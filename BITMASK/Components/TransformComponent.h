#pragma once
#include "SFML/Graphics.hpp"
#include "Component.h"

namespace bit
{
	class TransformComponent : public Component
	{
		private:
			sf::Vector2f pos;
			float rot;

		public:
			TransformComponent(float x, float y, float rot);
			~TransformComponent() override;

			void added() override;
			void removed() override;
	};
}
