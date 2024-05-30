#pragma once
#include <vector>
#include "food.hpp"
#include "snake.hpp"
#include "snakeManager.hpp"
#include <vector>
#include <SFML/Graphics.hpp>
class FoodManager
{
private:
    std::vector<Food> foods;
    int foodBornSpeed;
    int cnt;

public:
    FoodManager(int foodNum);
    void update(std::vector<Snake> &snakes);

    void render(sf::RenderWindow &window);
};
