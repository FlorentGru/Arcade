/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** CircleInfo.cpp
*/

#include "CircleInfo.hpp"

arcDisplay::CircleInfo::CircleInfo()
{
    this->_pos = std::pair<float, float>(0, 0);
    this->_size = std::pair<float, float>(0, 0);
    this->_color.push_back(0);
    this->_color.push_back(0);
    this->_color.push_back(0);
    this->_ascii = ' ';
    this->_texture = "";
}

arcDisplay::TypeInfoDisplay arcDisplay::CircleInfo::getType() const
{
    return (arcDisplay::CIRCLE);
}