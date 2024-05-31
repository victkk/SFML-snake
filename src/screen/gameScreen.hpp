#include "IScreen.hpp"
#include "../entity/snakeManager.hpp"
#include "../entity/foodManager.hpp"

class GameScreen : public IScreen
{
private:
    SnakeManager snakeManager;
    FoodManager foodManager;

public:
    GameScreen(int foodNum);
    void handleInput(sf::RenderWindow &window) override;
    void update() override;
    void render(sf::RenderWindow &window) override;
    void run(sf::RenderWindow &window) override;
    SCREEN nextScreenLogic(sf::RenderWindow &window) override;
};