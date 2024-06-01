
#include "screenManager.hpp"
ScreenManager::ScreenManager() : pauseScreen(), gameScreen(400), window(sf::VideoMode(800, 600), "SFML")
{
    currentScreen = &gameScreen;
}
void ScreenManager::run()
{
    sf::Clock clock;
    sf::Clock test_clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    // 主循环运行，直到窗口关闭
    while (window.isOpen())
    {
        // 事件处理
        sf::Time elapsedTime = clock.restart();
        timeSinceLastUpdate += elapsedTime;
        sf::Event event;

        if (timeSinceLastUpdate > timePerFrame)
        {

            while (timeSinceLastUpdate > timePerFrame)
                timeSinceLastUpdate -= timePerFrame;

            currentScreen->run(window);
            nextScreenLogic();
            while (window.pollEvent(event))
            {
                switch (event.type)
                {
                case sf::Event::Closed:
                    window.close();
                    break;

                default:
                    break;
                }
            }
        }
    }
}

void ScreenManager::nextScreenLogic()
{
    switch (currentScreen->nextScreenLogic(window))
    {
    case SCREEN::PAUSE:
        currentScreen = &pauseScreen;
        break;
    case SCREEN::GAME:
        currentScreen = &gameScreen;
        break;
    default:
        break;
    }
}
void ScreenManager::jumpTo(SCREEN screen){

}