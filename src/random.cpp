#include "bresenham.h"
#include "random.h"
#include <random>

std::vector<sf::Vector2f> getRandomLine(sf::Vector2f start, sf::Vector2f end, sf::Vector2f offset)
{
  start.x += offset.x;
  start.y += offset.y;
  end.x += offset.x;
  end.y += offset.y;

  std::random_device rd;
  std::mt19937 gen(rd());

  std::uniform_int_distribution<std::mt19937::result_type> dis_x(start.x, end.x);
  std::uniform_int_distribution<std::mt19937::result_type> dis_y(start.y, end.y);

  sf::Vector2f start_point{(float)dis_x(gen), (float)dis_y(gen)};
  sf::Vector2f end_point{(float)dis_x(gen), (float)dis_y(gen)};

  return {start_point, end_point};
}

void drawRandomLine(sf::RenderWindow& window, std::vector<sf::Vector2f> line)
{
  drawLineBresenham(window, line[0], line[1]);
}
