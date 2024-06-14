/*
 * @Author: vic123 zhangzc_efz@163.com
 * @Date: 2024-06-01 15:50:53
 * @LastEditors: vic123 zhangzc_efz@163.com
 * @LastEditTime: 2024-06-14 21:20:46
 * @FilePath: \SFML-snake\src\screen\screenManager.hpp
 * @Description:
 *
 * Copyright (c) 2024 by vic123, All Rights Reserved.
 */
#pragma once
#include "gameScreen.hpp"
#include "pauseScreen.hpp"
#include "startScreen.hpp"
#include "deathScreen.hpp"
#include "../utils/Constants.hpp"
#include <SFML/Audio.hpp>
class ScreenManager
{
private:
    sf::RenderWindow window;
    IScreen *currentScreen;
    PauseScreen &pauseScreen;
    GameScreen &gameScreen;
    StartScreen &startScreen;
    DeathScreen &deathScreen;
    sf::Music music;
public:
    void run();
    static ScreenManager &getInstance();

    ScreenManager(ScreenManager const &) = delete; // make sure no copies of SnakeManager may exist
    void operator=(ScreenManager const &) = delete;

private:
    ScreenManager();
    void nextScreenLogic();
    void jumpTo(SCREEN screen);
};