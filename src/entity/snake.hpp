#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <vector>
#include <deque>
#include "../utils.hpp"
class Snake
{
private:
    float kNodeDist;
    std::vector<sf::Vector2f> snakeBody;
    sf::Vector2f direction;
    int speed;

public:
    Snake();
    void handleInput(sf::RenderWindow &window);
    void update();
    void render(sf::RenderWindow &window);
    void move();
    void Sprint();
};