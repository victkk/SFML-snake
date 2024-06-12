/*
 * @Author: vic123 zhangzc_efz@163.com
 * @Date: 2024-06-01 15:50:53
 * @LastEditors: vic123 zhangzc_efz@163.com
 * @LastEditTime: 2024-06-11 21:18:07
 * @FilePath: \SFML-snake\src\screen\gameScreen.hpp
 * @Description:
 *
 * Copyright (c) 2024 by vic123, All Rights Reserved.
 */
#pragma once
#include "IScreen.hpp"
#include "../entity/snakeManager.hpp"
#include "../entity/foodManager.hpp"

class GameScreen : public IScreen
{
private:
    SnakeManager &snakeManager;
    FoodManager &foodManager;
    sf::RectangleShape rectangle;
    GameScreen();

public:
    static GameScreen &getInstance();

    void handleInput(sf::RenderWindow &window) override;
    void update() override;
    void render(sf::RenderWindow &window) override;
    void run(sf::RenderWindow &window) override;
    SCREEN nextScreenLogic(sf::RenderWindow &window) override;
    void restart();

    GameScreen(GameScreen const &) = delete; // make sure no copies of SnakeManager may exist
    void operator=(GameScreen const &) = delete;
};

extern sf::Vector2i topLeft;
extern sf::Vector2i buttomRight;