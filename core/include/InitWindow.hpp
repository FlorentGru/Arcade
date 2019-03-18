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
    int width;
    int height;
    std::string name;
    int frame;

    std::vector<std::string> textures;
    std::vector<std::string> sounds;
    std::vector<std::string> fonts;
public:
    int getWidth() const;
    int getHeight() const;
    const std::string &getName() const;

    const std::vector<std::string> &getTextures() const;
    const std::vector<std::string> &getSounds() const;
    const std::vector<std::string> &getFonts() const;

    void setWidth(int);
    void setHeight(int);
    void setName(const std::string &);

    void setTextures(const std::vector<std::string> &);
    void setSounds(const std::vector<std::string> &);
    void setFonts(const std::vector<std::string> &);
};

#endif