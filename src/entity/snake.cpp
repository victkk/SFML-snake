/*
 * @Author: vic123 zhangzc_efz@163.com
 * @Date: 2024-05-29 12:28:45
 * @LastEditors: vic123 zhangzc_efz@163.com
 * @LastEditTime: 2024-06-14 11:46:36
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
    speed = 2;
    maxAngularVelocity = 300;
    direction = sf::Vector2f(std::rand() % 100 - 50, std::rand() % 100 - 50);

    texture = createGradientTexture(20, 20, colorMap[std::rand() % 5], colorMap[std::rand() % 5]);
    initial_x = std::rand() % (buttomRight.x - 200) + 100;
    initial_y = std::rand() % (buttomRight.y - 200) + 100;
    for (int i = 0; i < 200; i++)
    {
        snakeBody.emplace_back(initial_x, initial_y);
    }
}

Snake::Snake(bool humanPlayer) : humanPlayer{humanPlayer}
{

    kNodeDist = 1.5;
    bodyNodeNum = 10;
    speed = 2;
    maxAngularVelocity = 300;
    direction = sf::Vector2f(sf::Vector2f(std::rand() % 100 - 50, std::rand() % 100 - 50));

    texture = createGradientTexture(20, 20, colorMap[std::rand() % 5], colorMap[std::rand() % 5]);
    initial_x = std::rand() % (buttomRight.x - 200) + 100;
    initial_y = std::rand() % (buttomRight.y - 200) + 100;
    for (int i = 0; i < 50; i++)
    {
        snakeBody.emplace_back(initial_x, initial_y);
    }
}

void Snake::render(sf::RenderWindow &window)
{
    int cnt = 1;
    sf::CircleShape circle(kNodeDist * bodyNodeNum * 0.7);
    circle.setTexture(&texture);
    circle.setOrigin(kNodeDist * bodyNodeNum * 0.7, kNodeDist * bodyNodeNum * 0.7);
    for (const auto &segment : snakeBody)
    {
        if ((snakeBody.size() - cnt) % bodyNodeNum == 0)
        {
            circle.setPosition(segment);
            window.draw(circle);
        }
        cnt++;
    }
}

void Snake::setDirection(sf::Vector2f direction)
{
    if (direction.x != 0 || direction.y != 0)
        this->direction = direction;
}

void Snake::update()
{
    move();
    scaleUp();
    // Sprint(); //only for log(great cost)
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
        std::cout << "(" << snakeBody[0].x << "," << snakeBody[0].y << ")";
    }
    std::cout << std::endl;
}
void Snake::scaleUp()
{
    int len = getNodeNum();
    bodyNodeNum = 10 + std::log(len) / 3;
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
        speed = 4;
    }
    else
    {
        speed = 2;
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

float Snake::getRadius()
{
    return kNodeDist * bodyNodeNum * 0.7;
}
void Snake::respawn()
{

    texture = createGradientTexture(20, 20, colorMap[std::rand() % 5], colorMap[std::rand() % 5]);
    direction = sf::Vector2f(sf::Vector2f(std::rand() % 100 - 50, std::rand() % 100 - 50));

    snakeBody.clear();
    initial_x = std::rand() % (buttomRight.x - 200) + 100;
    initial_y = std::rand() % (buttomRight.y - 200) + 100;

    for (int i = 0; i < 50; i++)
    {
        snakeBody.emplace_back(initial_x, initial_y);
    }
}