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

const arcDisplay::TypeInfoDisplay arcDisplay::LineInfo::getType() const
{
    return (arcDisplay::LINE);
}

/*###############################
## SETTER AND GETTER
###############################*/

void arcDisplay::LineInfo::setPosition2(const float x, const float y)
{
    this->_position2 = std::make_pair(x, y);
}

const std::pair<float, float> &arcDisplay::LineInfo::getPosition2() const
{
    return (this->_position2);
}