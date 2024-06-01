#include "button.hpp"
Button::Button(const std::string &buttonText)
{

    text.setString(buttonText);
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(24);
    isClicked = false;
    shape.setFillColor(sf::Color::Blue);
    shape.setSize({200, 50});
    // 使文字居中显示
    text.setPosition(shape.getPosition() + sf::Vector2f(shape.getSize().x / 2 - text.getLocalBounds().width / 2,
                                                        shape.getSize().y / 2 - text.getLocalBounds().height / 1.5));
}

bool Button::getIsClicked() const
{
    return isClicked;
}
void Button::update(sf::RenderWindow &window, const sf::Time &dt)
{
    // 更新按钮状态：检测鼠标悬停状态
    auto mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
    isHovered = shape.getGlobalBounds().contains(mousePos);
    if (isHovered)
    {
        shape.setFillColor(sf::Color::Red); // 如果鼠标悬停在按钮上，则改变颜色
    }
    else
    {
        shape.setFillColor(sf::Color::Blue); // 否则恢复原色
    }

    // 检测鼠标点击
    if (isHovered && sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        // 这里可以放置点击后的处理逻辑
        isClicked = true;
        std::cout << "Button clicked!" << std::endl;
    }
    else
    {
        isClicked = false;
    }
}

void Button::setPosition(const sf::Vector2f &position)
{
    shape.setPosition(position);
    text.setPosition(position + sf::Vector2f(shape.getSize().x / 2 - text.getLocalBounds().width / 2,
                                             shape.getSize().y / 2 - text.getLocalBounds().height / 1.5));
}

sf::Vector2f Button::getPosition() const
{
    return shape.getPosition();
}

void Button::setSize(const sf::Vector2f &size)
{
    shape.setSize(size);
}

sf::Vector2f Button::getSize() const
{
    return shape.getSize();
}

void Button::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(shape, states);
    target.draw(text, states);
}
