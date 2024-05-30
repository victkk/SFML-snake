#pragma once
#include <SFML/Graphics.hpp>
#include <cstdlib>
#include <ctime>
#include "../utils.hpp"
#include "snake.hpp"
class Food
{
private:
    sf::Vector2f pos;
    int velocity; // when eaten by snake, food flow to snake
    int score;    // also for color
    float radius;

public:
    Food();
    void render(sf::RenderWindow &window);
    bool update(Snake &snake); // return dist from snakehead
    int getScore();
};
