#pragma once
#include "IScreen.hpp"
#include "../UI/button.hpp"
class StartScreen : public IScreen
{
private:
    SCREEN ScreenEnum;
    Button startButton;
    sf::Text text1;
    sf::Text text2;
    sf::Font font;
    StartScreen();

public:
    static StartScreen &getInstance();

    void handleInput(sf::RenderWindow &window) override;
    void update() override;
    void render(sf::RenderWindow &window) override;
    void run(sf::RenderWindow &window) override;
    SCREEN nextScreenLogic(sf::RenderWindow &window) override;
    SCREEN getScreenEnum() override;
    StartScreen(StartScreen const &) = delete; // make sure no copies of SnakeManager may exist
    void operator=(StartScreen const &) = delete;
};