/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** SpriteInfo.cpp
*/

#include "SpriteInfo.hpp"

arcDisplay::SpriteInfo::SpriteInfo()
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

arcDisplay::TypeInfoDisplay arcDisplay::SpriteInfo::getType() const
{
    return (arcDisplay::SPRITE);
}

/*###############################
## SETTER AND GETTER
###############################*/

const std::pair<int, int> &arcDisplay::SpriteInfo::getPosRect() const
{
    return (this->_posRect);
}

const std::pair<int, int> &arcDisplay::SpriteInfo::getSizeRect() const
{
    return (this->_sizeRect);
}

void arcDisplay::SpriteInfo::setPosRect(int x, int y)
{
    this->_posRect = std::make_pair(x, y);
}

void arcDisplay::SpriteInfo::setSizeRect(int x, int y)
{
    this->_sizeRect = std::make_pair(x, y);
}