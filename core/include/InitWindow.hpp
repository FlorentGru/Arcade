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
    size_t _width;
    size_t _height;
    std::string _name;
    size_t _frame;

    std::vector<std::string> _textures;
    std::vector<std::string> _sounds;
    std::vector<std::string> _fonts;
public:
    InitWindow(size_t width, size_t height);
    ~InitWindow();

    size_t getWidth() const;
    size_t getHeight() const;
    const std::string &getName() const;
    size_t getFrame() const;

    const std::vector<std::string> &getTextures() const;
    const std::vector<std::string> &getSounds() const;
    const std::vector<std::string> &getFonts() const;

    void setWidth(size_t);
    void setHeight(size_t);
    void setName(const std::string &);
    void setFrame(size_t);

    void setTextures(const std::vector<std::string> &);
    void setSounds(const std::vector<std::string> &);
    void setFonts(const std::vector<std::string> &);
};

#endif