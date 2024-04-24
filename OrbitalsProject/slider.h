#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

class slider {
	protected:
		sf::Vector2f position;
		sf::Vector2f dialPosition;
		sf::Vector2f size;

		sf::Text txt;
		sf::Font font;
		
		float value;
		float minimum;
		float maximum;
		std::string units;
		
		//drawing features
		sf::RectangleShape rectSlider;
		sf::CircleShape dial;

		bool locked = false;

	public:
		slider(sf::Vector2f pos, sf::Vector2f size, float val, float min, float max, std::string units);

		sf::Vector2f getDialPosition();

		void moveSlider(sf::Vector2f mousePosition, bool isClicked);

		void render(sf::RenderWindow& window);

		float getValue() {
			return value;
		}


};