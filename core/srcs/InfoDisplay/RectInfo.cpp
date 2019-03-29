/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** RectInfo.cpp
*/

#include "RectInfo.hpp"

arcDisplay::RectInfo::RectInfo()
{
    this->_pos = std::pair<float, float>(0, 0);
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

arcDisplay::TypeInfoDisplay arcDisplay::RectInfo::getType() const
{
    return (arcDisplay::RECT);
}