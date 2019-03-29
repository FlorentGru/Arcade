/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Rect.hpp
*/

#ifndef OOP_ARCADE_2018_LIBRECT_HPP
#define OOP_ARCADE_2018_LIBRECT_HPP

#include "RectInfo.hpp"
#include "TextInfo.hpp"

const int CHAR_SIZE = 15;

class Rect
{
private:
    arcDisplay::RectInfo rect;
    arcDisplay::TextInfo text;
public:
    explicit Rect(const std::string &);

    const arcDisplay::RectInfo &getRect() const;
    const arcDisplay::TextInfo &getText() const;

    void setAscii(char c);
    void setFont(const std::string &);
    void setPos(float, float, float, float);
    void setSize(float, float, unsigned int);
    void setColor(unsigned char, unsigned char, unsigned char);
};

#endif //OOP_ARCADE_2018_LIBRECT_HPP
