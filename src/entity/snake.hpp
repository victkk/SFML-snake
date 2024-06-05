#pragma once
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
    int bodyNodeNum;
    std::deque<sf::Vector2f> snakeBody;
    sf::Vector2f direction;
    int speed;
    sf::Texture texture;
    bool humanPlayer;
    int initial_x, initial_y;
    float maxAngularVelocity;

public:
    Snake(bool humanPlayer, int initial_x, int initial_y);

    void update();
    void render(sf::RenderWindow &window);
    void grow(int size);
    void setDirection(sf::RenderWindow &window, std::vector<Snake> &snakes);
    bool collision(sf::Vector2f point, float r);
    const sf::Vector2f &getHead();
    int getNodeNum();

private:
    void autoDrive(std::vector<Snake> &snakes, int xMin, int xMax, int yMin, int yMax);
    void move();
    void Sprint();
    void handleInput(sf::RenderWindow &window);
    void scaleUp();
};

extern sf::Time timePerFrame;