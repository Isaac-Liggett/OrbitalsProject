#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "planet.h"

sf::Color linearColorGradient(sf::Color c1, sf::Color c2, float range) {
	float r_size = c2.r - c1.r;
	float g_size = c2.g - c1.g;
	float b_size = c2.b - c1.b;

	return sf::Color(c1.r + (r_size * range), c1.g + (g_size * range), c1.b + (b_size * range), 255);
}

planet::planet(sf::Vector2f pos, sf::Vector2f vel, float r) : position{ pos }, velocity{ vel }, radius{ r } {
	volume = 3.1415 * pow(radius, 2);
	mass = volume * density;

	// volume = mass / density -> radius = sqrt(mass / (density * 3.1415))

	c.setPosition(pos);
	c.setRadius(radius);
	c.setFillColor(linearColorGradient(sf::Color::Blue, sf::Color::Red, r/150.f));
}

void planet::render(sf::RenderWindow& window) {
	applyVelocity();
	window.draw(c);
}

sf::Vector2f planet::getPosition() {
	return position;
}

sf::Vector2f planet::getMomentum() {
	float momentum = planet::mass * sqrt(pow(planet::velocity.x, 2) + pow(planet::velocity.y, 2));
	//Need to return a value
	return sf::Vector2f(2.f, 2.f);
}

void planet::movePosition(sf::Vector2f delta) {
	position.x += delta.x;
	position.y += delta.y;
}

void planet::applyGravity(sf::Vector2f planet2, float p2mass) {
	float distance = sqrt(pow(planet2.x - position.x, 2) + pow(planet2.y - position.y, 2));
	float g_strength = ((6.67 * pow(10, -11)) * mass * p2mass) / pow(distance, 2);

	const float relDistX = planet2.x - position.x;
	const float relDistY = planet2.y - position.y;

	float invDist = 1.f / distance;
	float normalXDist = invDist * relDistX;
	float normalYDist = invDist * relDistY;

	float gforceX = normalXDist * g_strength;
	float gforceY = normalYDist * g_strength;

	acceleration.x = gforceX / mass;
	acceleration.y = gforceY / mass;
}

void planet::applyVelocity() {
	velocity.x += acceleration.x;
	velocity.y += acceleration.y;
	position.x += velocity.x;
	position.y += velocity.y;
	acceleration.x = 0;
	acceleration.y = 0;

	c.setPosition(position.x, position.y);
}