/*
 * @Author: vic123 zhangzc_efz@163.com
 * @Date: 2024-05-29 13:06:26
 * @LastEditors: vic123 zhangzc_efz@163.com
 * @LastEditTime: 2024-05-30 15:12:30
 * @FilePath: \tetris-online\src\snake_test.cpp
 * @Description:
 *
 * Copyright (c) 2024 by vic123, All Rights Reserved.
 */
#include <SFML/Graphics.hpp>
#include "entity/snake.hpp"
#include "entity/snakeManager.hpp"
#include "entity/food.hpp"
#include "entity/foodManager.hpp"
sf::Time timePerFrame = sf::seconds(1.0f / 100.0f);

int main()
{
    // 创建一个视频模式对象
    sf::VideoMode videoMode(800, 600);
    SnakeManager snakeManager;
    FoodManager foodManager(400);
    // 创建一个窗口
    sf::RenderWindow window(videoMode, "SFML SNAKE");

    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    // 主循环运行，直到窗口关闭
    while (window.isOpen())
    {
        // 事件处理
        sf::Time elapsedTime = clock.restart();
        timeSinceLastUpdate += elapsedTime;
        sf::Event event;

        // 清除窗口（用黑色填充）

        if (timeSinceLastUpdate > timePerFrame)
        {
            std::cout << timeSinceLastUpdate.asSeconds() << std::endl;
            timeSinceLastUpdate -= timePerFrame;

            snakeManager.handleInput(window);
            snakeManager.update();
            foodManager.update(snakeManager.getSnakes());
            window.clear(sf::Color::Black);
            snakeManager.render(window);
            foodManager.render(window);
            window.display();
            while (window.pollEvent(event))
            {
                switch (event.type)
                {
                case sf::Event::Closed:
                    window.close();
                    break;

                default:
                    break;
                }
            }
        }
    }

    return 0;
}
