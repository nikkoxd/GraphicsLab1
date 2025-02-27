#include "random.h"
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

        float scale = 4.0;
        sf::Vector2f offset = {5, 35};
        drawLineCDA(window, {0, 1}, {1, 0}, offset, scale);
        drawLineCDA(window, {1, 0}, {2, 0}, offset, scale);
        drawLineCDA(window, {2, 0}, {5, 2}, offset, scale);
        drawLineCDA(window, {5, 2}, {5, 5}, offset, scale);
        drawLineCDA(window, {2, 3}, {5, 5}, offset, scale);
        drawLineCDA(window, {1, 3}, {2, 3}, offset, scale);
        drawLineCDA(window, {1, 3}, {0, 4}, offset, scale);
        drawLineCDA(window, {0, 1}, {0, 4}, offset, scale);
        drawLineCDA(window, {1, 0}, {1, 3}, offset, scale);
        drawLineCDA(window, {2, 0}, {2, 3}, offset, scale);
        drawLineCDA(window, {0, 4}, {5, 5}, offset, scale);

        drawLineCDA(window, {-1, 0}, {(float)window.getSize().x, 0}, {0, 30});
        drawLineCDA(window, {0, 30}, {0, (float)window.getSize().y}, {35, 0});
        
        drawLineCDA(window, randomLine[0], randomLine[1]);

        window.display();
    }
}
