/*
 * @Author: vic123 zhangzc_efz@163.com
 * @Date: 2024-05-30 11:24:05
 * @LastEditors: vic123 zhangzc_efz@163.com
 * @LastEditTime: 2024-06-05 16:17:12
 * @FilePath: \SFML-snake\src\entity\foodManager.hpp
 * @Description:
 *
 * Copyright (c) 2024 by vic123, All Rights Reserved.
 */
#pragma once
#include <vector>
#include "food.hpp"
#include "snake.hpp"
#include "snakeManager.hpp"
#include <vector>
#include <SFML/Graphics.hpp>
class FoodManager
{
private:
    std::vector<Food> foods;
    sf::VertexArray quadsArray;
public:
    FoodManager(int foodNum);
    void update(std::vector<Snake> &snakes);

    void render(sf::RenderWindow &window);
};
