//
// Created by teena on 28.02.2023.
//

#pragma once
#include "SFML/Graphics.hpp"

class Gameplay
{
private:
    int **field = nullptr;
    int size;
    bool winning = false;
    int score = 0;
    sf::Texture empty;
    sf::Texture two;
    sf::Texture four;
    sf::Texture eight;
    sf::Texture sixteen;
    sf::Texture thirtyTwo;
    sf::Texture sixtyFour;
    sf::Texture oneHundredTwentyEight;
    sf::Texture twoHundredFiftySix;
    sf::Texture fiveHundredTwelve;
    sf::Texture oneThousandTwentyFour;
    sf::Texture twoThousandFortyEight;

    sf::Sprite* emptySprite = nullptr;
    sf::Sprite* twoSprite = nullptr;
    sf::Sprite* fourSprite = nullptr;
    sf::Sprite* eightSprite = nullptr;
    sf::Sprite* sixteenSprite = nullptr;
    sf::Sprite* thirtyTwoSprite = nullptr;
    sf::Sprite* sixtyFourSprite = nullptr;
    sf::Sprite* oneHundredTwentyEightSprite = nullptr;
    sf::Sprite* twoHundredFiftySixSprite = nullptr;
    sf::Sprite* fiveHundredTwelveSprite = nullptr;
    sf::Sprite* oneThousandTwentyFourSprite = nullptr;
    sf::Sprite* twoThousandFortyEightSprite = nullptr;
public:
    Gameplay();

    Gameplay(int _size);

    ~Gameplay();

    void addNew();

    void moveUp();

    void moveDown();

    void moveLeft();

    void moveRight();

    void display(sf::RenderWindow &app, const int &cellSize);

    bool canMoveUp() const;

    bool canMoveDown() const;

    bool canMoveLeft() const;

    bool canMoveRight() const;

    bool isGameOver() const;

    bool isPlayerWon() const;
};
