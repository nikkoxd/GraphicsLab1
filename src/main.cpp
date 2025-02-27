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

        sf::Vector2f offset = {5, 35};
        drawLineCDA(window, {0, 4}, {4, 0}, offset);
        drawLineCDA(window, {4, 0}, {8, 0}, offset);
        drawLineCDA(window, {8, 0}, {20, 8}, offset);
        drawLineCDA(window, {20, 8}, {20, 20}, offset);
        drawLineCDA(window, {8, 12}, {20, 20}, offset);
        drawLineCDA(window, {4, 12}, {8, 12}, offset);
        drawLineCDA(window, {4, 12}, {0, 16}, offset);
        drawLineCDA(window, {0, 4}, {0, 16}, offset);
        drawLineCDA(window, {4, 0}, {4, 12}, offset);
        drawLineCDA(window, {8, 0}, {8, 12}, offset);
        drawLineCDA(window, {0, 16}, {20, 20}, offset);

        drawLineCDA(window, {-1, 0}, {(float)window.getSize().x, 0}, {0, 30});
        drawLineCDA(window, {0, 30}, {0, (float)window.getSize().y}, {35, 0});

        window.display();
    }
}
