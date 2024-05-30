/*
 * @Author: vic123 zhangzc_efz@163.com
 * @Date: 2024-05-29 22:57:14
 * @LastEditors: vic123 zhangzc_efz@163.com
 * @LastEditTime: 2024-05-30 15:02:45
 * @FilePath: \tetris-online\src\entity\snakeManager.cpp
 * @Description:
 *
 * Copyright (c) 2024 by vic123, All Rights Reserved.
 */
#include "snakeManager.hpp"
#include "snake.hpp"
SnakeManager::SnakeManager()
{
    snakes.emplace_back(true, 100, 100);  // A snake controlled by humanplayer
    snakes.emplace_back(false, 300, 300); // An auto snake
}
void SnakeManager::update()
{
    for (auto &snake : snakes)
    {
        snake.update();
    }
    deathJudge();
}

void SnakeManager::render(sf::RenderWindow &window)
{
    for (auto &snake : snakes)
    {
        snake.render(window);
    }
}

void SnakeManager::handleInput(sf::RenderWindow &window)
{
    for (auto &snake : snakes)
    {
        snake.setDirection(window);
    }
}

void SnakeManager::deathJudge()
{
    for (auto itSubject = snakes.begin(); itSubject != snakes.end();)
    {
        bool subjectKilled = false;
        for (auto itKiller = snakes.begin(); itKiller != snakes.end(); ++itKiller)
        {
            if (itKiller != itSubject)
            {
                if (itKiller->collision(itSubject->getHead(), 10))
                {
                    itSubject = snakes.erase(itSubject);
                    subjectKilled = true;
                    std::cout << "KILLED!";
                    break;
                }
            }
        }
        if (!subjectKilled)
        {
            ++itSubject;
        }
    }
}
std::vector<Snake> &SnakeManager::getSnakes()
{
    return snakes;
}