#include <SFML/Graphics.hpp>
#include "menu.h"
#include "planet.h"
#include <iostream>
#include <vector>
#include <string>
#include "gameDef.h"
#include <cmath>

void collisionDetection(std::vector<planet> &planets) {
    for (int a = 0; a < planets.size(); a++) { //Nested for loop collision detection
        for (int b = 0; b < planets.size(); b++) {
            if (a != b) {
                const float distance = sqrt(pow(planets[b].getPosition().x - planets[a].getPosition().x, 2) + pow(planets[b].getPosition().y - planets[a].getPosition().y, 2));
                if (distance <= (planets[a].radius + planets[b].radius)) { // Planets have collided
                    
                    
                    if (planets[a].mass < planets[b].mass) { // first planet is smaller

                    }
                    else { // second planet is smaller

                    }
                    std::cout << "Collision" << std::endl;
                }
            }
        }
    }
}

//Main Function
int main()
{
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Gravity Simulation");
    window.setFramerateLimit(60);

    mode gamemode = none;

    bool mouselock = false;
    sf::CircleShape placePlanet;

    sf::Vector2f prevMousePos;

    placePlanet.setFillColor(sf::Color::Transparent);
    placePlanet.setOutlineThickness(1);
    placePlanet.setOutlineColor(sf::Color::Red);

    std::vector<planet> planets {};
    menu menubar = menu(sf::Vector2f(800, 0), sf::Vector2f(400, 800));
    
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }

        window.clear();

        sf::Vector2i pixelPos = sf::Mouse::getPosition(window);
        sf::Vector2f worldPos = window.mapPixelToCoords(pixelPos);

        if (menu::clearAll.isClicked(worldPos, sf::Mouse::isButtonPressed(sf::Mouse::Left))) {
            planets.clear();
        }
        
        for (int i = 0; i < planets.size(); i++) {
            for (int a = 0; a < planets.size(); a++) {
                if (a != i) {
                    planets[i].applyGravity(planets[a].getPosition(), planets[a].mass);
                }
            }
        }
        collisionDetection(planets);

        for (int i = 0; i < planets.size(); i++) {
            planets[i].render(window);
        }

        if (!(worldPos.x > menubar.getPosition().x && worldPos.y > menubar.getPosition().y
            && worldPos.x < menubar.getPosition().x + menubar.getSize().x && worldPos.y < menubar.getPosition().y + menubar.getSize().y)) {
            if (gamemode == place) {
                placePlanet.setRadius(menubar.radius.getValue());
                placePlanet.setPosition(worldPos.x - placePlanet.getRadius(), worldPos.y - placePlanet.getRadius());
                window.draw(placePlanet);

                if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !mouselock) {
                    planets.push_back(planet(sf::Vector2f(worldPos.x - menubar.radius.getValue(), worldPos.y - menubar.radius.getValue()), sf::Vector2f(menubar.velocityX.getValue(), menubar.velocityY.getValue()), menubar.radius.getValue()));
                }
            }
            else if (gamemode == move) {
                if (mouselock) {
                    float xDist = worldPos.x - prevMousePos.x;
                    float yDist = worldPos.y - prevMousePos.y;

                    for (int i = 0; i < planets.size(); i++) {
                        planets[i].movePosition(sf::Vector2f(xDist, yDist));
                    }
                }
                prevMousePos = worldPos;
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && !mouselock) {
            mouselock = true;
        }
        else if (!sf::Mouse::isButtonPressed(sf::Mouse::Left) && mouselock) {
            mouselock = false;
        }

        menubar.render(window, gamemode);
        window.display();
    }

    return 0;
}