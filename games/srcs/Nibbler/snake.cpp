/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** snake.cpp
*/

#include "snake.hpp"

Snake::Snake()
{
    for (int i = 0; i < 4; ++i) {
        this->body.push_back(arcDisplay::RectInfo());
        this->body.at(i).setAscii('o');
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
    this->nextMove.at(0) = std::pair<int, int>(x, y);

    if (eatItself(x, y)) {
            return (false);    
        for (size_t i = 0; i < this->body.size(); ++i) {
            x = body.at(i).getPos().first + this->nextMove.at(i).first;
            y = body.at(i).getPos().second + this->nextMove.at(i).second;
            this->body.at(i).setPos(x, y);
            if (i < this->nextMove.size() - 1) {
                this->nextMove.at(i + 1) = this->nextMove.at(i);
            }
        }
        return (true);
    }
}

const std::vector<arcDisplay::RectInfo> &Snake::getSnake() const
{
    return (this->body);
}