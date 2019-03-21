/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** LibRect.hpp
*/

#ifndef OOP_ARCADE_2018_LIBRECT_HPP
#define OOP_ARCADE_2018_LIBRECT_HPP

#include "RectInfo.hpp"
#include "TextInfo.hpp"

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
    void setSize(float, float, size_t);
};

#endif //OOP_ARCADE_2018_LIBRECT_HPP