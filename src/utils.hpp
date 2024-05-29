#include <SFML/Graphics.hpp>
#include <cmath>
sf::Vector2f normalize(const sf::Vector2f &v);
sf::Vector2f operator*(const sf::Vector2f &v, float scalar);
sf::Vector2f operator*(float scalar, const sf::Vector2f &v);

sf::Texture createGradientTexture(unsigned int width, unsigned int height, sf::Color startColor, sf::Color endColor);

template <typename T>
T square(T x);

float V2fDist(sf::Vector2f a, sf::Vector2f b);