/*
 * @Author: vic123 zhangzc_efz@163.com
 * @Date: 2024-05-29 22:52:00
 * @LastEditors: vic123 zhangzc_efz@163.com
 * @LastEditTime: 2024-06-05 14:47:46
 * @FilePath: \SFML-snake\src\entity\snakeManager.hpp
 * @Description:
 *
 * Copyright (c) 2024 by vic123, All Rights Reserved.
 */
#pragma once
#include "snake.hpp"

class SnakeManager
{
private:
    std::vector<Snake> snakes;
    void autoDrive(int xMin, int xMax, int yMin, int yMax);
    void deathJudge();

public:
    SnakeManager();
    void handleInput(sf::RenderWindow &window);
    void followHumanPlayer(sf::RenderWindow &window);
    void render(sf::RenderWindow &window);
    void update();
    std::vector<Snake> &getSnakes();
};