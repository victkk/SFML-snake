/*
 * @Author: vic123 zhangzc_efz@163.com
 * @Date: 2024-06-01 15:58:19
 * @LastEditors: vic123 zhangzc_efz@163.com
 * @LastEditTime: 2024-06-14 17:14:21
 * @FilePath: \SFML-snake\src\UI\button.cpp
 * @Description:
 *
 * Copyright (c) 2024 by vic123, All Rights Reserved.
 */
#include "button.hpp"
Button::Button(const std::string &buttonText)
{
    if (!font.loadFromFile("../../resources/font/retro-pixel-font/arcade/retro-pixel-arcade.otf"))
    {
        std::cout << "fuck! where is the font?(calling from button.cpp)";
    }
    text.setFont(font);
    text.setString(buttonText);
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(24);
    isClicked = false;
    shape.setFillColor(sf::Color::Blue);
    shape.setSize({200, 50});
    frame.setFillColor(sf::Color::Blue);
    frame.setSize({206, 56});
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

    auto mousePos = static_cast<sf::Vector2f>(window.mapPixelToCoords(sf::Mouse::getPosition(window)));
    isHovered = shape.getGlobalBounds().contains(mousePos);
    if (isHovered)
    {
        shape.setFillColor(sf::Color(255, 0, 0, 255)); // 如果鼠标悬停在按钮上，则改变颜色
        frame.setFillColor(sf::Color(0, 0, 0, 255));   // 如果鼠标悬停在按钮上，则改变颜色
    }
    else
    {
        shape.setFillColor(sf::Color(255, 0, 0, 128)); // 否则恢复原色
        frame.setFillColor(sf::Color(0, 0, 0, 128));
    }

    // 检测鼠标点击
    if (isHovered && sf::Mouse::isButtonPressed(sf::Mouse::Left))
    {
        // 这里可以放置点击后的处理逻辑
        isClicked = true;
        // std::cout << "Button clicked!" << std::endl;
    }
    else
    {
        isClicked = false;
    }
}

void Button::setPosition(const sf::Vector2f &position)
{
    shape.setPosition(position);
    frame.setPosition(sf::Vector2f(position.x - 3, position.y - 3));
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
    target.draw(frame, states);
    target.draw(shape, states);

    target.draw(text, states);
}
