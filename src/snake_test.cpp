/*
 * @Author: vic123 zhangzc_efz@163.com
 * @Date: 2024-05-29 13:06:26
 * @LastEditors: vic123 zhangzc_efz@163.com
 * @LastEditTime: 2024-05-31 14:49:22
 * @FilePath: \SFML-snake\src\snake_test.cpp
 * @Description:
 *
 * Copyright (c) 2024 by vic123, All Rights Reserved.
 */
#include <SFML/Graphics.hpp>
#include "entity/snake.hpp"
#include "entity/snakeManager.hpp"
#include "entity/food.hpp"
#include "entity/foodManager.hpp"
#include "screen/screenManager.hpp"

sf::Time timePerFrame = sf::seconds(1.0f / 100.0f);

int main()
{
    ScreenManager screenManager;
    screenManager.run();
    return 0;
}
