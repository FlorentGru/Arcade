/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** InitWindow.cpp
*/

#include "InitWindow.hpp"

InitWindow::InitWindow(unsigned int width, unsigned int height) : _width(width), _height(height)
{
    this->_frame = 30;
    this->_name = "Arcade";
}

/*###############################
########### GETTER ##############
###############################*/

unsigned int InitWindow::getWidth() const
{
    return (this->_width);
}

unsigned int InitWindow::getHeight() const
{
    return (this->_height);
}

const std::string &InitWindow::getName() const
{
    return (this->_name);
}

unsigned int InitWindow::getFrame() const
{
    return (this->_frame);
}

/*###############################
########### SETTER ##############
###############################*/

void InitWindow::setWidth(unsigned int width)
{
    this->_width = width;
}

void InitWindow::setHeight(unsigned int height)
{
    this->_height = height;
}

void InitWindow::setName(const std::string &name)
{
    this->_name = name;
}

void InitWindow::setFrame(unsigned int frame)
{
    this->_frame = frame;
}