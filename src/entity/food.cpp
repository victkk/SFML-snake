/*
 * @Author: vic123 zhangzc_efz@163.com
 * @Date: 2024-05-30 11:23:42
 * @LastEditors: vic123 zhangzc_efz@163.com
 * @LastEditTime: 2024-05-30 13:05:52
 * @FilePath: \tetris-online\src\entity\food.cpp
 * @Description:
 *
 * Copyright (c) 2024 by vic123, All Rights Reserved.
 */
#include "food.hpp"

Food::Food()
{
    score = std::rand() % 5;
    pos = sf::Vector2f(std::rand() % 600, std::rand() % 800);
    velocity = 2;
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
    float dist = V2fDist(snake.getHead(), pos);
    if (dist < 10)
    {
        return true;
    }
    if (dist < 50)
    {
        sf::Vector2f velocity_vec = normalize(snake.getHead() - pos) * velocity;
        pos += velocity_vec;
    }
    return false;
}
int Food::getScore()
{
    return score;
}