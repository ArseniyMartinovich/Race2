#pragma once
#include "settings.h"
#include "SFML/Graphics.hpp"

struct Car {
	sf::Texture texture;
	sf::Sprite sprite;
	float speedx;
};

void carInit(Car& car, sf::Vector2f pos, std::string fileName) {
	car.texture.loadFromFile(fileName);
	car.sprite.setTexture(car.texture);
	car.sprite.setPosition(pos);
}

void carControl(Car& car) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		car.speedx = -CAR_SPEED;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		car.speedx = CAR_SPEED;
	car.sprite.move(car.speedx, 0.f);
	car.speedx = 0.f;
}

void carReboundEdges(Car& car) {
	float carx = car.sprite.getPosition().x;
	float cary = car.sprite.getPosition().y;
	if (carx <= 0) car.sprite.setPosition(0.f, cary);
	if (carx >= WINDOW_WIDTH - CAR_SPRITE)
		car.sprite.setPosition(WINDOW_WIDTH - CAR_SPRITE, cary);
}

void carUpdate(Car& car) {
	carControl(car);
	carReboundEdges(car);
}

void carDraw(sf::RenderWindow& window, const Car& car) {
	window.draw(car.sprite);
}