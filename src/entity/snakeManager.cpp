
/*
 * @Author: vic123 zhangzc_efz@163.com
 * @Date: 2024-05-29 22:57:14
 * @LastEditors: vic123 zhangzc_efz@163.com
 * @LastEditTime: 2024-06-11 21:01:55
 * @FilePath: \SFML-snake\src\entity\snakeManager.cpp
 * @Description:
 *
 * Copyright (c) 2024 by vic123, All Rights Reserved.
 */
#include "snakeManager.hpp"
#include "snake.hpp"
SnakeManager::SnakeManager()
{
    snakes.emplace_back(true);  // A snake controlled by humanplayer
    snakes.emplace_back(false); // An auto snake
    snakes.emplace_back(false);
    snakes.emplace_back(false);
    humanPlayerAlive = true;
}
void SnakeManager::update()
{
    for (auto &snake : snakes)
    {
        snake.update();
    }
    autoDrive(topLeft.x, buttomRight.x, topLeft.y, buttomRight.y);
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
        if (snake.isHumanPlayer())
        {
            sf::Event event;

            // Sprint();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                snake.setSpeed(true);
            else
                snake.setSpeed(false);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                snake.setDirection(sf::Vector2f(-1, 0));
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                snake.setDirection(sf::Vector2f(0, -1));
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                snake.setDirection(sf::Vector2f(0, 1));
            else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                snake.setDirection(sf::Vector2f(1, 0));
            else if (sf::Event::GainedFocus && sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::Vector2f headPos = snake.getHead();
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2f relativePos = sf::Vector2f(mousePos.x - 400, mousePos.y - 300);
                snake.setDirection(turnWithBound(snake.getDirection(), relativePos, snake.getMaxAngularVelocity() * snake.getSpeed() * timePerFrame.asSeconds())); // speed * maxAngularVelocity * timePerFrame.asSeconds()
            }
        }
    }
}

void SnakeManager::deathJudge()
{
    for (auto itSubject = snakes.begin(); itSubject != snakes.end();)
    {
        bool subjectKilled = false;
        if (itSubject->getHead().x < topLeft.x || itSubject->getHead().x > buttomRight.x || itSubject->getHead().y < topLeft.y || itSubject->getHead().y > buttomRight.y)
        {
            // itSubject = snakes.erase(itSubject);
            subjectKilled = true;
            std::cout << "KILLED!";
            if (itSubject->isHumanPlayer())
            {
                humanPlayerAlive = false;
            }
            itSubject->respawn();
            break;
        }
        for (auto itKiller = snakes.begin(); itKiller != snakes.end(); ++itKiller)
        {
            if (itKiller != itSubject)
            {
                if (itKiller->collision(itSubject->getHead(), 10))
                {
                    if (itSubject->isHumanPlayer())
                    {
                        humanPlayerAlive = false;
                    }
                    itSubject->respawn();
                    // itSubject = snakes.erase(itSubject);
                    subjectKilled = true;
                    std::cout << "KILLED!";
                    break;
                }
            }
        }
        // if (!subjectKilled)
        // {
        ++itSubject;
        // }
    }
}
std::vector<Snake> &SnakeManager::getSnakes()
{
    return snakes;
}

void SnakeManager::autoDrive(int xMin, int xMax, int yMin, int yMax)
{
    for (auto &snake : snakes)
    {
        if (!snake.isHumanPlayer())
        {

            bool changed = false;
            sf::Vector2f closestPoint;
            float dist = 50;
            if (xMax - snake.getSnakeBody().at(snake.getSnakeBody().size() - 1).x < dist)
            {
                closestPoint = sf::Vector2f(xMax, snake.getSnakeBody().at(snake.getSnakeBody().size() - 1).y);
                dist = xMax - snake.getSnakeBody().at(snake.getSnakeBody().size() - 1).x;
                changed = true;
            }
            if (-xMin + snake.getSnakeBody().at(snake.getSnakeBody().size() - 1).x < dist)
            {
                closestPoint = sf::Vector2f(xMin, snake.getSnakeBody().at(snake.getSnakeBody().size() - 1).y);
                dist = -xMin + snake.getSnakeBody().at(snake.getSnakeBody().size() - 1).x;
                changed = true;
            }
            if (yMax - snake.getSnakeBody().at(snake.getSnakeBody().size() - 1).y < dist)
            {
                closestPoint = sf::Vector2f(snake.getSnakeBody().at(snake.getSnakeBody().size() - 1).x, yMax);
                dist = yMax - snake.getSnakeBody().at(snake.getSnakeBody().size() - 1).y;
                changed = true;
            }
            if (-yMin + snake.getSnakeBody().at(snake.getSnakeBody().size() - 1).y < dist)
            {
                closestPoint = sf::Vector2f(snake.getSnakeBody().at(snake.getSnakeBody().size() - 1).x, yMin);
                dist = -yMin + snake.getSnakeBody().at(snake.getSnakeBody().size() - 1).y;
                changed = true;
            }
            for (auto itSnake = snakes.begin(); itSnake != snakes.end(); itSnake++)
            {
                if (&*itSnake != &snake)
                {
                    for (const auto &node : itSnake->getSnakeBody())
                        if (V2fDist(node, snake.getSnakeBody().at(snake.getSnakeBody().size() - 1)) < dist)
                        {
                            closestPoint = node;
                            dist = V2fDist(node, snake.getSnakeBody().at(snake.getSnakeBody().size() - 1));
                            changed = true;
                        }
                }
            }

            if (changed)
            {
                sf::Vector2f headPos = snake.getSnakeBody().at(snake.getSnakeBody().size() - 1);
                sf::Vector2f relativePos = sf::Vector2f(-closestPoint.x + headPos.x, -closestPoint.y + headPos.y);
                snake.setDirection(turnWithBound(snake.getDirection(), relativePos, snake.getMaxAngularVelocity() * snake.getSpeed() * timePerFrame.asSeconds()));
            }
            else
            {
                if (std::rand() % 2000 < 2000 * timePerFrame.asSeconds())
                {
                    snake.setDirection(sf::Vector2f(std::rand() % 100 - 50, std::rand() % 100 - 50));
                }

                if (std::rand() % 2000 < 2000 * timePerFrame.asSeconds())
                {
                    snake.setSpeed(std::rand() % 2);
                }
            }
        }
    }
}
void SnakeManager::followHumanPlayer(sf::RenderWindow &window)
{
    sf::View view = window.getView();
    for (auto &snake : snakes)
    {
        if (snake.isHumanPlayer())
        {
            view.setCenter(snake.getHead());
        }
    }
    window.setView(view);
    return;
}

bool SnakeManager::isHumanPlayerAlive()
{
    return humanPlayerAlive;
}

void SnakeManager::randomInitialize()
{
    for (auto &snake : snakes)
    {
        snake.respawn();
    }
    humanPlayerAlive = true;
}

SnakeManager &SnakeManager::getInstance()
{
    static SnakeManager mSnakeManager;
    return mSnakeManager;
}