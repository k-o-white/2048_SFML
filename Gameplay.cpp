//
// Created by teena on 28.02.2023.
//

#include "Gameplay.h"
#include <iostream>
#include <ctime>

Gameplay::Gameplay()
{
    size = 4;
    field = new int*[size];
    for(int i = 0; i < size; ++i)
    {
        field[i] = new int[size];
        for (int j = 0; j < size; ++j)
            field[i][j] = 0;
    }
    std::srand(std::time(nullptr));
    int values[] = {2, 4};
    for (int i = 0; i < 2; ++i)
    {
        int y, x;
        do {
            y = std::rand() % size;
            x = std::rand() % size;
        } while (field[y][x] != 0);
        field[y][x] = values[std::rand() % 2];
    }

    empty.loadFromFile("..\\sprites\\empty.jpg");
    emptySprite = new sf::Sprite(empty);
    two.loadFromFile("..\\sprites\\2.jpg");
    twoSprite = new sf::Sprite(two);
    four.loadFromFile("..\\sprites\\4.jpg");
    fourSprite = new sf::Sprite(four);
    eight.loadFromFile("..\\sprites\\8.jpg");
    eightSprite = new sf::Sprite(eight);
    sixteen.loadFromFile("..\\sprites\\16.jpg");
    sixteenSprite = new sf::Sprite(sixteen);
    thirtyTwo.loadFromFile("..\\sprites\\32.jpg");
    thirtyTwoSprite = new sf::Sprite(thirtyTwo);
    sixtyFour.loadFromFile("..\\sprites\\64.jpg");
    sixtyFourSprite = new sf::Sprite(sixtyFour);
    oneHundredTwentyEight.loadFromFile("..\\sprites\\128.jpg");
    oneHundredTwentyEightSprite = new sf::Sprite(oneHundredTwentyEight);
    twoHundredFiftySix.loadFromFile("..\\sprites\\256.jpg");
    twoHundredFiftySixSprite = new sf::Sprite(twoHundredFiftySix);
    fiveHundredTwelve.loadFromFile("..\\sprites\\512.jpg");
    fiveHundredTwelveSprite = new sf::Sprite(fiveHundredTwelve);
    oneThousandTwentyFour.loadFromFile("..\\sprites\\1024.jpg");
    oneThousandTwentyFourSprite = new sf::Sprite(oneThousandTwentyFour);
    twoThousandFortyEight.loadFromFile("..\\sprites\\2048.jpg");
    twoThousandFortyEightSprite = new sf::Sprite(twoThousandFortyEight);
}

Gameplay::Gameplay(int _size) : size(_size)
{
    field = new int*[size];
    for(int i = 0; i < size; ++i)
    {
        field[i] = new int[size];
        for (int j = 0; j < size; ++j)
            field[i][j] = 0;
    }
    std::srand(std::time(nullptr));
    int values[] = {2, 4};
    for (int i = 0; i < 2; ++i)
    {
        int y, x;
        do {
            y = std::rand() % size;
            x = std::rand() % size;
        } while (field[y][x] != 0);
        field[y][x] = values[std::rand() % 2];
    }

    empty.loadFromFile("..\\sprites\\empty.png");
    emptySprite = new sf::Sprite(empty);
    two.loadFromFile("..\\sprites\\2.png");
    twoSprite = new sf::Sprite(two);
    four.loadFromFile("..\\sprites\\4.png");
    fourSprite = new sf::Sprite(four);
    eight.loadFromFile("..\\sprites\\8.png");
    eightSprite = new sf::Sprite(eight);
    sixteen.loadFromFile("..\\sprites\\16.png");
    sixteenSprite = new sf::Sprite(sixteen);
    thirtyTwo.loadFromFile("..\\sprites\\32.png");
    thirtyTwoSprite = new sf::Sprite(thirtyTwo);
    sixtyFour.loadFromFile("..\\sprites\\64.png");
    sixtyFourSprite = new sf::Sprite(sixtyFour);
    oneHundredTwentyEight.loadFromFile("..\\sprites\\128.png");
    oneHundredTwentyEightSprite = new sf::Sprite(oneHundredTwentyEight);
    twoHundredFiftySix.loadFromFile("..\\sprites\\256.png");
    twoHundredFiftySixSprite = new sf::Sprite(twoHundredFiftySix);
    fiveHundredTwelve.loadFromFile("..\\sprites\\512.png");
    fiveHundredTwelveSprite = new sf::Sprite(fiveHundredTwelve);
    oneThousandTwentyFour.loadFromFile("..\\sprites\\1024.png");
    oneThousandTwentyFourSprite = new sf::Sprite(oneThousandTwentyFour);
    twoThousandFortyEight.loadFromFile("..\\sprites\\2048.png");
    twoThousandFortyEightSprite = new sf::Sprite(twoThousandFortyEight);
}

