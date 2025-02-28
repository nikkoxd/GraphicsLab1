#ifndef BREZENHAM_H
#define BREZENHAM_H

#include <SFML/Graphics.hpp>

void drawLineBresenham(sf::RenderWindow& window, sf::Vector2f start, sf::Vector2f end, sf::Vector2f offset = {0, 0}, float scale = 1.0);

void drawShapeBresenham(sf::RenderWindow& window, sf::Vector2f offset = {0, 0}, float scale = 1.0);

#endif
