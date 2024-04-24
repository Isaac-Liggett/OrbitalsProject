#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <string>
#include "button.h"

class toggle : public button {
	protected:
		bool toggleState = false;

	public:
		toggle(sf::Vector2f size, sf::Vector2f pos, std::string txt, int charSize) : button(size, pos, txt, charSize) {
		};

		bool getState();

		void disable();

		void render(sf::RenderWindow& window);

};
