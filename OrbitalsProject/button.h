#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <string>


class button {
	protected:
		sf::Vector2f position;
		sf::Vector2f size;

		sf::RectangleShape rect;
		sf::Text labelTxt;
		sf::Font font;

		std::string text;

		bool lock = false;
		int charSize;

	public:
		button(sf::Vector2f size, sf::Vector2f pos, std::string txt, int charSize);

		bool isClicked(sf::Vector2f mousePos, bool buttonPressed);

		void hoverEffect(sf::Vector2f mousePos);

		void render(sf::RenderWindow& window);

};
