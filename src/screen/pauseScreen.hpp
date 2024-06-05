#pragma once
#include "IScreen.hpp"
#include "../UI/button.hpp"
class PauseScreen : public IScreen
{
private:
    Button resumeButton;

public:
    PauseScreen();
    void handleInput(sf::RenderWindow &window) override;
    void update() override;
    void render(sf::RenderWindow &window) override;
    void run(sf::RenderWindow &window) override;
    SCREEN nextScreenLogic(sf::RenderWindow &window) override;
};