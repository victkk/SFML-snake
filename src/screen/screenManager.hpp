/*
 * @Author: vic123 zhangzc_efz@163.com
 * @Date: 2024-06-01 15:50:53
 * @LastEditors: vic123 zhangzc_efz@163.com
 * @LastEditTime: 2024-06-11 09:30:51
 * @FilePath: \SFML-snake\src\screen\screenManager.hpp
 * @Description:
 *
 * Copyright (c) 2024 by vic123, All Rights Reserved.
 */
#pragma once
#include "gameScreen.hpp"
#include "pauseScreen.hpp"
#include "startScreen.hpp"
class ScreenManager
{
private:
    sf::RenderWindow window;
    IScreen *currentScreen;
    PauseScreen pauseScreen;
    GameScreen gameScreen;
    StartScreen startScreen;

public:
    ScreenManager();
    void run();

private:
    void nextScreenLogic();
    void jumpTo(SCREEN screen);
};