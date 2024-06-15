/*
 * @Author: vic123 zhangzc_efz@163.com
 * @Date: 2024-06-01 15:50:53
 * @LastEditors: vic123 zhangzc_efz@163.com
 * @LastEditTime: 2024-06-15 14:57:13
 * @FilePath: \SFML-snake\src\screen\screenManager.cpp
 * @Description:
 *
 * Copyright (c) 2024 by vic123, All Rights Reserved.
 */

#include "screenManager.hpp"
ScreenManager::ScreenManager() : pauseScreen(PauseScreen::getInstance()), gameScreen(GameScreen::getInstance()), startScreen(StartScreen::getInstance()), deathScreen(DeathScreen::getInstance()), window(sf::VideoMode(800, 600), "SFML")
{
    currentScreen = &startScreen;

    if (!music.openFromFile("../../resources/audio/dabeizhou.ogg"))
    {
        {
            std::cout << "fuck! where is dabeizhou.ogg?(calling from screenManager.cpp)";
        }
    }
    music.setVolume(25);
    music.setLoop(true);

    music.play();
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
            // logTime = test_clock.restart();
            // std::cout << "currentScreen.run:" << logTime.asMilliseconds() << std::endl;
            nextScreenLogic();
            // logTime = test_clock.restart();
            // std::cout << "nextScreenLogic:" << logTime.asMilliseconds() << std::endl;
            while (window.pollEvent(event))
            {
                switch (event.type)
                {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::Resized:
                {
                    // update the view to the new size of the window
                    sf::FloatRect visibleArea(0.f, 0.f, event.size.width, event.size.height);
                    sf::View view(visibleArea);
                    view.setCenter(400, 300);
                    window.setView(view);
                    break;
                }
                default:
                    break;
                }
            }
            logTime = test_clock.restart();
            // std::cout << "pollevent:" << logTime.asMicroseconds() << std::endl;
        }
    }
}

void ScreenManager::nextScreenLogic()
{
    // double states stateMachine：outter nextScreen, inner currentScreen
    switch (currentScreen->nextScreenLogic(window))
    {
    case SCREEN::PAUSE:
        currentScreen = &pauseScreen;
        break;
    case SCREEN::GAME:
        currentScreen = &gameScreen;
        break;
    case SCREEN::START:
        switch (currentScreen->getScreenEnum())
        {
        case SCREEN::START:
            break;

        default:
            gameScreen.restart();
            break;
        }
        currentScreen = &startScreen;
        break;

    case SCREEN::DEATH:
        switch (currentScreen->getScreenEnum())
        {
        case SCREEN::DEATH:
            break;

        default:
            gameScreen.restart();
            deathScreen.restart();
            break;
        }
        currentScreen = &deathScreen;
        break;
    default:
        break;
    }
}
void ScreenManager::jumpTo(SCREEN screen)
{
}

ScreenManager &ScreenManager::getInstance()
{
    static ScreenManager mScreenManager;
    return mScreenManager;
}