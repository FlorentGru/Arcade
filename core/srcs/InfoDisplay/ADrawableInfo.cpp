/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** ADrawableInfo.hpp
*/

#include "ADrawableInfo.hpp"

const std::pair<float, float> &arcDisplay::ADrawableInfo::getPos() const
{
    return (this->_pos);
}

const std::pair<float, float> &arcDisplay::ADrawableInfo::getSize() const
{
    return (this->_size);
}

const std::vector<unsigned char> &arcDisplay::ADrawableInfo::getColor() const
{
    return (this->_color);
}

char arcDisplay::ADrawableInfo::getAscii() const
{
    return (this->_ascii);
}

const std::string &arcDisplay::ADrawableInfo::getTexture() const
{
    return (this->_texture);
}

void arcDisplay::ADrawableInfo::setPos(float x, float y)
{
    this->_pos.first = x;
    this->_pos.second = y;
}

void arcDisplay::ADrawableInfo::setSize(float width, float height)
{
    this->_size.first = width;
    this->_size.second = height;
}

void arcDisplay::ADrawableInfo::setColor(unsigned char r, unsigned char g, unsigned char b)
{
    this->_color.clear();
    this->_color.push_back(r);
    this->_color.push_back(g);
    this->_color.push_back(b);
}

void arcDisplay::ADrawableInfo::setAscii(char ascii)
{
    this->_ascii = ascii;
}

void arcDisplay::ADrawableInfo::setTexture(const std::string &texture)
{
    this->_texture = texture;
}