/*
 * @Author: vic123 zhangzc_efz@163.com
 * @Date: 2024-05-30 11:23:42
 * @LastEditors: vic123 zhangzc_efz@163.com
 * @LastEditTime: 2024-06-02 10:31:46
 * @FilePath: \SFML-snake\src\entity\food.cpp
 * @Description:
 *
 * Copyright (c) 2024 by vic123, All Rights Reserved.
 */
#include "food.hpp"

Food::Food()
{
    score = std::rand() % 5;
    pos = sf::Vector2f(std::rand() % 600, std::rand() % 800);
    velocity = 500; // pixel per second
    radius = 2;
}

void Food::render(sf::RenderWindow &window)
{
    sf::CircleShape circle(radius);
    circle.setPosition(pos);
    circle.setFillColor(colorMap[score]);
    window.draw(circle);
}
bool Food::update(Snake &snake)
{
    float dist = V2fMhtDist(snake.getHead(), pos);
    if (dist < 10)
    {
        return true;
    }
    if (dist < 50)
    {
        sf::Vector2f velocity_vec = normalize(snake.getHead() - pos) * velocity * timePerFrame.asSeconds();
        pos += velocity_vec;
    }
    return false;
}
void Food::reborn()
{
    pos = sf::Vector2f(std::rand() % 600, std::rand() % 800);
}
int Food::getScore()
{
    return score;
}