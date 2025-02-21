#include <SFML/Graphics.hpp>
#include "defines.h"

sf::Vector2i toScreen(sf::RenderWindow& window, sf::Vector2i pixel)
{
  return sf::Vector2i{pixel.x + offset, int(window.getSize().y) - pixel.y - offset};
}

sf::Vector2i pseudoToReal(sf::Vector2f pixel)
{
  return sf::Vector2i{int(pixel.x) * pixel_size, int(pixel.y) * pixel_size};
}

void drawPseudoPixel(sf::RenderWindow& window, sf::Vector2i origin)
{
  sf::Vector2i end{origin.x + pixel_size, origin.y + pixel_size};
  sf::Vector2f current{float(origin.x), float(origin.y)};

  while (current.y <= end.y)
  {
    while (current.x <= end.x)
    {
      sf::Vertex point{current, sf::Color::Black};
      window.draw(&point, 1, sf::PrimitiveType::Points);

      current.x += 0.1;
    }
    current.x = float(origin.x);
    current.y += 0.1;
  }
}

void drawGrid(sf::RenderWindow& window)
{
  for (float i = 0; i < window.getSize().x; i += 1)
  {
    for (float j = 0; j < window.getSize().y; j += 1)
    {
      if (int(i) % pixel_size == 0 || int(j) % pixel_size == 0)
      {
        sf::Vertex point{sf::Vector2f{i, j}, sf::Color::Black};
        window.draw(&point, 1, sf::PrimitiveType::Points);
      }
    }
  }
}
