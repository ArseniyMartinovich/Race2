#pragma once
#include "SFML/Graphics.hpp"

const float WINDOW_WIDTH = 800.f;
const float WINDOW_HEIGHT = 1000.f;
const std::string WINDOW_TITLE = "SFML Race";
const float FPS = 60.f;

const sf::Vector2f GRASS_POS{ 0.f, 0.f };
const sf::Vector2f SEND_POS{ 50.f, 0.f };
const sf::Vector2f ROAD_POS{ 100.f, 0.f };

const float ROAD_LAYER_SPEED = 2.f;

const float CAR_SPEED = 2.f;
const float CAR_SPRITE = (70, 68);
const sf::Vector2f CAR_POS{ 275, 70 }
