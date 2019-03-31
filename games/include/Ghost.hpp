/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Ghost.hpp
*/

#ifndef OOP_ARCADE_2018_GHOST_HPP
#define OOP_ARCADE_2018_GHOST_HPP


#include "RectInfo.hpp"

class Ghost
{
private:
    arcDisplay::RectInfo rect;
    std::pair<int, int> posMap;
    std::pair<int, int> nextMove;
public:
    Ghost(float, float);

    void move(int count, const std::vector<std::string> &map);
    const arcDisplay::RectInfo &getRect() const;
};


#endif //OOP_ARCADE_2018_GHOST_HPP
