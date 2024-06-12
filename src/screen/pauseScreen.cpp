/*
 * @Author: vic123 zhangzc_efz@163.com
 * @Date: 2024-05-31 14:18:31
 * @LastEditors: vic123 zhangzc_efz@163.com
 * @LastEditTime: 2024-06-11 17:18:24
 * @FilePath: \SFML-snake\src\screen\pauseScreen.cpp
 * @Description:
 *
 * Copyright (c) 2024 by vic123, All Rights Reserved.
 */

#include "pauseScreen.hpp"
PauseScreen::PauseScreen() : resumeButton("RESUME"), startMenuButton("ENDGAME")
{
    resumeButton.setPosition(sf::Vector2f(150, 300));
    startMenuButton.setPosition(sf::Vector2f(450, 300));
}
void PauseScreen::run(sf::RenderWindow &window)
{
    handleInput(window);
    update();
    render(window);
}

void PauseScreen::handleInput(sf::RenderWindow &window)
{
    resumeButton.update(window, sf::seconds(0));
    startMenuButton.update(window, sf::seconds(0));
}

void PauseScreen::update()
{
    ;
}

void PauseScreen::render(sf::RenderWindow &window)
{
    window.clear(sf::Color::Black);
    window.draw(resumeButton);
    window.draw(startMenuButton);
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
    if (resumeButton.getIsClicked())
    {
        return SCREEN::GAME;
    }
    if (startMenuButton.getIsClicked())
    {
        return SCREEN::START;
    }
    return SCREEN::PAUSE;
}

PauseScreen& PauseScreen::getInstance(){
    static PauseScreen mPauseScreen;
    return mPauseScreen;
}