Gameplay::~Gameplay()
{
    for (int i = size - 1; i >= 0; --i)
    {
        delete field[i];
        field[i] = nullptr;
    }
    delete field;
    field = nullptr;
    delete emptySprite;
    emptySprite = nullptr;
    delete twoSprite;
    twoSprite = nullptr;
    delete fourSprite;
    fourSprite = nullptr;
    delete eightSprite;
    eightSprite = nullptr;
    delete sixteenSprite;
    sixteenSprite = nullptr;
    delete thirtyTwoSprite;
    thirtyTwoSprite = nullptr;
    delete sixtyFourSprite;
    sixtyFourSprite = nullptr;
    delete oneHundredTwentyEightSprite;
    oneHundredTwentyEightSprite = nullptr;
    delete twoHundredFiftySixSprite;
    twoHundredFiftySixSprite = nullptr;
    delete fiveHundredTwelveSprite;
    fiveHundredTwelveSprite = nullptr;
    delete oneThousandTwentyFourSprite;
    oneThousandTwentyFourSprite = nullptr;
    delete twoThousandFortyEightSprite;
    twoThousandFortyEightSprite = nullptr;
}

void Gameplay::addNew()
{
    int values[] = {2, 4};
    int i, j;
    do {
        i = std::rand() % size;
        j = std::rand() % size;
    } while (field[i][j] != 0);
    field[i][j] = values[std::rand() % 2];
}

void Gameplay::moveLeft()
{
    bool changed = false;
    for (int j = 0; j < size; ++j)
    {
        int newValues[size];
        for (int k = 0; k < size; ++k)
            newValues[k] = 0;
        int newValuesCount = 0;
        for (int i = 0; i < size; ++i)
        {
            if (field[i][j] != 0)
            {
                bool match = false;
                for (int k = i + 1; k < size && !match; ++k)
                {
                    if (field[i][j] == field[k][j])
                    {
                        match = true;
                        newValues[newValuesCount] = field[i][j] * 2;
                        if (newValues[newValuesCount] == 2048)
                            winning = true;
                        score += newValues[newValuesCount];
                        i = k;
                    }
                    else if (field[i][j] != field[k][j] && field[k][j] != 0)
                        break;
                }
                if (!match)
                    newValues[newValuesCount] = field[i][j];
                ++newValuesCount;
            }
        }

        if (!changed)
        {
            for (int i = 0; i < size; ++i)
            {
                if (field[i][j] != newValues[i])
                    changed = true;
            }
        }

        for (int i = 0; i < size; ++i)
            field[i][j] = newValues[i];
    }
    if (changed)
        addNew();
}

void Gameplay::moveRight()
{
    bool changed = false;
    for (int j = 0; j < size; ++j)
    {
        int newValues[size];
        for (int k = 0; k < size; ++k)
            newValues[k] = 0;
        int newValuesCount = size - 1;
        for (int i = size - 1; i >= 0; --i)
        {
            if (field[i][j] != 0)
            {
                bool match = false;
                for (int k = i - 1; k >= 0 && !match; --k)
                {
                    if (field[i][j] == field[k][j])
                    {
                        match = true;
                        newValues[newValuesCount] = field[i][j] * 2;
                        if (newValues[newValuesCount] == 2048)
                            winning = true;
                        score += newValues[newValuesCount];
                        i = k;
                    }
                    else if (field[i][j] != field[k][j] && field[k][j] != 0)
                        break;
                }
                if (!match)
                    newValues[newValuesCount] = field[i][j];
                --newValuesCount;
            }
        }

        if (!changed)
        {
            for (int i = size - 1; i >= 0; --i)
            {
                if (field[i][j] != newValues[i])
                    changed = true;
            }
        }

        for (int i = size - 1; i >= 0; --i)
            field[i][j] = newValues[i];
    }

    if (changed)
        addNew();
}

void Gameplay::moveUp()
{
    bool changed = false;
    for (int i = 0; i < size; ++i)
    {
        int newValues[size];
        for (int k = 0; k < size; ++k)
            newValues[k] = 0;
        int newValuesCount = 0;

        for (int j = 0; j < size; ++j)
        {
            if (field[i][j] != 0)
            {
                bool match = false;
                for (int k = j + 1; k < size && !match; ++k)
                {
                    if (field[i][j] == field[i][k])
                    {
                        match = true;
                        newValues[newValuesCount] = field[i][j] * 2;
                        if (newValues[newValuesCount] == 2048)
                            winning = true;
                        score += newValues[newValuesCount];
                        j = k;
                    }
                    else if (field[i][j] != field[i][k] && field[i][k] != 0)
                        break;
                }
                if (!match)
                    newValues[newValuesCount] = field[i][j];
                ++newValuesCount;
            }
        }

        if (!changed)
        {
            for (int j = 0; j < size; ++j)
            {
                if (field[i][j] != newValues[j])
                    changed = true;
            }
        }

        for (int j = 0; j < size; ++j)
            field[i][j] = newValues[j];
    }

    if (changed)
        addNew();
}

