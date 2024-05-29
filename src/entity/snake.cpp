/*
 * @Author: vic123 zhangzc_efz@163.com
 * @Date: 2024-05-29 12:28:45
 * @LastEditors: vic123 zhangzc_efz@163.com
 * @LastEditTime: 2024-05-29 14:31:10
 * @FilePath: \tetris-online\src\entity\snake.cpp
 * @Description:
 *
 * Copyright (c) 2024 by vic123, All Rights Reserved.
 */
#include "snake.hpp"

Snake::Snake()
{
    kNodeDist = 5;
    speed = 1;
    direction = sf::Vector2f(1, 1);
    for (int i = 0; i < 20; i++)
    {
        snakeBody.emplace_back(100, 100);
    }
}
void Snake::render(sf::RenderWindow &window)
{
    for (const auto &segment : snakeBody)
    {
        sf::RectangleShape rectangle(sf::Vector2f(kNodeDist, kNodeDist));
        rectangle.setPosition(segment);
        window.draw(rectangle);
    }
}
void Snake::handleInput(sf::RenderWindow &window)
{
    sf::Event event;
    // Sprint();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        direction = sf::Vector2f(-1, 0);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        direction = sf::Vector2f(0, -1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        direction = sf::Vector2f(0, 1);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        direction = sf::Vector2f(1, 0);
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        sf::Vector2f headPos = snakeBody.at(snakeBody.size() - 1);
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        direction = sf::Vector2f(mousePos.x - headPos.x, mousePos.y - headPos.y);
    }
}
void Snake::update()
{
    move();
}
void Snake::move()
{
    snakeBody.erase(snakeBody.begin());
    snakeBody.push_back(snakeBody.at(snakeBody.size() - 1) + normalize(direction));
}

// helper func for debugging
void Snake::Sprint()
{
    for (const auto &a : snakeBody)
    {
        std::cout << "(" << a.x << "," << a.y << ")";
    }
    std::cout << std::endl;
}