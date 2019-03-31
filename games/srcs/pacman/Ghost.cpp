/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Ghost.cpp
*/

#include "../../include/Ghost.hpp"
#include <iostream>
#include <ctime>

Ghost::Ghost(float x, float y)
{
    this->rect.setAscii(' ');
    this->rect.setSize(1, 1);
    this->rect.setColor(255, 0, 255);
    this->rect.setTexture("");
    this->rect.setPos(x, y);

    this->nextMove = std::pair<int, int>(-1, 0);
    this->posMap = std::pair<int, int>(x, y);

    std::srand(std::time(nullptr));
}

void Ghost::move(int count, const std::vector<std::string> &map)
{
    std::vector<std::pair<int, int>> moves;

    if (count != 0) {
        rect.setPos(rect.getPos().first + static_cast<float>(nextMove.first / 10.0), rect.getPos().second + static_cast<float>(nextMove.second / 10.0));
        return;
    }

    if (map[posMap.second - 20 + 1][posMap.first - 20] != 'X' && nextMove.second != -1) {
        moves.emplace_back(std::pair<int, int>(0, 1));
    }
    if (map[posMap.second - 20 - 1][posMap.first - 20] != 'X' && nextMove.second != 1) {
        moves.emplace_back(std::pair<int, int>(0, -1));
    }
    if (map[posMap.second - 20][posMap.first - 20 + 1] != 'X' && nextMove.first != -1) {
        moves.emplace_back(std::pair<int, int>(1, 0));
    }
    if (map[posMap.second - 20][posMap.first - 20 - 1] != 'X' && nextMove.first != 1) {
        moves.emplace_back(std::pair<int, int>(-1, 0));
    }
    if (!moves.empty())
        nextMove = moves.at(std::rand() % moves.size());
    else
        nextMove = std::pair<int, int>(0, 0);
    posMap.first += nextMove.first;
    posMap.second += nextMove.second;
    rect.setPos(rect.getPos().first + static_cast<float>(nextMove.first / 10.0), rect.getPos().second + static_cast<float>(nextMove.second / 10.0));
}

const arcDisplay::RectInfo &Ghost::getRect() const
{
    return (this->rect);
}