void Gameplay::moveDown()
{
    bool changed = false;
    for (int i = 0; i < size; ++i)
    {
        int newValues[size];
        for (int k = 0; k < size; ++k)
            newValues[k] = 0;
        int newValuesCount = size - 1;
        for (int j = size - 1; j >= 0; --j)
        {
            if (field[i][j] != 0)
            {
                bool match = false;
                for (int k = j - 1; k >= 0 && !match; --k)
                {
                    if (field[i][j] == field[i][k])
                    {
                        match = true;
                        newValues[newValuesCount] = field[i][j] * 2;
                        if (newValues[newValuesCount] == 2048)
                            winning = true;
                        score += newValues[newValuesCount];
                        j = k;
                    }
                    else if (field[i][j] != field[i][k] && field[i][k] != 0)
                        break;
                }
                if (!match)
                    newValues[newValuesCount] = field[i][j];
                --newValuesCount;
            }
        }

        if (!changed)
        {
            for (int j = size - 1; j >= 0; --j)
            {
                if (field[i][j] != newValues[j])
                    changed = true;
            }
        }

        for (int j = size - 1; j >= 0; --j)
            field[i][j] = newValues[j];
    }

    if (changed)
        addNew();
}

void Gameplay::display(sf::RenderWindow &app, const int &cellSize)
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            switch (field[i][j])
            {
                case 0:
                    emptySprite->setPosition(i * cellSize, j * cellSize);
                    app.draw(*emptySprite);
                    break;
                case 2:
                    twoSprite->setPosition(i * cellSize, j * cellSize);
                    app.draw(*twoSprite);
                    break;
                case 4:
                    fourSprite->setPosition(i * cellSize, j * cellSize);
                    app.draw(*fourSprite);
                    break;
                case 8:
                    eightSprite->setPosition(i * cellSize, j * cellSize);
                    app.draw(*eightSprite);
                    break;
                case 16:
                    sixteenSprite->setPosition(i * cellSize, j * cellSize);
                    app.draw(*sixteenSprite);
                    break;
                case 32:
                    thirtyTwoSprite->setPosition(i * cellSize, j * cellSize);
                    app.draw(*thirtyTwoSprite);
                    break;
                case 64:
                    sixtyFourSprite->setPosition(i * cellSize, j * cellSize);
                    app.draw(*sixtyFourSprite);
                    break;
                case 128:
                    oneHundredTwentyEightSprite->setPosition(i * cellSize, j * cellSize);
                    app.draw(*oneHundredTwentyEightSprite);
                    break;
                case 256:
                    twoHundredFiftySixSprite->setPosition(i * cellSize, j * cellSize);
                    app.draw(*twoHundredFiftySixSprite);
                    break;
                case 512:
                    fiveHundredTwelveSprite->setPosition(i * cellSize, j * cellSize);
                    app.draw(*fiveHundredTwelveSprite);
                    break;
                case 1024:
                    oneThousandTwentyFourSprite->setPosition(i * cellSize, j * cellSize);
                    app.draw(*oneThousandTwentyFourSprite);
                    break;
                case 2048:
                    twoThousandFortyEightSprite->setPosition(i * cellSize, j * cellSize);
                    app.draw(*twoThousandFortyEightSprite);
                    break;
            }
        }
    }
}

bool Gameplay::canMoveUp() const
{
    for (int j = 0; j < size; ++j)
    {
        for (int i = 0; i < size - 1; ++i)
        {
            if (field[i][j] == 0 || field[i][j] == field [i + 1][j] || field[i + 1][j] == 0)
                return true;
        }
    }
    return false;
}

bool Gameplay::canMoveDown() const
{
    for (int j = 0; j < size; ++j)
    {
        for (int i = size - 1; i > 0; --i)
        {
            if (field[i][j] == 0 || field[i][j] == field [i - 1][j] || field[i - 1][j] == 0)
                return true;
        }
    }
    return false;
}

bool Gameplay::canMoveLeft() const
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size - 1; ++j)
        {
            if (field[i][j] == 0 || field[i][j] == field [i][j + 1] || field[i][j + 1] == 0)
                return true;
        }
    }
    return false;
}

bool Gameplay::canMoveRight() const
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = size - 1; j > 0; --j)
        {
            if (field[i][j] == 0 || field[i][j] == field [i][j - 1] || field[i][j - 1] == 0)
                return true;
        }
    }
    return false;
}

bool Gameplay::isGameOver() const
{
    return !canMoveUp() && !canMoveDown() && !canMoveLeft() && !canMoveRight();
}

bool Gameplay::isPlayerWon() const
{
    return winning;
}
