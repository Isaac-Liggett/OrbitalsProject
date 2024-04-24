#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include <string>
#include "button.h"

button::button(sf::Vector2f size, sf::Vector2f pos, std::string txt, int charSize) : size{ size }, position{ pos }, text{ txt }, charSize{ charSize } {
	rect.setPosition(position);
	rect.setSize(size);
	rect.setFillColor(sf::Color::Color(135, 139, 145, 255));
	rect.setOutlineThickness(2);
	rect.setOutlineColor(sf::Color::Color(120, 120, 120, 100));

	font.loadFromFile("C:\\Users\\isaac\\OneDrive\\Documents\\CodeProjects\\SFMLFonts\\opensans\\OpenSans-Regular.ttf");

	labelTxt.setFont(font);
	labelTxt.setCharacterSize(charSize);
	labelTxt.setString(txt);
	labelTxt.setPosition(position.x + 10, position.y + 10);
}

bool button::isClicked(sf::Vector2f mousePos, bool buttonPressed) {
	if (buttonPressed) {
		if (mousePos.x > position.x && mousePos.y > position.y &&
			mousePos.x < (position.x + size.x) && mousePos.y < (position.y + size.y)) {
			return true; //The button has been pressed
		}
	}
	return false;
}

void button::hoverEffect(sf::Vector2f mousePos) {
	if (mousePos.x > position.x && mousePos.y > position.y &&
		mousePos.x < (position.x + size.x) && mousePos.y < (position.y + size.y)) {
		rect.setFillColor(sf::Color::Color(100, 120, 120, 200));
	}
	else {
		rect.setFillColor(sf::Color::Color(135, 139, 145, 255));
	}
}

void button::render(sf::RenderWindow& window) {
	sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
	sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);

	button:hoverEffect(worldPos);
	window.draw(rect);
	window.draw(labelTxt);

	if (button::isClicked(worldPos, sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) && !lock) {
		lock = true;
		std::cout << "The button has been pressed" << std::endl;
	}
	else if(!button::isClicked(worldPos, sf::Mouse::isButtonPressed(sf::Mouse::Button::Left))){
		lock = false;
	}
}