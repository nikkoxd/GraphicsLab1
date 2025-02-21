#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/PrimitiveType.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Vertex.hpp>
#include <SFML/System/Vector2.hpp>

#define offset 10
#define pixel_size 10

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

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "My window");

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.clear(sf::Color::White);

        drawGrid(window);

        drawLineCDA(window, {0, 4}, {4, 0});
        drawLineCDA(window, {4, 0}, {8, 0});
        drawLineCDA(window, {8, 0}, {20, 8});
        drawLineCDA(window, {20, 8}, {20, 20});
        drawLineCDA(window, {8, 12}, {20, 20});
        drawLineCDA(window, {4, 12}, {8, 12});
        drawLineCDA(window, {4, 12}, {0, 16});
        drawLineCDA(window, {0, 4}, {0, 16});
        drawLineCDA(window, {4, 0}, {4, 12});
        drawLineCDA(window, {8, 0}, {8, 12});
        drawLineCDA(window, {0, 16}, {20, 20});

        window.display();
    }
}
