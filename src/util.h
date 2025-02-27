#ifndef UTIL_H
#define UTIL_H

#include <SFML/Graphics.hpp>

sf::Vector2i toScreen(sf::RenderWindow& window, sf::Vector2i pixel);
sf::Vector2i pseudoToReal(sf::Vector2f pixel);
void drawPseudoPixel(sf::RenderWindow& window, sf::Vector2i origin);
void drawGrid(sf::RenderWindow& window);
void drawSeparators(sf::RenderWindow& window);

#endif
