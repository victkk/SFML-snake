/*
 * @Author: vic123 zhangzc_efz@163.com
 * @Date: 2024-06-05 20:49:13
 * @LastEditors: vic123 zhangzc_efz@163.com
 * @LastEditTime: 2024-06-11 17:19:02
 * @FilePath: \SFML-snake\src\screen\startScreen.cpp
 * @Description:
 *
 * Copyright (c) 2024 by vic123, All Rights Reserved.
 */
#include "startScreen.hpp"
StartScreen::StartScreen() : startButton("start")
{
    startButton.setPosition(sf::Vector2f(300, 350));
}
void StartScreen::run(sf::RenderWindow &window)
{
    handleInput(window);
    update();
    render(window);
}

void StartScreen::handleInput(sf::RenderWindow &window)
{
    startButton.update(window, sf::seconds(0));
}

void StartScreen::update()
{
    ;
}

void StartScreen::render(sf::RenderWindow &window)
{
    window.clear(sf::Color::Black);
    window.draw(startButton);
    window.display();
}
SCREEN StartScreen::nextScreenLogic(sf::RenderWindow &window)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
    {
        return SCREEN::GAME;
    }
    if (startButton.getIsClicked())
    {
        return SCREEN::GAME;
    }
    return SCREEN::START;
}