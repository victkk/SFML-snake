/*
 * @Author: vic123 zhangzc_efz@163.com
 * @Date: 2024-06-11 15:50:46
 * @LastEditors: vic123 zhangzc_efz@163.com
 * @LastEditTime: 2024-06-14 17:01:01
 * @FilePath: \SFML-snake\src\screen\deathScreen.cpp
 * @Description:
 *
 * Copyright (c) 2024 by vic123, All Rights Reserved.
 */
#include "deathScreen.hpp"
DeathScreen::DeathScreen() : startMenuButton("MAINMENU"), restartButton("RESTART"), ScreenEnum(SCREEN::DEATH)
{
    startMenuButton.setPosition(sf::Vector2f(180, 500));
    restartButton.setPosition(sf::Vector2f(420, 500));
    texture.loadFromFile("../../resources/img/noob.png");
    sNoob.setTexture(texture);
    sNoob.setColor(sf::Color(0, 0, 0, transparent));
    sf::FloatRect spriteBounds = sNoob.getLocalBounds();
    sNoob.setOrigin(spriteBounds.width / 2, spriteBounds.height / 2);
}
void DeathScreen::run(sf::RenderWindow &window)
{
    handleInput(window);
    update();
    render(window);
}

void DeathScreen::handleInput(sf::RenderWindow &window)
{
    startMenuButton.update(window, sf::seconds(0));
    restartButton.update(window, sf::seconds(0));
}

void DeathScreen::update()
{
    transparent++;
    if (transparent > 255)
    {
        transparent = 0;
    }
}

void DeathScreen::render(sf::RenderWindow &window)
{
    float scale = window.getSize().x / 1200.0;
    sf::Vector2u windowSize = window.getSize();
    sNoob.setPosition(window.getView().getCenter());
    sNoob.setScale(scale, scale);
    sNoob.setColor(sf::Color(255, 255, 255, transparent));
    startMenuButton.setPosition(window.getView().getCenter() + scale * sf::Vector2f(-30, 300) + sf::Vector2f(-220, 0));
    restartButton.setPosition(window.getView().getCenter() + scale * sf::Vector2f(30, 300) + sf::Vector2f(20, 0));
    window.clear(sf::Color::Black);
    window.draw(startMenuButton);
    window.draw(restartButton);
    window.draw(sNoob);
    window.display();
}
SCREEN DeathScreen::nextScreenLogic(sf::RenderWindow &window)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        while (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            ;
        }
        return SCREEN::START;
    }
    if (restartButton.getIsClicked())
    {
        return SCREEN::GAME;
    }
    if (startMenuButton.getIsClicked())
    {
        return SCREEN::START;
    }
    return SCREEN::DEATH;
}

DeathScreen &DeathScreen::getInstance()
{
    static DeathScreen mDeathScreen;
    return mDeathScreen;
}

SCREEN DeathScreen::getScreenEnum()
{
    return ScreenEnum;
}

void DeathScreen::restart()
{
    transparent = 0;
}