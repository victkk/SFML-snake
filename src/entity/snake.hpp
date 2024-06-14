/*
 * @Author: vic123 zhangzc_efz@163.com
 * @Date: 2024-05-29 12:29:27
 * @LastEditors: vic123 zhangzc_efz@163.com
 * @LastEditTime: 2024-06-12 14:49:26
 * @FilePath: \SFML-snake\src\entity\snake.hpp
 * @Description:
 *
 * Copyright (c) 2024 by vic123, All Rights Reserved.
 */
#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <deque>
#include "../utils/utils.hpp"
#include "../utils/Constants.hpp"
class Snake
{
private:
    float kNodeDist;
    int bodyNodeNum;
    std::deque<sf::Vector2f> snakeBody;
    sf::Vector2f direction;
    int speed;
    sf::Texture texture;
    bool humanPlayer;
    int initial_x, initial_y;
    float maxAngularVelocity;

public:
    Snake(bool humanPlayer, int initial_x, int initial_y);
    Snake(bool humanPlayer);
    void update();
    void render(sf::RenderWindow &window);
    void grow(int size);
    void setDirection(sf::Vector2f direction);
    bool collision(sf::Vector2f point, float r);
    const sf::Vector2f &getHead();
    int getNodeNum();
    bool isHumanPlayer();
    void setSpeed(bool isHighSpeed);
    int getSpeed();
    int getMaxAngularVelocity();
    sf::Vector2f getDirection();
    std::deque<sf::Vector2f> const &getSnakeBody();
    float getRadius();
    void respawn();

private:
    void move();
    void Sprint();
    void scaleUp();
};

