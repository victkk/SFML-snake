#include "gameScreen.hpp"
GameScreen::GameScreen(int foodNum) : foodManager(foodNum), snakeManager()
{
}

void GameScreen::run(sf::RenderWindow &window)
{
    handleInput(window);
    update();
    render(window);
}

void GameScreen::handleInput(sf::RenderWindow &window)
{
    snakeManager.handleInput(window);
}

void GameScreen::update()
{
    snakeManager.update();
    foodManager.update(snakeManager.getSnakes());
}

void GameScreen::render(sf::RenderWindow &window)
{
    window.clear(sf::Color::Black);
    snakeManager.render(window);
    foodManager.render(window);
    window.display();
}
SCREEN GameScreen::nextScreenLogic(sf::RenderWindow &window)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
        while (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
        {
            ;
        }

        return SCREEN::PAUSE;
    }
    return SCREEN::GAME;
}