#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <string>
#include "button.h"
#include "toggle.h"

/*
toggle::toggle(sf::Vector2f size, sf::Vector2f pos, std::string txt) : size{ size }, position{ pos }, text{ txt } {
	
	rect.setPosition(position);
	rect.setSize(size);
	rect.setFillColor(sf::Color::Color(100, 120, 120, 1000));
	rect.setOutlineThickness(2);
	rect.setOutlineColor(sf::Color::Color(120, 120, 120, 100));

	font.loadFromFile("C:\\Users\\isaac\\OneDrive\\Documents\\CodeProjects\\SFMLFonts\\getho-font\\GethoLight-7Gal.ttf");

	labelTxt.setFont(font);
	labelTxt.setString(txt);
	labelTxt.setPosition(position.x + 10, position.y + 10);
}*/

bool toggle::getState() {
	return toggleState;
}

void toggle::disable() {
	toggleState = false;
}

void toggle::render(sf::RenderWindow& window) {
	sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
	sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);

	button::hoverEffect(worldPos);

	if (button::isClicked(worldPos, sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) && !lock) {
		lock = true;
		toggleState = !toggleState;
		if (toggleState == true) {
			rect.setFillColor(sf::Color::Color(173, 16, 45, 255));
		}
		else {
			rect.setFillColor(sf::Color::Color(135, 139, 145, 255));
		}
		std::cout << "The button has been pressed" << toggleState << std::endl;
	}
	else if (!button::isClicked(worldPos, sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))) {
		lock = false;
		if (toggleState == true) {
			rect.setFillColor(sf::Color::Color(173, 16, 45, 255));
		}
		else {
			rect.setFillColor(sf::Color::Color(135, 139, 145, 255));
		}
	}

	window.draw(rect);
	window.draw(labelTxt);
}