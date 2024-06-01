#include <SFML/Graphics.hpp>
#include <iostream>
#include "IUIComponent.hpp"
class Button : public sf::Drawable
{
private:
    sf::RectangleShape shape;
    sf::Text text;
    bool isHovered;
    bool isClicked;

public:
    // 构造函数：接收字体和按钮文本
    Button(const std::string &buttonText);

    // 更新函数：更新按钮状态
    void update(sf::RenderWindow &window, const sf::Time &dt = sf::seconds(0));

    // 设置按钮位置
    void setPosition(const sf::Vector2f &position);

    // 获取按钮位置
    sf::Vector2f getPosition() const;

    // 设置按钮大小
    void setSize(const sf::Vector2f &size);

    // 获取按钮大小
    sf::Vector2f getSize() const;

    bool getIsClicked() const;

protected:
    // 绘制函数：绘制按钮到渲染目标
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
};
