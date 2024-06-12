/*
 * @Author: vic123 zhangzc_efz@163.com
 * @Date: 2024-06-01 15:50:53
 * @LastEditors: vic123 zhangzc_efz@163.com
 * @LastEditTime: 2024-06-12 14:14:55
 * @FilePath: \SFML-snake\src\screen\IScreen.hpp
 * @Description:
 *
 * Copyright (c) 2024 by vic123, All Rights Reserved.
 */
#pragma once
#include <SFML/Graphics.hpp>
enum class SCREEN
{
    GAME,
    PAUSE,
    START,
    DEATH
};

class IScreen
{
public:
    virtual void handleInput(sf::RenderWindow &window) = 0;
    virtual void update() = 0;
    virtual void render(sf::RenderWindow &window) = 0;
    virtual void run(sf::RenderWindow &window) = 0;
    virtual SCREEN getScreenEnum()=0;
    virtual SCREEN nextScreenLogic(sf::RenderWindow &window) = 0;

};
