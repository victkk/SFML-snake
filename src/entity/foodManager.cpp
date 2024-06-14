/*
 * @Author: vic123 zhangzc_efz@163.com
 * @Date: 2024-05-30 11:23:58
 * @LastEditors: vic123 zhangzc_efz@163.com
 * @LastEditTime: 2024-06-12 14:43:50
 * @FilePath: \SFML-snake\src\entity\foodManager.cpp
 * @Description:
 *
 * Copyright (c) 2024 by vic123, All Rights Reserved.
 */
#include "foodManager.hpp"

FoodManager::FoodManager(int foodNum) : quadsArray(sf::Quads, foodNum * 4)
{
    for (int i = 0; i < foodNum; i++)
    {
        foods.emplace_back(&(quadsArray[4 * i]));
    }
}
void FoodManager::render(sf::RenderWindow &window)
{
    window.draw(quadsArray);
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
                break;
            }
        }
        if (!isEaten)
            food_ptr++;
    }
}

FoodManager &FoodManager::getInstance()
{
    static FoodManager mFoodManager(foodNum);
    return mFoodManager;
}