/*
 * @Author: vic123 zhangzc_efz@163.com
 * @Date: 2024-05-29 12:28:45
 * @LastEditors: vic123 zhangzc_efz@163.com
 * @LastEditTime: 2024-06-05 14:39:21
 * @FilePath: \SFML-snake\src\entity\snake.cpp
 * @Description:
 *
 * Copyright (c) 2024 by vic123, All Rights Reserved.
 */
#include "snake.hpp"

Snake::Snake(bool humanPlayer, int initial_x, int initial_y) : humanPlayer{humanPlayer}, initial_x{initial_x}, initial_y{initial_y}
{
    kNodeDist = 1.5;
    bodyNodeNum = 10;
    speed = 1;
    maxAngularVelocity = 300;
    direction = sf::Vector2f(1, 1);
    texture = createGradientTexture(20, 20, sf::Color::Red, sf::Color::Blue);
    for (int i = 0; i < 200; i++)
    {
        snakeBody.emplace_back(initial_x, initial_y);
    }
}
void Snake::render(sf::RenderWindow &window)
{
    int cnt = 0;
    sf::CircleShape circle(kNodeDist * bodyNodeNum * 0.7);
    circle.setTexture(&texture);
    for (const auto &segment : snakeBody)
    {
        if ((snakeBody.size() - cnt++) % bodyNodeNum == 0) // to make sure the first node is always displayed
        {
            circle.setPosition(segment);
            window.draw(circle);
        }
    }
}

void Snake::setDirection(sf::Vector2f direction)
{
    this->direction = direction;
}

void Snake::autoDrive(std::vector<Snake> &snakes, int xMin, int xMax, int yMin, int yMax)
{
    bool changed = false;
    sf::Vector2f closestPoint;
    float dist = 50;
    if (xMax - snakeBody.at(snakeBody.size() - 1).x < dist)
    {
        closestPoint = sf::Vector2f(xMax, snakeBody.at(snakeBody.size() - 1).y);
        dist = xMax - snakeBody.at(snakeBody.size() - 1).x;
        changed = true;
    }
    if (-xMin + snakeBody.at(snakeBody.size() - 1).x < dist)
    {
        closestPoint = sf::Vector2f(xMin, snakeBody.at(snakeBody.size() - 1).y);
        dist = -xMin + snakeBody.at(snakeBody.size() - 1).x;
        changed = true;
    }
    if (yMax - snakeBody.at(snakeBody.size() - 1).y < dist)
    {
        closestPoint = sf::Vector2f(snakeBody.at(snakeBody.size() - 1).x, yMax);
        dist = yMax - snakeBody.at(snakeBody.size() - 1).y;
        changed = true;
    }
    if (-yMin + snakeBody.at(snakeBody.size() - 1).y < dist)
    {
        closestPoint = sf::Vector2f(snakeBody.at(snakeBody.size() - 1).x, yMin);
        dist = -yMin + snakeBody.at(snakeBody.size() - 1).y;
        changed = true;
    }
    for (auto itSnake = snakes.begin(); itSnake != snakes.end(); itSnake++)
    {
        if (&*itSnake != this)
        {
            for (const auto &node : itSnake->snakeBody)
                if (V2fDist(node, snakeBody.at(snakeBody.size() - 1)) < dist)
                {
                    closestPoint = node;
                    dist = V2fDist(node, snakeBody.at(snakeBody.size() - 1));
                    changed = true;
                }
        }
    }
    if (changed)
    {
        sf::Vector2f headPos = snakeBody.at(snakeBody.size() - 1);
        sf::Vector2f relativePos = sf::Vector2f(-closestPoint.x + headPos.x, -closestPoint.y + headPos.y);
        direction = turnWithBound(direction, relativePos, speed * maxAngularVelocity * timePerFrame.asSeconds());
    }
}
void Snake::update()
{
    move();
    scaleUp();
}
void Snake::move()
{
    for (int i = 0; i < speed; i++)
    {
        snakeBody.pop_front();
        snakeBody.push_back(snakeBody.at(snakeBody.size() - 1) + kNodeDist * normalize(direction));
    }
}

void Snake::grow(int size)
{
    for (int i = 0; i < size; i++)
    {
        snakeBody.push_front(snakeBody[0]);
    }
}

bool Snake::collision(sf::Vector2f point, float r)
{
    for (const auto &node : snakeBody)
    {
        if (V2fDist(node, point) < r)
            return true;
    }
    return false;
}

const sf::Vector2f &Snake::getHead()
{
    return snakeBody[snakeBody.size() - 1];
}

// helper func for debugging
void Snake::Sprint()
{
    for (const auto &a : snakeBody)
    {
        std::cout << "(" << a.x << "," << a.y << ")";
    }
    std::cout << std::endl;
}
void Snake::scaleUp()
{
    int len = getNodeNum();
    bodyNodeNum = 10 + len / 100;
}

int Snake::getNodeNum()
{
    return snakeBody.size();
}
bool Snake::isHumanPlayer()
{
    return humanPlayer;
}

void Snake::setSpeed(bool isHighSpeed)
{
    if (isHighSpeed)
    {
        speed = 2;
    }
    else
    {
        speed = 1;
    }
}

int Snake::getSpeed()
{
    return speed;
}

int Snake::getMaxAngularVelocity()
{
    return maxAngularVelocity;
}

sf::Vector2f Snake::getDirection()
{
    return direction;
}

std::deque<sf::Vector2f> const &Snake::getSnakeBody()
{
    return snakeBody;
}