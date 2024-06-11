#include "deathScreen.hpp"
DeathScreen::DeathScreen() : startMenuButton("MainMenu"), restartButton("restart")
{
    startMenuButton.setPosition(sf::Vector2f(200, 500));
    restartButton.setPosition(sf::Vector2f(400, 500));
    texture.loadFromFile("../../resources/img/noob.png");
    sNoob.setTexture(texture);
}
void DeathScreen::run(sf::RenderWindow &window)
{
    handleInput(window);
    update();
    render(window);
}

void DeathScreen::handleInput(sf::RenderWindow &window)
{
    startMenuButton.update(window, sf::seconds(0));
    restartButton.update(window, sf::seconds(0));
}

void DeathScreen::update()
{
    ;
}

void DeathScreen::render(sf::RenderWindow &window)
{
    sf::Vector2u windowSize = window.getSize();
    sf::FloatRect spriteBounds = sNoob.getLocalBounds();
    sNoob.setOrigin(spriteBounds.width / 2, spriteBounds.height / 2);
    sNoob.setPosition(windowSize.x / 2.0f, windowSize.y / 2.0f);
    sNoob.setScale(0.5, 0.5);
    window.clear(sf::Color::Black);
    window.draw(startMenuButton);
    window.draw(restartButton);
    window.draw(sNoob);
    window.display();
}
SCREEN DeathScreen::nextScreenLogic(sf::RenderWindow &window)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        while (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            ;
        }
        return SCREEN::START;
    }
    if (restartButton.getIsClicked())
    {
        return SCREEN::GAME;
    }
    if (startMenuButton.getIsClicked())
    {
        return SCREEN::START;
    }
    return SCREEN::DEATH;
}