/*
 * @Author: vic123 zhangzc_efz@163.com
 * @Date: 2024-06-14 11:28:27
 * @LastEditors: vic123 zhangzc_efz@163.com
 * @LastEditTime: 2024-06-14 11:31:12
 * @FilePath: \SFML-snake\src\utils\Constants.cpp
 * @Description:
 *
 * Copyright (c) 2024 by vic123, All Rights Reserved.
 */
#include "Constants.hpp"

sf::Time timePerFrame = sf::seconds(1.0f / 120.0f);
int foodNum = 1000;
int robotSnakeNum = 10;

sf::Vector2i topLeft(0, 0);
sf::Vector2i buttomRight(2400, 1800); // size of the map