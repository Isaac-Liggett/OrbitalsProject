#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "button.h"
#include "toggle.h"
#include "slider.h"
#include "gameDef.h"

class menu {

	protected:
		sf::Vector2f position;
		sf::Vector2f size;
		sf::RectangleShape rect;

		//Text Elements
		sf::Text radTxt;
		sf::Text velXTxt;
		sf::Text velYTxt;
		sf::Text title;

		sf::Font txtFont;
		sf::Font txtFontBold;

	public:

		static toggle tbtn;
		static slider velocityX;
		static slider velocityY;
		static slider radius;
		static toggle movebtn;
		static button clearAll;

		menu(sf::Vector2f, sf::Vector2f);

		sf::Vector2f getPosition();
		sf::Vector2f getSize();

		void render(sf::RenderWindow&, mode& placemode);
};
