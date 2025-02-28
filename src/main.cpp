#include "bresenham.h"
#include "random.h"
#include "bresenham.h"
#include "cda.h"
#include "util.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode({800, 600}), "My window");
    bool wasEnterPressed = false;
    std::vector<sf::Vector2f> randomLine = getRandomLine({0, 0}, {50, 30});

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window.close();
            }
            else if (const auto* keyReleased = event->getIf<sf::Event::KeyReleased>())
            {
              if (keyReleased->code == sf::Keyboard::Key::Enter)
              {
                randomLine = getRandomLine({0, 0}, {50, 30});
              }
            }
        }

        window.clear(sf::Color::White);

        drawGrid(window);
        drawSeparators(window);

        float scale = 4.0;
        drawShapeCDA(window, {5, 35}, scale);
        drawShapeBresenham(window, {45, 35}, scale);
        drawRandomLine(window, randomLine);

        window.display();
    }
}
