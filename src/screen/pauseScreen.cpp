/*
 * @Author: vic123 zhangzc_efz@163.com
 * @Date: 2024-05-31 14:18:31
 * @LastEditors: vic123 zhangzc_efz@163.com
 * @LastEditTime: 2024-05-31 15:24:10
 * @FilePath: \SFML-snake\src\screen\pauseScreen.cpp
 * @Description:
 *
 * Copyright (c) 2024 by vic123, All Rights Reserved.
 */
#include "pauseScreen.hpp"
PauseScreen::PauseScreen()
{
}
void PauseScreen::run(sf::RenderWindow &window)
{
    handleInput(window);
    update();
    render(window);
}

void PauseScreen::handleInput(sf::RenderWindow &window)
{
    ;
}

void PauseScreen::update()
{
    ;
}

void PauseScreen::render(sf::RenderWindow &window)
{
    window.clear(sf::Color::White);

    window.display();
}
SCREEN PauseScreen::nextScreenLogic(sf::RenderWindow &window)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        while (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            ;
        }
        return SCREEN::GAME;
    }
    return SCREEN::PAUSE;
}