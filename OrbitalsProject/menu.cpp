#include <SFML/Graphics.hpp>
#include "menu.h"
#include "button.h"
#include "toggle.h"
#include <string>
#include "gameDef.h"

menu::menu(sf::Vector2f pos, sf::Vector2f size) : position{ pos }, size{ size } {
	menu:rect = sf::RectangleShape(size);
	rect.setPosition(pos);
	rect.setFillColor(sf::Color::Color(122, 119, 119, 100));
	rect.setOutlineThickness(2);
	rect.setOutlineColor(sf::Color::Color(122, 119, 119, 255));
	txtFont.loadFromFile("C:\\Users\\isaac\\OneDrive\\Documents\\CodeProjects\\SFMLFonts\\opensans\\OpenSans-Regular.ttf");
	txtFontBold.loadFromFile("C:\\Users\\isaac\\OneDrive\\Documents\\CodeProjects\\SFMLFonts\\opensans\\OpenSans-SemiBold.ttf");

	title.setString("Add Planet Menu");
	title.setFont(txtFontBold);
	title.setCharacterSize(28);
	title.setPosition(820, 40);

	velXTxt.setString("Velocity in x direction");
	velXTxt.setFont(txtFont);
	velXTxt.setCharacterSize(20);
	velXTxt.setPosition(815, 160);

	velYTxt.setString("Velocity in y direction");
	velYTxt.setFont(txtFont);
	velYTxt.setCharacterSize(20);
	velYTxt.setPosition(815, 260);

	radTxt.setString("Planet Radius");
	radTxt.setFont(txtFont);
	radTxt.setCharacterSize(20);
	radTxt.setPosition(815, 360);
}

toggle menu::tbtn(sf::Vector2f(190, 55), sf::Vector2f(900, 650), "Place Planet", 30);
toggle menu::movebtn(sf::Vector2f(120, 35), sf::Vector2f(820, 100), "Move Scene", 17);
button menu::clearAll(sf::Vector2f(130, 35), sf::Vector2f(960, 100), "Delete Planets", 16);
slider menu::velocityX(sf::Vector2f(880, 200), sf::Vector2f(310, 5), 0.f, -10.f, 10.f, "px/s");
slider menu::velocityY(sf::Vector2f(880, 300), sf::Vector2f(310, 5), 0.f, -10.f, 10.f, "px/s");
slider menu::radius(sf::Vector2f(880, 400), sf::Vector2f(310, 5), 0.f, 1.f, 150.f, "px");

sf::Vector2f menu::getPosition() {
	return position;
}

sf::Vector2f menu::getSize() {
	return size;
}

void menu::render(sf::RenderWindow& window, mode& gameMode) {
	window.draw(rect);
	tbtn.render(window);
	movebtn.render(window);
	clearAll.render(window);
	if (gameMode == move && tbtn.getState()) {
		movebtn.disable();
		gameMode = place;
	}
	if (gameMode == place && movebtn.getState()) {
		tbtn.disable();
		gameMode = move;
	}

	if (tbtn.getState()) {
		gameMode = place;
		
	} else if (movebtn.getState()) {
		gameMode = move;
	}
	else {
		gameMode = none;
	}

	velocityX.render(window);
	velocityY.render(window);
	radius.render(window);
	window.draw(radTxt);
	window.draw(velXTxt);
	window.draw(velYTxt);
	window.draw(title);
}