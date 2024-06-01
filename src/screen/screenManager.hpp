#include "gameScreen.hpp"
#include "pauseScreen.hpp"

class ScreenManager
{
private:
    sf::RenderWindow window;
    IScreen *currentScreen;
    PauseScreen pauseScreen;
    GameScreen gameScreen;

public:
    ScreenManager();
    void run();

private:
    void nextScreenLogic();
    void jumpTo(SCREEN screen);
};