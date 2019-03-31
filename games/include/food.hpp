/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** food.hpp
*/

#ifndef _FOOD_HPP_
#define _FOOD_HPP_

#include "RectInfo.hpp"
#include "snake.hpp"
#include <vector>
#include <string>

class Food 
{
private:
    std::vector<std::pair<int, int>> posFood;
    std::vector<arcDisplay::RectInfo> _fruits;

    unsigned int _width;
    unsigned int _height;
public:
    Food();

    bool eatFruits(const Snake &snake);
    int getWidth();
    int getHeight();
    void setWidth(unsigned int width);
    void setHeight(unsigned int height);
    void setPosFood();

    const std::vector<arcDisplay::RectInfo> &getFruits() const;
};

#endif //_FOOD_HPP_