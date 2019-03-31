/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** snake.cpp
*/

#include "snake.hpp"
#include <iostream>

Snake::Snake()
{
    for (int i = 0; i < 4; ++i) {
        this->body.push_back(arcDisplay::RectInfo());
        this->body.at(i).setAscii(' ');
        this->body.at(i).setColor(10, 255, 100);
        this->body.at(i).setSize(1, 1);

        this->nextMove.push_back(std::pair<int, int>(1, 0));
    }
}

bool Snake::eatItself(int x, int y)
{
    x += body.at(0).getPos().first;
    y += body.at(0).getPos().second;

    for (auto &rect : body) {
        if (rect.getPos().first == x && rect.getPos().second == y) {
            return (true);
        }
    }
    return (false);
}

bool Snake::move(int x, int y)
{
    std::vector<std::pair<int, int>> newMove;
    
    newMove.push_back(std::pair<int, int>(0, 0));
    if (eatItself(x, y))
        return (false);
    this->nextMove.at(0) = std::pair<int, int>(x, y);
    for (size_t i = 0; i < this->body.size(); ++i) {
        x = body.at(i).getPos().first + this->nextMove.at(i).first;
        y = body.at(i).getPos().second + this->nextMove.at(i).second;
        this->body.at(i).setPos(x, y);
    }
    for (size_t i = 0; i < this->nextMove.size() - 1; i++) {
        newMove.push_back(nextMove.at(i));
    }
    nextMove = newMove;
    if (body.at(0).getPos().first > _width - 1 || body.at(0).getPos().second > _height - 1 || body.at(0).getPos().first == 0 || body.at(0).getPos().second == 0)
        return (false);
    return (true);
}

void Snake::grow()
{
    std::pair<int, int> pos = body.back().getPos();
    std::pair<int, int> move = nextMove.back();

    this->body.push_back(arcDisplay::RectInfo());
    this->nextMove.push_back(move);
    
    body.back().setPos(pos.first - move.first, pos.second - move.second);

    body.back().setSize(1, 1);
    body.back().setAscii(' ');
    body.back().setColor(10, 255, 99);
    body.back().setTexture("");
}

const std::vector<arcDisplay::RectInfo> &Snake::getSnake() const
{
    return (this->body);
}

int Snake::getWidth()
{
    return (this->_width);
}

int Snake::getHeight()
{
    return (this->_height);
}

void Snake::setWidth(unsigned int width)
{
    this->_width = width;
}

void Snake::setHeight(unsigned int height)
{
    this->_height = height;
}

void Snake::setPosSnake(int x, int y)
{
    for (size_t i = 0; i < body.size(); ++i) {
        body.at(i).setPos(x, y);
        x--;
    }
}