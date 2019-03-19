/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** InitWindow.cpp
*/

#include "InitWindow.hpp"

InitWindow::InitWindow(size_t width, size_t height) : _width(width), _height(height)
{

}

/*###############################
########### GETTER ##############
###############################*/

size_t InitWindow::getWidth() const
{
    return (this->_width);
}

size_t InitWindow::getHeight() const
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

void InitWindow::setWidth(size_t width)
{
    this->_width = width;
}

void InitWindow::setHeight(size_t height)
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
    this->_sounds = sound;
}

void InitWindow::setFonts(const std::vector<std::string> &fonts)
{
    this->_fonts = fonts;
}