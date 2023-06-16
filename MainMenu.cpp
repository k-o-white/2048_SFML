//
// Created by teena on 31.05.2023.
//

#include "MainMenu.h"

MainMenu::MainMenu()
{
    menuFont.loadFromFile(".\\resources\\HighlandGothicFLF.ttf");
    logo = sf::Text("2048", menuFont, 180);
    logo.setStyle(sf::Text::Bold);
    logo.setColor(sf::Color::Red);
    menuText = sf::Text("Press Enter to start", menuFont, 50);
    menuText.setStyle(sf::Text::Bold);
    menuText.setColor(sf::Color::Black);
}

void MainMenu::displayMenu(sf::RenderWindow &window, scenes &scene)
{
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::KeyPressed)
        {
            switch (event.key.code)
            {
                case sf::Keyboard::Enter:
                    scene = GAME;
                    break;
                case sf::Keyboard::Escape:
                    window.close();
                    break;
            }
        }
        else if (event.type == sf::Event::Closed)
            window.close();
    }
    window.clear(sf::Color(255, 218, 185, 0));
    logo.setPosition(45, 90);
    menuText.setPosition(65, 370);
    window.draw(logo);
    window.draw(menuText);
    window.display();
}

