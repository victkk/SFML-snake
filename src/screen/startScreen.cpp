/*
 * @Author: vic123 zhangzc_efz@163.com
 * @Date: 2024-06-05 20:49:13
 * @LastEditors: vic123 zhangzc_efz@163.com
 * @LastEditTime: 2024-06-11 19:47:57
 * @FilePath: \SFML-snake\src\screen\startScreen.cpp
 * @Description:
 *
 * Copyright (c) 2024 by vic123, All Rights Reserved.
 */
#include "startScreen.hpp"
StartScreen::StartScreen() : startButton("START")
{
    startButton.setPosition(sf::Vector2f(300, 350));
    if (!font.loadFromFile("../../resources/font/retro-pixel-font/arcade/retro-pixel-arcade.otf"))
    {
        std::cout << "fuck! where is the font?(calling from startScreen.cpp)";
    }
    text1.setFont(font);
    text1.setString("SFML SNAKE");
    text1.setFillColor(sf::Color::Blue);
    text1.setCharacterSize(64);
    text1.setOrigin(text1.getGlobalBounds().width / 2.0, text1.getGlobalBounds().height / 2.0);
    text1.setPosition(400, 200);

    text2.setFont(font);
    text2.setString("BY:VIC");
    text2.setFillColor(sf::Color::White);
    text2.setCharacterSize(32);
    text2.setOrigin(text2.getGlobalBounds().width / 2.0, text2.getGlobalBounds().height / 2.0);
    text2.setPosition(400, 280);
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
    window.draw(text1);
    window.draw(text2);
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