/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** LineInfo.cpp
*/

#include "LineInfo.hpp"

/*###############################
## GET TYPE
###############################*/

arcDisplay::TypeInfoDisplay arcDisplay::LineInfo::getType() const
{
    return (arcDisplay::LINE);
}

/*###############################
## SETTER AND GETTER
###############################*/

void arcDisplay::LineInfo::setPos2(const float x, const float y)
{
    this->_pos2 = std::make_pair(x, y);
}

const std::pair<float, float> &arcDisplay::LineInfo::getPos2() const
{
    return (this->_pos2);
}