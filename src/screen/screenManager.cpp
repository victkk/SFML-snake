/*
 * @Author: vic123 zhangzc_efz@163.com
 * @Date: 2024-06-01 15:50:53
 * @LastEditors: vic123 zhangzc_efz@163.com
 * @LastEditTime: 2024-06-11 15:02:56
 * @FilePath: \SFML-snake\src\screen\screenManager.cpp
 * @Description:
 *
 * Copyright (c) 2024 by vic123, All Rights Reserved.
 */

#include "screenManager.hpp"
ScreenManager::ScreenManager() : pauseScreen(), gameScreen(1000), startScreen(), deathScreen(), window(sf::VideoMode(800, 600), "SFML")
{
    currentScreen = &startScreen;
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
    // 遭，一不小心又写成屎山状态机了，寄
    switch (currentScreen->nextScreenLogic(window))
    {
    case SCREEN::PAUSE:
        currentScreen = &pauseScreen;
        break;
    case SCREEN::GAME:
        currentScreen = &gameScreen;
        break;
    case SCREEN::START:
        if (currentScreen != &startScreen)
        {
            gameScreen.restart();
        }
        currentScreen = &startScreen;
        break;

    case SCREEN::DEATH:
        gameScreen.restart();
        currentScreen = &deathScreen;
        break;
    default:
        break;
    }
}
void ScreenManager::jumpTo(SCREEN screen)
{
}