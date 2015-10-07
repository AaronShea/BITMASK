#pragma once

class Component
{
	public:

		Component();
		virtual ~Component() = 0;

		virtual void update(sf::Time deltaTime) = 0;

		int id = 0;
};