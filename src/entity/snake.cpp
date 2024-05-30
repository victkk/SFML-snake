/*
 * @Author: vic123 zhangzc_efz@163.com
 * @Date: 2024-05-29 12:28:45
 * @LastEditors: vic123 zhangzc_efz@163.com
 * @LastEditTime: 2024-05-30 20:30:12
 * @FilePath: \tetris-online\src\entity\snake.cpp
 * @Description:
 *
 * Copyright (c) 2024 by vic123, All Rights Reserved.
 */
#include "snake.hpp"

Snake::Snake(bool humanPlayer, int initial_x, int initial_y) : humanPlayer{humanPlayer}, initial_x{initial_x}, initial_y{initial_y}
{
    kNodeDist = 1;
    speed = 1;
    maxAngularVelocity = 300;
    direction = sf::Vector2f(1, 1);
    texture = createGradientTexture(20, 20, sf::Color::Red, sf::Color::Blue);
    for (int i = 0; i < 200; i++)
    {
        snakeBody.emplace_back(initial_x, initial_y);
    }
}
void Snake::render(sf::RenderWindow &window)
{
    int cnt = 0;
    for (const auto &segment : snakeBody)
    {
        if ((snakeBody.size() - cnt++) % 10 == 0) // to make sure the first node is always displayed
        {
            sf::CircleShape circle(kNodeDist * 10 * 0.7);
            circle.setPosition(segment);
            circle.setTexture(&texture);
            window.draw(circle);
        }
    }
}

void Snake::setDirection(sf::RenderWindow &window)
{
    if (humanPlayer)
    {
        handleInput(window);
    }
    else
    {
        autoDrive();
    }
}
void Snake::handleInput(sf::RenderWindow &window)
{
    sf::Event event;
    // Sprint();
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        speed = 2;
    else
        speed = 1;
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        direction = sf::Vector2f(-1, 0);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        direction = sf::Vector2f(0, -1);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        direction = sf::Vector2f(0, 1);
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        direction = sf::Vector2f(1, 0);
    else if (sf::Event::GainedFocus && sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        sf::Vector2f headPos = snakeBody.at(snakeBody.size() - 1);
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        sf::Vector2f relativePos = sf::Vector2f(mousePos.x - headPos.x, mousePos.y - headPos.y);
        direction = turnWithBound(direction, relativePos, speed * maxAngularVelocity * timePerFrame.asSeconds());
    }
}
void Snake::autoDrive()
{
    static int cnt = 0;
    cnt++;
    if (cnt % 400 == 100)
    {
        direction = sf::Vector2f(-1, 0);
    }
    if (cnt % 400 == 200)
    {
        direction = sf::Vector2f(0, 1);
    }
    if (cnt % 400 == 300)
    {
        direction = sf::Vector2f(1, 0);
    }
    if (cnt % 400 == 0)
    {
        direction = sf::Vector2f(0, -1);
        cnt = 0;
    }
}
void Snake::update()
{
    move();
}
void Snake::move()
{
    for (int i = 0; i < speed; i++)
    {
        snakeBody.pop_front();
        snakeBody.push_back(snakeBody.at(snakeBody.size() - 1) + kNodeDist * normalize(direction));
    }
}

void Snake::grow(int size)
{
    for (int i = 0; i < size; i++)
    {
        snakeBody.push_front(snakeBody[0]);
    }
}

bool Snake::collision(sf::Vector2f point, float r)
{
    for (const auto &node : snakeBody)
    {
        if (V2fDist(node, point) < r)
            return true;
    }
    return false;
}

const sf::Vector2f &Snake::getHead()
{
    return snakeBody[snakeBody.size() - 1];
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
