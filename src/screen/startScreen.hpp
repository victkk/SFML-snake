#pragma once
#include "IScreen.hpp"
#include "../UI/button.hpp"
class StartScreen : public IScreen
{
private:
    Button startButton;
    sf::Text text1;
    sf::Text text2;
    sf::Font font;

public:
    StartScreen();
    void handleInput(sf::RenderWindow &window) override;
    void update() override;
    void render(sf::RenderWindow &window) override;
    void run(sf::RenderWindow &window) override;
    SCREEN nextScreenLogic(sf::RenderWindow &window) override;
};