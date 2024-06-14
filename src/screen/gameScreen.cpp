/*
 * @Author: vic123 zhangzc_efz@163.com
 * @Date: 2024-06-01 15:50:53
 * @LastEditors: vic123 zhangzc_efz@163.com
 * @LastEditTime: 2024-06-14 11:39:21
 * @FilePath: \SFML-snake\src\screen\gameScreen.cpp
 * @Description:
 *
 * Copyright (c) 2024 by vic123, All Rights Reserved.
 */
#include "gameScreen.hpp"

GameScreen::GameScreen() : foodManager(FoodManager::getInstance()), snakeManager(SnakeManager::getInstance()), rectangle(), ScreenEnum(SCREEN::GAME)
{
    rectangle.setSize(sf::Vector2f(buttomRight.x, buttomRight.y));
    rectangle.setPosition(0, 0);
}

void GameScreen::run(sf::RenderWindow &window)
{
    sf::Clock test_clock;
    sf::Time logTime;
    test_clock.restart();
    handleInput(window);
    logTime = test_clock.restart();
    // std::cout << "\thandleInput:" << logTime.asMicroseconds() << std::endl;
    update();
    logTime = test_clock.restart();
    // std::cout << "\tupdate:" << logTime.asMicroseconds() << std::endl;
    render(window);
    logTime = test_clock.restart();
    // std::cout << "\trender:" << logTime.asMicroseconds() << std::endl;
}

void GameScreen::handleInput(sf::RenderWindow &window)
{
    snakeManager.handleInput(window);
}

void GameScreen::update()
{
    sf::Clock test_clock;
    sf::Time logTime;
    logTime = test_clock.restart();
    snakeManager.update();
    logTime = test_clock.restart();
    // std::cout << "\t\tSMupdate:" << logTime.asMicroseconds() << std::endl;

    foodManager.update(snakeManager.getSnakes());
    logTime = test_clock.restart();
    // std::cout << "\t\tFMupdate:" << logTime.asMicroseconds() << std::endl;
}

void GameScreen::render(sf::RenderWindow &window)
{
    sf::Clock test_clock;
    sf::Time logTime;
    window.clear(sf::Color::Black);
    window.draw(rectangle);
    snakeManager.followHumanPlayer(window);
    test_clock.restart();

    foodManager.render(window);
    logTime = test_clock.restart();
    // std::cout << "\t\tFMrender:" << logTime.asMicroseconds() << std::endl;

    snakeManager.render(window);
    logTime = test_clock.restart();
    // std::cout << "\t\tSMrender:" << logTime.asMicroseconds() << std::endl;

    window.display();
    logTime = test_clock.restart();
    // std::cout << "\t\tdisplay:" << logTime.asMicroseconds() << std::endl;
}
SCREEN GameScreen::nextScreenLogic(sf::RenderWindow &window)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        while (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            ;
        }
        sf::View view = window.getView();
        view.setCenter(400, 300);
        window.setView(view);
        return SCREEN::PAUSE;
    }
    if (!snakeManager.isHumanPlayerAlive())
    {
        sf::View view = window.getView();
        view.setCenter(400, 300);
        window.setView(view);
        return SCREEN::DEATH;
    }
    return SCREEN::GAME;
}

void GameScreen::restart()
{
    snakeManager.randomInitialize();
}

GameScreen &GameScreen::getInstance()
{
    static GameScreen mGameScreen;
    return mGameScreen;
}

SCREEN GameScreen::getScreenEnum()
{
    return ScreenEnum;
}