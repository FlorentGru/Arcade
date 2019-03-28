/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** InitWindow.hpp
*/

#ifndef INITWINDOW_HPP
#define INITWINDOW_HPP

#include <vector>
#include <string>

class InitWindow
{
private:
    unsigned int _width;
    unsigned int _height;
    std::string _name;
    unsigned int _frame;
public:
    InitWindow(unsigned int width, unsigned int height);

    unsigned int getWidth() const;
    unsigned int getHeight() const;
    const std::string &getName() const;
    unsigned int getFrame() const;

    void setWidth(unsigned int);
    void setHeight(unsigned int);
    void setName(const std::string &);
    void setFrame(unsigned int);
};

#endif