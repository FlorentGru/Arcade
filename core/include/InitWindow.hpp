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

    std::vector<std::string> _textures;
    std::vector<std::string> _sounds;
    std::vector<std::string> _fonts;
public:
    InitWindow(unsigned int width, unsigned int height);

    unsigned int getWidth() const;
    unsigned int getHeight() const;
    const std::string &getName() const;
    unsigned int getFrame() const;

    const std::vector<std::string> &getTextures() const;
    const std::vector<std::string> &getSounds() const;
    const std::vector<std::string> &getFonts() const;

    void setWidth(unsigned int);
    void setHeight(unsigned int);
    void setName(const std::string &);
    void setFrame(unsigned int);

    void setTextures(const std::vector<std::string> &);
    void setSounds(const std::vector<std::string> &);
    void setFonts(const std::vector<std::string> &);
};

#endif