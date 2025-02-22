#include "cda.h"
#include "util.h"
#include <SFML/Graphics.hpp>

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

        drawLineCDA(window, {0, 4}, {4, 0}, {0, 20});
        drawLineCDA(window, {4, 0}, {8, 0}, {0, 20});
        drawLineCDA(window, {8, 0}, {20, 8}, {0, 20});
        drawLineCDA(window, {20, 8}, {20, 20}, {0, 20});
        drawLineCDA(window, {8, 12}, {20, 20}, {0, 20});
        drawLineCDA(window, {4, 12}, {8, 12}, {0, 20});
        drawLineCDA(window, {4, 12}, {0, 16}, {0, 20});
        drawLineCDA(window, {0, 4}, {0, 16}, {0, 20});
        drawLineCDA(window, {4, 0}, {4, 12}, {0, 20});
        drawLineCDA(window, {8, 0}, {8, 12}, {0, 20});
        drawLineCDA(window, {0, 16}, {20, 20}, {0, 20});

        window.display();
    }
}
