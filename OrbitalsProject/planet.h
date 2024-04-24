#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

class planet {
	protected:
		sf::Vector2f position;
		sf::Vector2f velocity;
		sf::Vector2f acceleration;
		
		sf::CircleShape c;

		const float density = 2387318563.79f;

	public:
		const float radius;
		float volume;
		float mass;

		planet(sf::Vector2f pos, sf::Vector2f vel, float r);

		sf::Vector2f getPosition();
		sf::Vector2f getMomentum();

		void movePosition(sf::Vector2f delta);

		void applyGravity(sf::Vector2f planet2, float p2mass);
		void applyVelocity();

		void render(sf::RenderWindow& window);


};