#pragma once
#include "IScreen.hpp"
#include "../UI/button.hpp"
class PauseScreen : public IScreen
{
private:
    Button resumeButton;
    Button startMenuButton;
    PauseScreen();

public:
    static PauseScreen &getInstance();
    void handleInput(sf::RenderWindow &window) override;
    void update() override;
    void render(sf::RenderWindow &window) override;
    void run(sf::RenderWindow &window) override;
    SCREEN nextScreenLogic(sf::RenderWindow &window) override;

    PauseScreen(PauseScreen const &) = delete; // make sure no copies of SnakeManager may exist
    void operator=(PauseScreen const &) = delete;
};