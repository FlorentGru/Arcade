/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** WindowInfo.cpp
*/

#include "WindowInfo.hpp"

arcDisplay::WindowInfo::WindowInfo(bool close)
{
    this->_close = close;
}

bool arcDisplay::WindowInfo::isClosed() const
{
    return (this->_close);
}

void arcDisplay::WindowInfo::setClose(bool close)
{
    this->_close = close;
}

arcDisplay::TypeInfoDisplay arcDisplay::WindowInfo::getType() const
{
    return (arcDisplay::WINDOW);
}