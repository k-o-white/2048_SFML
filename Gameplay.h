//
// Created by teena on 28.02.2023.
//

#pragma once
#include <fstream>
#include <array>
#include "SFML/Graphics.hpp"
#include "MainMenu.h"

class Gameplay
{
private:
    int **field = nullptr;
    std::array<std::array<sf::RectangleShape, 4>, 4> tiles;
    std::array<std::array<sf::Text, 4>, 4> tileValues;
    int size;
    bool winning = false;
    bool first2048 = false;
    int score = 0;
    int highScore = 0;
    sf::Font font;
    sf::Font numbersFont;
    sf::RectangleShape background;
    sf::Text scoreText;
    sf::Text highScoreText;
    sf::Text startNewGameText;

    void startNewGame();
public:
    Gameplay();

    ~Gameplay();

    void addNew();

    void moveUp();

    void moveDown();

    void moveLeft();

    void moveRight();

    void drawGame(sf::RenderWindow &app, const int &cellSize);

    bool canMoveUp() const;

    bool canMoveDown() const;

    bool canMoveLeft() const;

    bool canMoveRight() const;

    bool isGameOver() const;

    bool isPlayerWon() const;

    void displayGame(sf::RenderWindow &w, const int &cellsize, scenes &scene);
};
