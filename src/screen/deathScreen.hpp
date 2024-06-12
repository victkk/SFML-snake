#pragma once
#include "IScreen.hpp"
#include "../UI/button.hpp"
class DeathScreen : public IScreen
{
private:
    SCREEN ScreenEnum;
    Button startMenuButton;
    Button restartButton;
    sf::Texture texture;
    sf::Sprite sNoob;
    DeathScreen();

public:
    static DeathScreen &getInstance();
    void handleInput(sf::RenderWindow &window) override;
    void update() override;
    void render(sf::RenderWindow &window) override;
    void run(sf::RenderWindow &window) override;
    SCREEN nextScreenLogic(sf::RenderWindow &window) override;
    SCREEN getScreenEnum() override;
    DeathScreen(DeathScreen const &) = delete; // make sure no copies of SnakeManager may exist
    void operator=(DeathScreen const &) = delete;
};