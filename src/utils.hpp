#pragma once
#include <SFML/Graphics.hpp>
#include <cmath>
#include <map>
sf::Vector2f normalize(const sf::Vector2f &v);
sf::Vector2f operator*(const sf::Vector2f &v, float scalar);
sf::Vector2f operator*(float scalar, const sf::Vector2f &v);

sf::Texture createGradientTexture(unsigned int width, unsigned int height, sf::Color startColor, sf::Color endColor);

template <typename T>
T square(T x);

float V2fDist(const sf::Vector2f &a, const sf::Vector2f &b);

sf::Vector2f turnWithBound(sf::Vector2f &current, sf::Vector2f &target, float angleBound);
sf::Vector2f angleDiff();
double vectorAngle(const sf::Vector2f &vec);
sf::Vector2f rotateVector(const sf::Vector2f &vec, float angle);
double calculateAngleDifference(const sf::Vector2f &vec1, const sf::Vector2f &vec2);

extern std::map<int, sf::Color> colorMap;
float V2fMhtDist(sf::Vector2f a, sf::Vector2f b);