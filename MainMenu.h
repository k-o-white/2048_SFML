//
// Created by teena on 31.05.2023.
//

#pragma once
#include "SFML/Graphics.hpp"

enum scenes {MENU = 0, GAME, RECORDS};

class MainMenu
{
private:
    sf::Font menuFont;
    sf::Text logo;
    sf::Text menuText;
public:
    MainMenu();

    ~MainMenu() = default;

    void displayMenu(sf::RenderWindow &window, scenes &scene);
};
