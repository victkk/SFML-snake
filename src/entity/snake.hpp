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
    void setDirection(sf::Vector2f direction);
    bool collision(sf::Vector2f point, float r);
    const sf::Vector2f &getHead();
    int getNodeNum();
    bool isHumanPlayer();
    void setSpeed(bool isHighSpeed);
    int getSpeed();
    int getMaxAngularVelocity();
    sf::Vector2f getDirection();
    std::deque<sf::Vector2f> const &getSnakeBody();
    float getRadius();

private:
    void move();
    void Sprint();
    void scaleUp();
};

extern sf::Time timePerFrame;