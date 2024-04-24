#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "slider.h";
#include <string>
#include <sstream>
#include <iomanip>

slider::slider(sf::Vector2f pos, sf::Vector2f size, float val, float min, float max, std::string units) : position{ pos }, size{ size }, value{ val }, minimum{ min }, maximum{ max }, units{ units } {
	font.loadFromFile("C:\\Users\\isaac\\OneDrive\\Documents\\CodeProjects\\SFMLFonts\\roboto\\Roboto-Regular.ttf");
	txt.setFont(font);
	txt.setString(std::to_string(value).substr(0, 4) + " " + units);
	txt.setPosition(position.x - 65, position.y - 5);
	txt.setCharacterSize(14);

	rectSlider.setSize(size);
	rectSlider.setPosition(position);
	rectSlider.setFillColor(sf::Color::Color(255, 255, 255, 255));

	dial.setRadius(10.f);

	//Determine and set dial position
	dialPosition.y = position.y - (dial.getRadius()/1.5);
	dialPosition.x = position.x - (((val + min) / (max - min)) * size.x) - dial.getRadius();
	dial.setPosition(dialPosition);

	dial.setFillColor(sf::Color::Color(133, 133, 133, 255));
}

sf::Vector2f slider::getDialPosition() {
	return dialPosition;
}

void slider::moveSlider(sf::Vector2f mousePosition, bool isClicked) {
	const float dist = sqrt(pow(mousePosition.x - (dialPosition.x+dial.getRadius()), 2) + pow(mousePosition.y - (dialPosition.y+dial.getRadius()), 2));
	
	if (dist <= dial.getRadius()) {
		dial.setFillColor(sf::Color::Color(61, 61, 61, 255));
	}
	else {
		dial.setFillColor(sf::Color::Color(133, 133, 133, 255));
	}

	if (dist <= dial.getRadius() && isClicked) {
		locked = true;
	}

	if (locked && isClicked) {
		if (mousePosition.x < position.x) {
			dialPosition.x = position.x;
		}
		else if (mousePosition.x > position.x + size.x) {
			dialPosition.x = position.x + size.x - dial.getRadius();
		}
		else {
			dialPosition.x = mousePosition.x;
		}
		dial.setFillColor(sf::Color::Color(61, 61, 61, 255));
		dial.setPosition(dialPosition);

		float relPos = (dialPosition.x - position.x) / (size.x - dial.getRadius());
		value = relPos * (maximum - minimum) + minimum;

		std::stringstream stream;
		stream << std::fixed << std::setprecision(2) << value;
		std::string s = stream.str();

		txt.setString(s + " " + units);
	}
	else {
		locked = false;
	}
}

void slider::render(sf::RenderWindow& window) {
	sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
	sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);

	moveSlider(worldPos, sf::Mouse::isButtonPressed(sf::Mouse::Button::Left));
	window.draw(rectSlider);
	window.draw(dial);
	window.draw(txt);
}

