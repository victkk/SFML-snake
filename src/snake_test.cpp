/*
 * @Author: vic123 zhangzc_efz@163.com
 * @Date: 2024-05-29 13:06:26
 * @LastEditors: vic123 zhangzc_efz@163.com
 * @LastEditTime: 2024-05-29 13:32:22
 * @FilePath: \tetris-online\src\snake_test.cpp
 * @Description:
 *
 * Copyright (c) 2024 by vic123, All Rights Reserved.
 */
#include <SFML/Graphics.hpp>
#include "entity/snake.hpp"

int main()
{
    // 创建一个视频模式对象
    sf::VideoMode videoMode(800, 600);
    Snake snake;
    // 创建一个窗口
    sf::RenderWindow window(videoMode, "SFML Game Framework");
    sf::Time timePerFrame = sf::seconds(1.0f / 60.0f);
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

        while (timeSinceLastUpdate > timePerFrame)
        {
            timeSinceLastUpdate -= timePerFrame;
            snake.handleInput(window);
            snake.update();
        }
        window.clear(sf::Color::Black);
        snake.render(window);
        // 在这里添加更多的绘制调用
        // 例如: window.draw(someDrawableObject);

        // 显示已经绘制的内容
        window.display();
    }

    return 0;
}