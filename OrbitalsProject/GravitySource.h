#pragma once
#include <SFML/Graphics.hpp>

class GravitySource {

	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Vector2f acceleration;
	float strength;

	public:
		GravitySource() {

		}

		void render(sf::RenderWindow& window) {
			window.draw();
		}

};
