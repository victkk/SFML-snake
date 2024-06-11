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
    virtual SCREEN nextScreenLogic(sf::RenderWindow &window) = 0;
};
