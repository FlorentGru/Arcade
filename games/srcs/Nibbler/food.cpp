/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** food.cpp
*/

#include "food.hpp"

Food::Food()
{
    for (int i = 0; i < 1; ++i) {
        this->_fruits.push_back(arcDisplay::RectInfo());
        this->_fruits.at(i).setAscii(' ');
        this->_fruits.at(i).setColor(255, 0, 0);
        this->_fruits.at(i).setSize(1, 1);
    }
}

bool Food::eatFruits(const Snake &snake)
{
    std::pair<int, int> pos = snake.getSnake().at(0).getPos();
        if (_fruits.at(0).getPos().first == pos.first && _fruits.at(0).getPos().second == pos.second) {
            return (true);
        }
    return (false);
}

const std::vector<arcDisplay::RectInfo> &Food::getFruits() const
{
    return (this->_fruits);
}

int Food::getWidth()
{
    return (this->_width);
}

int Food::getHeight()
{
    return (this->_height);
}

void Food::setWidth(unsigned int width)
{
    this->_width = width;
}

void Food::setHeight(unsigned int height)
{
    this->_height = height;
}

void Food::setPosFood(const Snake &snake)
{
    for (size_t i = 0; i < _fruits.size(); ++i) {
        int x = 1 + std::rand() % (_width - 1);
        int y = 1 + std::rand() % (_height - 1);
        if (x != snake.getSnake().at(0).getPos().first && y != snake.getSnake().at(0).getPos().second)
            _fruits.at(i).setPos(x, y);
    }
}