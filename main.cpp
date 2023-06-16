#include "SFML/Graphics.hpp"
#include "Gameplay.h"

int main()
{
    const unsigned int cellSize = 160;
    const unsigned int arraySize = 4;
    const unsigned int windowWidth = 680;
    const unsigned int windowHeight = 780;

    sf::RenderWindow app(sf::VideoMode(windowWidth, windowHeight), "2048", sf::Style::Close);
    auto image = sf::Image{};
    if (!image.loadFromFile(".\\resources\\2048.png"))
    {
        return 0;
    }
    app.setIcon(image.getSize().x, image.getSize().y, image.getPixelsPtr());
    app.setFramerateLimit(60);
    scenes currentScene = MENU;
    while (app.isOpen())
    {
        if (currentScene == MENU)
        {
            auto* menu = new MainMenu();
            while (currentScene == MENU && app.isOpen())
                menu->displayMenu(app, currentScene);
            delete menu;
            menu = nullptr;
        }
        else if (currentScene == GAME)
        {
            auto* game = new Gameplay();
            while (currentScene == GAME && app.isOpen())
                game->displayGame(app, cellSize, currentScene);
            delete game;
            game = nullptr;
        }
        else
            app.close();
    }
    return 0;
}
