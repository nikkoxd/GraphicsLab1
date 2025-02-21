#include "util.cpp"

void drawLineCDA(sf::RenderWindow& window, sf::Vector2f start, sf::Vector2f end)
{
  sf::Vector2f position = start;

  float dx = end.x - start.x;
  float dy = end.y - start.y;

  int l = dx > dy ? dx : dy;

  dx = dx / l;
  dy = dy / l;

  for (int i = 0; i <= l; i++)
  {
    sf::Vector2i pseudoPosition = toScreen(window, pseudoToReal(position));
    drawPseudoPixel(window, pseudoPosition);

    position.x += dx;
    position.y += dy;
  }
}
