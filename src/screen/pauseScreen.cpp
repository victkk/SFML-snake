
#include "pauseScreen.hpp"
PauseScreen::PauseScreen() : resumeButton("resume")
{
    resumeButton.setPosition(sf::Vector2f(300, 200));
}
void PauseScreen::run(sf::RenderWindow &window)
{
    handleInput(window);
    update();
    render(window);
}

void PauseScreen::handleInput(sf::RenderWindow &window)
{
    resumeButton.update(window, sf::seconds(0));
}

void PauseScreen::update()
{
    ;
}

void PauseScreen::render(sf::RenderWindow &window)
{
    window.clear(sf::Color::White);
    window.draw(resumeButton);
    window.display();
}
SCREEN PauseScreen::nextScreenLogic(sf::RenderWindow &window)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        while (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            ;
        }
        return SCREEN::GAME;
    }
    return SCREEN::PAUSE;
}