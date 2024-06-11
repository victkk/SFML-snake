#pragma once
#include "IScreen.hpp"
#include "../UI/button.hpp"
class DeathScreen : public IScreen
{
private:
    Button startMenuButton;
    Button restartButton;
    sf::Texture texture;
    sf::Sprite sNoob;

public:
    DeathScreen();
    void handleInput(sf::RenderWindow &window) override;
    void update() override;
    void render(sf::RenderWindow &window) override;
    void run(sf::RenderWindow &window) override;
    SCREEN nextScreenLogic(sf::RenderWindow &window) override;
};