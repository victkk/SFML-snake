/*
 * @Author: vic123 zhangzc_efz@163.com
 * @Date: 2024-05-30 11:23:42
 * @LastEditors: vic123 zhangzc_efz@163.com
 * @LastEditTime: 2024-06-05 20:44:23
 * @FilePath: \SFML-snake\src\entity\food.cpp
 * @Description:
 *
 * Copyright (c) 2024 by vic123, All Rights Reserved.
 */
#include "food.hpp"

Food::Food(sf::Vertex *vertex) : vertex(vertex)
{
    score = std::rand() % 5;
    pos = sf::Vector2f(std::rand() % buttomRight.x, std::rand() % buttomRight.y);
    velocity = 500; // pixel per second
    radius = 2;
    vertex[0].color = colorMap[score];
    vertex[1].color = colorMap[score];
    vertex[2].color = colorMap[score];
    vertex[3].color = colorMap[score];
    vertex[0].position = pos;
    vertex[1].position = pos + sf::Vector2f(0, 4);
    vertex[2].position = pos + sf::Vector2f(4, 4);
    vertex[3].position = pos + sf::Vector2f(4, 0);
}

bool Food::update(Snake &snake)
{
    float dist = V2fMhtDist(snake.getHead(), pos);
    if (dist < snake.getRadius())
    {
        reborn();
        vertex[0].position = pos;
        vertex[1].position = pos + sf::Vector2f(0, 4);
        vertex[2].position = pos + sf::Vector2f(4, 4);
        vertex[3].position = pos + sf::Vector2f(4, 0);
        return true;
    }
    else if (dist < 5 * snake.getRadius())
    {
        sf::Vector2f velocity_vec = normalize(snake.getHead() - pos) * velocity * timePerFrame.asSeconds();
        pos += velocity_vec;
        vertex[0].position = pos;
        vertex[1].position = pos + sf::Vector2f(0, 4);
        vertex[2].position = pos + sf::Vector2f(4, 4);
        vertex[3].position = pos + sf::Vector2f(4, 0);
    }
    return false;
}
void Food::reborn()
{
    pos = sf::Vector2f(std::rand() % buttomRight.x, std::rand() % buttomRight.y);
}
int Food::getScore()
{
    return score;
}