/*
 * @Author: vic123 zhangzc_efz@163.com
 * @Date: 2024-05-29 14:07:43
 * @LastEditors: vic123 zhangzc_efz@163.com
 * @LastEditTime: 2024-05-29 14:13:58
 * @FilePath: \tetris-online\src\utils.cpp
 * @Description:
 *
 * Copyright (c) 2024 by vic123, All Rights Reserved.
 */

#include "utils.hpp"
sf::Vector2f normalize(const sf::Vector2f &v)
{
    float length = std::sqrt(v.x * v.x + v.y * v.y);
    // 避免除以零
    if (length != 0)
    {
        return sf::Vector2f(v.x / length, v.y / length);
    }
    return sf::Vector2f(0, 0);
}