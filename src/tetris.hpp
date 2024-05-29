/*
 * @Author: vic123 zhangzc_efz@163.com
 * @Date: 2024-05-27 22:20:15
 * @LastEditors: vic123 zhangzc_efz@163.com
 * @LastEditTime: 2024-05-29 09:46:32
 * @FilePath: \tetris-online\src\tetris.hpp
 * @Description:
 *
 * Copyright (c) 2024 by vic123, All Rights Reserved.
 */
#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

class Tetris
{

  static const std::uint32_t lines{20};
  static const std::uint32_t cols{10};
  static const std::uint32_t squares{4};
  static const std::uint32_t shapes{7};

  std::vector<std::vector<std::uint32_t>> area;
  std::vector<std::vector<std::uint32_t>> forms;

  struct Coords
  {
    std::uint32_t x, y;
  } z[squares], k[squares];

  std::shared_ptr<sf::RenderWindow> window;
  sf::Texture tiles, bg;
  std::shared_ptr<sf::Sprite> sprite, background;
  sf::Clock clock;
  sf::Font font;
  sf::Text txtScore, txtGameOver;

  int dirx, color, score;
  bool rotate, gameover;
  float timercount, delay;

protected:
  void events();
  void draw();
  void moveToDown();
  void setRotate();
  void resetValues();
  void changePosition();
  bool maxLimit();
  void setScore();

public:
  Tetris();
  void run();
};
