/*
 * @Author: vic123 zhangzc_efz@163.com
 * @Date: 2024-05-30 11:23:51
 * @LastEditors: vic123 zhangzc_efz@163.com
 * @LastEditTime: 2024-06-05 19:16:56
 * @FilePath: \SFML-snake\src\entity\food.hpp
 * @Description:
 *
 * Copyright (c) 2024 by vic123, All Rights Reserved.
 */
#pragma once
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include "../utils.hpp"
#include "snake.hpp"
class Food
{
private:
    sf::Vector2f pos;
    int velocity; // when eaten by snake, food flow to snake
    int score;    // also for color
    float radius;
    sf::Vertex *vertex;

public:
    Food(sf::Vertex *vertex);
    bool update(Snake &snake);
    int getScore();
    void reborn();
};
extern sf::Vector2i buttomRight,topLeft;