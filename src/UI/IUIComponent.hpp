#pragma once
#include <SFML/Graphics.hpp>

// UIComponent是一个抽象基类，用于所有UI组件
class IUIComponent : public sf::Drawable
{
public:
    // 构造函数
    IUIComponent() = default;

    // 虚析构函数，确保派生类的析构函数被调用
    virtual ~IUIComponent() {}

    // 更新组件状态，通过window的引用查询输入状态
    virtual void update(sf::RenderWindow &window, const sf::Time &dt) = 0;

    // 设置组件位置
    virtual void setPosition(const sf::Vector2f &position) = 0;

    // 获取组件位置
    virtual sf::Vector2f getPosition() const = 0;

    // 设置组件大小
    virtual void setSize(const sf::Vector2f &size) = 0;

    // 获取组件大小
    virtual sf::Vector2f getSize() const = 0;

protected:
    // 重写draw函数，是SFML的绘制接口
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const = 0;
};