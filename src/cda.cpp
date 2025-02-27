#include "cda.h"
#include "util.h"

void drawLineCDA(sf::RenderWindow& window, sf::Vector2f start, sf::Vector2f end, sf::Vector2f offset, float scale)
{
  start.x *= scale;
  start.y *= scale;
  end.x *= scale;
  end.y *= scale;

  start.x += offset.x;
  start.y += offset.y;
  end.x += offset.x;
  end.y += offset.y;

  sf::Vector2f position = start;

  float dx = (int)end.x - (int)start.x;
  float dy = (int)end.y - (int)start.y;

  int l = std::abs(dx) > std::abs(dy) ? std::abs(dx) : std::abs(dy);

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
