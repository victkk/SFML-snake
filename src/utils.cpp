/*
 * @Author: vic123 zhangzc_efz@163.com
 * @Date: 2024-05-29 14:07:43
 * @LastEditors: vic123 zhangzc_efz@163.com
 * @LastEditTime: 2024-05-30 19:28:12
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
sf::Vector2f operator*(const sf::Vector2f &v, float scalar)
{
    return sf::Vector2f(v.x * scalar, v.y * scalar);
}

sf::Vector2f operator*(float scalar, const sf::Vector2f &v)
{
    return v * scalar; // 利用了前一个运算符重载
}

sf::Texture createGradientTexture(unsigned int width, unsigned int height, sf::Color startColor, sf::Color endColor)
{
    sf::Image image;
    image.create(width, height);

    for (unsigned int x = 0; x < width; ++x)
    {
        float ratio = static_cast<float>(x) / static_cast<float>(width - 1);
        sf::Color color(
            static_cast<sf::Uint8>(startColor.r * (1 - ratio) + endColor.r * ratio),
            static_cast<sf::Uint8>(startColor.g * (1 - ratio) + endColor.g * ratio),
            static_cast<sf::Uint8>(startColor.b * (1 - ratio) + endColor.b * ratio),
            static_cast<sf::Uint8>(startColor.a * (1 - ratio) + endColor.a * ratio));

        for (unsigned int y = 0; y < height; ++y)
        {
            image.setPixel(x, y, color);
        }
    }

    sf::Texture texture;
    texture.loadFromImage(image);
    return texture;
}

template <typename T>
T square(T x)
{
    return x * x;
}

float V2fDist(sf::Vector2f a, sf::Vector2f b)
{
    return std::sqrt(square(a.x - b.x) + square(a.y - b.y));
}

float V2fMhtDist(sf::Vector2f a, sf::Vector2f b)
{
    return std::abs(a.x - b.x) + std::abs(a.y - b.y);
}
std::map<int, sf::Color> colorMap = {
    {0, sf::Color::Red},
    {1, sf::Color::Green},
    {2, sf::Color::Blue},
    {3, sf::Color::Yellow},
    {4, sf::Color::Magenta}};