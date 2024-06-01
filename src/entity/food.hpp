/*
 * @Author: vic123 zhangzc_efz@163.com
 * @Date: 2024-05-30 11:23:51
 * @LastEditors: vic123 zhangzc_efz@163.com
 * @LastEditTime: 2024-06-01 16:29:03
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

public:
    Food();
    void render(sf::RenderWindow &window);
    bool update(Snake &snake); // return dist from snakehead
    int getScore();
    void reborn();
};
