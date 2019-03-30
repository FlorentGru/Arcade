/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** snake.hpp
*/

#ifndef _SNAKE_HPP_
#define _SNAKE_HPP_

#include "RectInfo.hpp"
#include <vector>
#include <string>

class Snake
{
private:
    std::vector<arcDisplay::RectInfo> body;
    std::vector<std::pair<int, int>> nextMove;

    unsigned int width;
    unsigned int height;

public:
    Snake();

    bool eatItself(int x, int y);
    bool move(int x, int y);

    const std::vector<arcDisplay::RectInfo> &getSnake() const;
};

#endif //_SNAKE_HPP_