/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** LineInfo.cpp
*/

#include "LineInfo.hpp"

arcDisplay::LineInfo::LineInfo()
{
    this->_pos = std::pair<float, float>(0, 0);
    this->_pos2 = std::pair<float, float>(0, 0);
    this->_size = std::pair<float, float>(0, 0);
    this->_color.push_back(0);
    this->_color.push_back(0);
    this->_color.push_back(0);
    this->_ascii = ' ';
    this->_texture = "";
}

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