#include "bresenham.h"
#include "util.h"

void drawLineBresenham(sf::RenderWindow& window, sf::Vector2f start, sf::Vector2f end, sf::Vector2f offset, float scale)
{
  start.x *= scale;
  start.y *= scale;
  end.x *= scale;
  end.y *= scale;

  start.x += offset.x;
  start.y += offset.y;
  end.x += offset.x;
  end.y += offset.y;

  bool steep = abs(end.y - start.y) > abs(end.x - start.x);
  if (steep)
  {
    std::swap(start.x, start.y);
    std::swap(end.x, end.y);
  }
  if (start.x > end.x)
  {
    std::swap(start, end);
  }

  int dx = end.x - start.x;
  int dy = std::abs(end.y - start.y);

  int error = 0;
  int deltaerr = dy + 1;

  int y = start.y;
  int diry = (start.y < end.y) ? 1 : -1;

  for (int x = start.x; x <= end.x; x++)
  {
    sf::Vector2i pseudoPosition = toScreen(window, pseudoToReal({steep ? (float)y : (float)x, steep ? (float)x : (float)y}));
    drawPseudoPixel(window, pseudoPosition);

    error += deltaerr;

    if (error > (dx + 1)) 
    {
      y += diry;
      error -= (dx + 1);
    }
  }
}

void drawShapeBresenham(sf::RenderWindow& window, sf::Vector2f offset, float scale)
{
  drawLineBresenham(window, {0, 1}, {1, 0}, offset, scale);
  drawLineBresenham(window, {1, 0}, {2, 0}, offset, scale);
  drawLineBresenham(window, {2, 0}, {5, 2}, offset, scale);
  drawLineBresenham(window, {5, 2}, {5, 5}, offset, scale);
  drawLineBresenham(window, {2, 3}, {5, 5}, offset, scale);
  drawLineBresenham(window, {1, 3}, {2, 3}, offset, scale);
  drawLineBresenham(window, {1, 3}, {0, 4}, offset, scale);
  drawLineBresenham(window, {0, 1}, {0, 4}, offset, scale);
  drawLineBresenham(window, {1, 0}, {1, 3}, offset, scale);
  drawLineBresenham(window, {2, 0}, {2, 3}, offset, scale);
  drawLineBresenham(window, {0, 4}, {5, 5}, offset, scale);
}
