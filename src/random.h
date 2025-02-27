#ifndef RANDOM_H
#define RANDOM_H

#include <SFML/Graphics.hpp>

std::vector<sf::Vector2f> getRandomLine(sf::Vector2f start, sf::Vector2f end, sf::Vector2f offset = {0, 0});

void drawRandomLine(sf::RenderWindow& window, std::vector<sf::Vector2f> line);

#endif
