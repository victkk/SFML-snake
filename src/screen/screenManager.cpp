/*
 * @Author: vic123 zhangzc_efz@163.com
 * @Date: 2024-06-01 15:50:53
 * @LastEditors: vic123 zhangzc_efz@163.com
 * @LastEditTime: 2024-06-05 17:25:11
 * @FilePath: \SFML-snake\src\screen\screenManager.cpp
 * @Description:
 *
 * Copyright (c) 2024 by vic123, All Rights Reserved.
 */

#include "screenManager.hpp"
ScreenManager::ScreenManager() : pauseScreen(), gameScreen(100), window(sf::VideoMode(800, 600), "SFML")
{
    currentScreen = &gameScreen;
}
void ScreenManager::run()
{
    sf::Clock clock;
    sf::Clock test_clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Time logTime;
    // 主循环运行，直到窗口关闭
    while (window.isOpen())
    {
        // 事件处理
        sf::Time elapsedTime = clock.restart();

        timeSinceLastUpdate += elapsedTime;
        sf::Event event;

        if (timeSinceLastUpdate > timePerFrame)
        {

            while (timeSinceLastUpdate > timePerFrame)
                timeSinceLastUpdate -= timePerFrame;
            logTime = test_clock.restart();
            currentScreen->run(window);
            logTime = test_clock.restart();
            std::cout << "currentScreen.run:" << logTime.asMilliseconds() << std::endl;
            nextScreenLogic();
            logTime = test_clock.restart();
            std::cout << "nextScreenLogic:" << logTime.asMilliseconds() << std::endl;
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
            logTime = test_clock.restart();
            std::cout << "pollevent:" << logTime.asMilliseconds() << std::endl;
        }
    }
}

void ScreenManager::nextScreenLogic()
{
    switch (currentScreen->nextScreenLogic(window))
    {
    case SCREEN::PAUSE:
        currentScreen = &pauseScreen;
        break;
    case SCREEN::GAME:
        currentScreen = &gameScreen;
        break;
    default:
        break;
    }
}
void ScreenManager::jumpTo(SCREEN screen)
{
}