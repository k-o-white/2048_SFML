#include "Gameplay.h"
#include "SFML/Graphics.hpp"

int main()
{
    const int cellSize = 80;
    const int arraySize = 4;

    Gameplay game(arraySize);

    sf::RenderWindow app
        (sf::VideoMode(arraySize * cellSize, arraySize * cellSize), "2048");

    while (app.isOpen())
    {
        sf::Event event;
        while (app.pollEvent(event))
        {
            if (event.type == sf::Event::KeyPressed && !game.isPlayerWon() && !game.isGameOver())
            {
                switch (event.key.code)
                {
                    case sf::Keyboard::A:
                        game.moveLeft();
                        break;
                    case sf::Keyboard::D:
                        game.moveRight();
                        break;
                    case sf::Keyboard::W:
                        game.moveUp();
                        break;
                    case sf::Keyboard::S:
                        game.moveDown();
                        break;
                    case sf::Keyboard::Left:
                        game.moveLeft();
                        break;
                    case sf::Keyboard::Right:
                        game.moveRight();
                        break;
                    case sf::Keyboard::Up:
                        game.moveUp();
                        break;
                    case sf::Keyboard::Down:
                        game.moveDown();
                        break;
                }
            }
            else if (event.type == sf::Event::Closed)
                app.close();
        }

        app.clear();
        game.display(app, cellSize);
        app.display();
    }
    return 0;
}
