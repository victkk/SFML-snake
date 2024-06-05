/*
 * @Author: vic123 zhangzc_efz@163.com
 * @Date: 2024-05-29 14:07:43
 * @LastEditors: vic123 zhangzc_efz@163.com
 * @LastEditTime: 2024-05-30 20:12:05
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

float V2fMhtDist(sf::Vector2f a, sf::Vector2f b)
{
    return std::abs(a.x - b.x) + std::abs(a.y - b.y);
}

float V2fDist(const sf::Vector2f &a, const sf::Vector2f &b)
{
    return std::sqrt(square(a.x - b.x) + square(a.y - b.y));
}
sf::Vector2f turnWithBound(const sf::Vector2f &current, const sf::Vector2f &target, float angleBound)
{
    float angle = calculateAngleDifference(target, current);
    if (abs(angle) > angleBound)
    {
        return rotateVector(current, angleBound * (angle > 0 ? 1 : -1));
    }
    else
    {
        return rotateVector(current, angle);
    }
}
double vectorAngle(const sf::Vector2f &vec)
{
    return std::atan2(vec.y, vec.x) * 180.0 / std::acos(-1.0);
}
sf::Vector2f rotateVector(const sf::Vector2f &vec, float angle)
{
    // 将角度转换为弧度
    float radians = angle * std::acos(-1.0) / 180.0f;

    // 计算旋转后的新坐标
    float cosTheta = std::cos(radians);
    float sinTheta = std::sin(radians);
    float xNew = vec.x * cosTheta - vec.y * sinTheta;
    float yNew = vec.x * sinTheta + vec.y * cosTheta;

    return sf::Vector2f(xNew, yNew);
}
// Function to calculate the angle difference between two vectors
double calculateAngleDifference(const sf::Vector2f &vec1, const sf::Vector2f &vec2)
{
    double angle1 = vectorAngle(vec1);
    double angle2 = vectorAngle(vec2);
    double diff = angle1 - angle2;

    // Normalize the angle difference to be within [-180, 180]
    while (diff > 180.0)
        diff -= 360.0;
    while (diff < -180.0)
        diff += 360.0;

    return diff;
}

std::map<int, sf::Color> colorMap = {
    {0, sf::Color::Red},
    {1, sf::Color::Green},
    {2, sf::Color::Blue},
    {3, sf::Color::Yellow},
    {4, sf::Color::Magenta}};