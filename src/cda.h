#ifndef CDA_H
#define CDA_H

#include <SFML/Graphics.hpp>

void drawLineCDA(sf::RenderWindow& window, sf::Vector2f start, sf::Vector2f end, sf::Vector2f offset = {0, 0}, float scale = 1.0);
void drawShapeCDA(sf::RenderWindow& window, sf::Vector2f offset = {0, 0}, float scale = 1.0);

#endif
