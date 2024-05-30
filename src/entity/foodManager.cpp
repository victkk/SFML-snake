/*
 * @Author: vic123 zhangzc_efz@163.com
 * @Date: 2024-05-30 11:23:58
 * @LastEditors: vic123 zhangzc_efz@163.com
 * @LastEditTime: 2024-05-30 13:09:20
 * @FilePath: \tetris-online\src\entity\foodManager.cpp
 * @Description:
 *
 * Copyright (c) 2024 by vic123, All Rights Reserved.
 */
#include "foodManager.hpp"

FoodManager::FoodManager(int foodNum)
{
    for (int i = 0; i < foodNum; i++)
    {
        foods.emplace_back();
    }
    foodBornSpeed = 10;
    cnt = 0;
}
void FoodManager::render(sf::RenderWindow &window)
{
    for (auto &food : foods)
    {
        food.render(window);
    }
}
void FoodManager::update(std::vector<Snake> &snakes)
{
    bool isEaten = false;
    // update food location/destroy food
    for (auto food_ptr = foods.begin(); food_ptr != foods.end();)
    {
        isEaten = false;
        for (auto &snake : snakes)
        {
            if (food_ptr->update(snake))
            {

                isEaten = true;
                snake.grow(food_ptr->getScore());
                food_ptr = foods.erase(food_ptr);
                break;
            }
        }
        if (!isEaten)
            food_ptr++;
    }
    // create food
    if (cnt++ * foodBornSpeed > 1 / timePerFrame.asSeconds())
    {
        cnt = 0;
        foods.emplace_back();
    }
}