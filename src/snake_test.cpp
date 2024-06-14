/*
 * @Author: vic123 zhangzc_efz@163.com
 * @Date: 2024-05-29 13:06:26
 * @LastEditors: vic123 zhangzc_efz@163.com
 * @LastEditTime: 2024-06-12 14:47:35
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
#include "utils/Constants.hpp"


int main()
{
    ScreenManager &screenManager = ScreenManager::getInstance();
    screenManager.run();
    return 0;
}
