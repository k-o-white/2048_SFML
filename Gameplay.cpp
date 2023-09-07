//
// Created by teena on 28.02.2023.
//

#include "Gameplay.h"
#include <iostream>
#include <cmath>

void Gameplay::startNewGame()
{
    this->score = 0;
    this->first2048 = false;
    for(int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
            this->field[i][j] = 0;
    }
    for (int i = 0; i < 2; ++i)
        this->addNew();
}

Gameplay::Gameplay()
{
    this->size = 4;
    this->field = new int*[this->size];
    for(int i = 0; i < this->size; ++i)
        field[i] = new int[this->size];
    this->startNewGame();
    this->font.loadFromFile(".\\resources\\HighlandGothicFLF.ttf");
    this->numbersFont.loadFromFile(".\\resources\\HighlandGothicFLF.ttf");
    background = sf::RectangleShape(sf::Vector2f(640.f, 640.f));
    background.setPosition(20, 20);
    background.setOutlineThickness(5.f);
    background.setFillColor(sf::Color(173, 157, 143));
    background.setOutlineColor(sf::Color(173, 157, 143));
    scoreText = sf::Text("", font, 20);
    scoreText.setStyle(sf::Text::Bold);
    highScoreText = sf::Text("", font, 20);
    highScoreText.setStyle(sf::Text::Bold);
    startNewGameText = sf::Text("[Space] - Restart", font, 20);
    startNewGameText.setStyle(sf::Text::Bold);
    for (int i = 0; i < this->size; ++i)
    {
        for (int j = 0; j < this->size; ++j)
        {
            this->tiles[i][j] = sf::RectangleShape(sf::Vector2f(160.f, 160.f));
            this->tiles[i][j].setFillColor(sf::Color(255, 255, 255));
            this->tiles[i][j].setOutlineThickness(-5.f);
            this->tiles[i][j].setOutlineColor(sf::Color(173, 157, 143));
            this->tileValues[i][j] = sf::Text("", numbersFont, 40);
            this->tileValues[i][j].setStyle(sf::Text::Bold);
        }
    }
    std::ifstream loadHighScore(".\\resources\\high_score.bin", std::ios::binary);
    if (loadHighScore.is_open())
        loadHighScore.read((char*)&this->highScore, sizeof(this->highScore));
    else
        this->highScore = 0;
    loadHighScore.close();
}

Gameplay::~Gameplay()
{
    std::ofstream loadHighScore(".\\resources\\high_score.bin", std::ios::binary);
    loadHighScore.write((char*)&this->highScore, sizeof(this->highScore));
    loadHighScore.close();
    for (int i = size - 1; i >= 0; --i)
    {
        delete field[i];
        field[i] = nullptr;
    }
    delete field;
    field = nullptr;
}

void Gameplay::addNew()
{
    int values[] = {2, 2, 2, 2, 2, 2, 2, 2, 2, 4};
    int i, j;
    do {
        i = std::rand() % size;
        j = std::rand() % size;
    } while (field[i][j] != 0);
    field[i][j] = values[std::rand() % std::size(values)];
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
                        if (newValues[newValuesCount] == 2048 && !first2048)
                        {
                            winning = true;
                            first2048 = true;
                        }
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
    if (score > highScore)
        highScore = score;
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
                        if (newValues[newValuesCount] == 2048 && !first2048)
                        {
                            winning = true;
                            first2048 = true;
                        }
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
    if (score > highScore)
        highScore = score;
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
                        if (newValues[newValuesCount] == 2048 && !first2048)
                        {
                            winning = true;
                            first2048 = true;
                        }
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
    if (score > highScore)
        highScore = score;
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
                        if (newValues[newValuesCount] == 2048 && !first2048)
                        {
                            winning = true;
                            first2048 = true;
                        }
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
    if (score > highScore)
        highScore = score;
}

