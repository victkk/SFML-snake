#pragma once
#include "snake.hpp"

class SnakeManager
{
private:
    std::vector<Snake> snakes;

public:
    SnakeManager();
    void handleInput(sf::RenderWindow &window);
    void deathJudge();
    void render(sf::RenderWindow &window);
    void update();
};