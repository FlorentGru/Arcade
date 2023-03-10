/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** TextInfo.cpp
*/

#include "TextInfo.hpp"

arcDisplay::TextInfo::TextInfo(const std::string &text, size_t size, const std::string &font)
{
    this->_text = text;
    setColor(255, 255, 255);
    this->_size = size;
    this->_font = font;
}

/*###############################
## GET TYPE
###############################*/

arcDisplay::TypeInfoDisplay arcDisplay::TextInfo::getType() const
{
    return (arcDisplay::TEXT);
}

/*###############################
## SETTER AND GETTER
###############################*/

const std::string &arcDisplay::TextInfo::getText() const
{
    return (this->_text);
}

const std::pair<float, float> &arcDisplay::TextInfo::getPos() const
{
    return (this->_pos);
}

size_t arcDisplay::TextInfo::getSize() const
{
    return (this->_size);
}

const std::vector<unsigned char> &arcDisplay::TextInfo::getColor() const
{
    return (this->_color);
}

const std::string &arcDisplay::TextInfo::getFont() const
{
    return (this->_font);
}

void arcDisplay::TextInfo::setText(const std::string &str)
{
    this->_text = str;
}

void arcDisplay::TextInfo::setSize(size_t size)
{
    this->_size = size;
}

void arcDisplay::TextInfo::setColor(unsigned char r, unsigned char g, unsigned char b)
{
    this->_color.push_back(r);
    this->_color.push_back(g);
    this->_color.push_back(b);
}

void arcDisplay::TextInfo::setFont(const std::string &str)
{
    this->_font = str;
}

void arcDisplay::TextInfo::setPos(const float x, const float y)
{
    this->_pos = std::make_pair(x, y);
}