void Gameplay::drawGame(sf::RenderWindow &app, const int &cellSize)
{
    app.draw(background);
    int i, j;
    for (i = 0; i < size; ++i)
    {
        for (j = 0; j < size; ++j)
        {
            switch (field[i][j])
            {
                case 0:
                    tiles[i][j].setFillColor(sf::Color(193, 179, 164));
                    break;
                case 2:
                    tiles[i][j].setFillColor(sf::Color(238, 224, 218));
                    break;
                case 4:
                    tiles[i][j].setFillColor(sf::Color(237,224,200));
                    break;
                case 8:
                    tiles[i][j].setFillColor(sf::Color(242,177,121));
                    break;
                case 16:
                    tiles[i][j].setFillColor(sf::Color(245,149,99));
                    break;
                case 32:
                    tiles[i][j].setFillColor(sf::Color(246,124,96));
                    break;
                case 64:
                    tiles[i][j].setFillColor(sf::Color(246,94,56));
                    break;
                case 128:
                    tiles[i][j].setFillColor(sf::Color(237,207,115));
                    break;
                case 256:
                    tiles[i][j].setFillColor(sf::Color(237,204,98));
                    break;
                case 512:
                    tiles[i][j].setFillColor(sf::Color(237,200,80));
                    break;
                case 1024:
                    tiles[i][j].setFillColor(sf::Color(237,197,63));
                    break;
                case 2048:
                    tiles[i][j].setFillColor(sf::Color(237,194,45));
                    break;
                default:
                    tiles[i][j].setFillColor(sf::Color(125,216,15));
            }
            tiles[i][j].setPosition(i * cellSize + 20, j * cellSize + 20);
            app.draw(tiles[i][j]);
            if (field[i][j] > 0)
            {
                sf::FloatRect textRect = tileValues[i][j].getLocalBounds();
                tileValues[i][j].setOrigin(textRect.width/2.f,textRect.height/2.f);
                tileValues[i][j].setPosition(tiles[i][j].getPosition() + (tiles[i][j].getSize() / 2.f));
                if (field[i][j] <= 4)
                    tileValues[i][j].setColor(sf::Color(97, 90, 84));
                else
                    tileValues[i][j].setColor(sf::Color::White);
                std::string tileValueText;
                if (field[i][j] > int(pow(2, 16)))
                {
                    tileValueText = "2**" + std::to_string(int(log2(double(field[i][j]))));
                    tileValues[i][j].setCharacterSize(40);
                }
                else
                {
                    tileValueText = std::to_string(field[i][j]);
                    switch (tileValueText.length())
                    {
                        case 1:
                            tileValues[i][j].setCharacterSize(65);
                            break;
                        case 2:
                            tileValues[i][j].setCharacterSize(55);
                            break;
                        case 3:
                            tileValues[i][j].setCharacterSize(50);
                            break;
                        case 4:
                            tileValues[i][j].setCharacterSize(40);
                            break;
                        default:
                            tileValues[i][j].setCharacterSize(30);
                    }
                }
                tileValues[i][j].setString(tileValueText);
                app.draw(tileValues[i][j]);
            }
        }
    }
    std::string scoreString = std::to_string(this->score);
    scoreText.setColor(sf::Color::Black);
    scoreText.setString("Score: " + scoreString);
    scoreText.setPosition(30, 690);
    std::string highScoreString = std::to_string(this->highScore);
    highScoreText.setColor(sf::Color::Black);
    highScoreText.setString("High score: " + highScoreString);
    highScoreText.setPosition(30, 720);
    startNewGameText.setColor(sf::Color::Black);
    startNewGameText.setPosition(450, 690);
    app.draw(scoreText);
    app.draw(highScoreText);
    app.draw(startNewGameText);
    if (this->isGameOver())
    {
        sf::Text gameOverText("GAME OVER!", font, 80);
        gameOverText.setColor(sf::Color::Red);
        gameOverText.setStyle(sf::Text::Bold);
        gameOverText.setOutlineThickness(5.f);
        gameOverText.setOutlineColor(sf::Color::White);
        sf::FloatRect textRect = gameOverText.getGlobalBounds();
        gameOverText.setOrigin(textRect.width/2.f,textRect.height/2.f);
        gameOverText.setPosition(background.getPosition() + (background.getSize() / 2.f));
        app.draw(gameOverText);
    }
    if (this->isPlayerWon())
    {
        sf::Text winText("YOU WIN!", font, 80);
        winText.setColor(sf::Color::Green);
        winText.setStyle(sf::Text::Bold);
        winText.setOutlineThickness(5.f);
        winText.setOutlineColor(sf::Color::White);
        sf::FloatRect textRect = winText.getGlobalBounds();
        winText.setOrigin(textRect.width/2.f,textRect.height/2.f);
        winText.setPosition(background.getPosition() + (background.getSize() / 2.f));
        app.draw(winText);
        sf::Text keepGoingText("[Enter] - Keep going", font, 20);
        keepGoingText.setColor(sf::Color::Black);
        keepGoingText.setStyle(sf::Text::Bold);
        keepGoingText.setPosition(425, 720);
        app.draw(keepGoingText);
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

void Gameplay::displayGame(sf::RenderWindow &w, const int &cellsize, scenes &scene)
{
    sf::Event event;
    while (w.pollEvent(event))
    {
        if (event.type == sf::Event::KeyPressed && !this->isPlayerWon() && !this->isGameOver())
        {
            switch (event.key.code)
            {
                case sf::Keyboard::A:
                    this->moveLeft();
                    break;
                case sf::Keyboard::D:
                    this->moveRight();
                    break;
                case sf::Keyboard::W:
                    this->moveUp();
                    break;
                case sf::Keyboard::S:
                    this->moveDown();
                    break;
                case sf::Keyboard::Left:
                    this->moveLeft();
                    break;
                case sf::Keyboard::Right:
                    this->moveRight();
                    break;
                case sf::Keyboard::Up:
                    this->moveUp();
                    break;
                case sf::Keyboard::Down:
                    this->moveDown();
                    break;
                case sf::Keyboard::Space:
                    this->startNewGame();
                    break;
            }
        }
        else if (this->isPlayerWon() && event.type == sf::Event::KeyPressed)
        {
            switch (event.key.code)
            {
                case sf::Keyboard::Enter:
                    winning = false;
                    break;
                case sf::Keyboard::Space:
                    this->startNewGame();
                    break;
                case sf::Keyboard::Escape:
                    w.close();
                    break;
            }
        }
        else if (this->isGameOver() && event.type == sf::Event::KeyPressed)
        {
            switch (event.key.code)
            {
                case sf::Keyboard::Space:
                    this->startNewGame();
                    break;
                case sf::Keyboard::Escape:
                    w.close();
                    break;
            }
        }
        else if (event.type == sf::Event::Closed)
           w.close();
    }
    w.clear(sf::Color(255, 218, 185, 0));
    this->drawGame(w, cellsize);
    w.display();
}
