/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** WindowInfo.cpp
*/

#include "WindowInfo.hpp"

arcDisplay::WindowInfo::WindowInfo()
{
    this->_close = false;
}

bool arcDisplay::WindowInfo::isClosed() const
{
    return (this->_close);
}

void arcDisplay::WindowInfo::setClose(bool close)
{
    this->_close = close;
}

const arcDisplay::TypeInfoDisplay arcDisplay::WindowInfo::getType() const
{
    return (arcDisplay::WINDOW);
}