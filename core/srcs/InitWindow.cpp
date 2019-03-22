/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** InitWindow.cpp
*/

#include "InitWindow.hpp"

InitWindow::InitWindow(unsigned int width, unsigned int height) : _width(width), _height(height)
{

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

size_t InitWindow::getFrame() const
{
    return (this->_frame);
}

const std::vector<std::string> &InitWindow::getTextures() const
{
    return (this->_textures);
}

const std::vector<std::string> &InitWindow::getSounds() const
{
    return (this->_sounds);
}

const std::vector<std::string> &InitWindow::getFonts() const
{
    return (this->_fonts);
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

void InitWindow::setFrame(size_t frame)
{
    this->_frame = frame;
}

void InitWindow::setTextures(const std::vector<std::string> &textures)
{
    this->_textures = textures;
}

void InitWindow::setSounds(const std::vector<std::string> &sounds)
{
    this->_sounds = sounds;
}

void InitWindow::setFonts(const std::vector<std::string> &fonts)
{
    this->_fonts = fonts;
}