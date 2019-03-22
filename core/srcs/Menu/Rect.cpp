/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** LibRect.cpp
*/

#include "Rect.hpp"

Rect::Rect(const std::string &_text)
{
    this->text.setText(_text);
    this->text.setColor(255, 255, 255);

    this->rect.setColor(10, 100, 255);
}

void Rect::setSize(float width, float height, unsigned int size)
{
    this->rect.setSize(width, height);
    this->text.setSize(size);
}

void Rect::setFont(const std::string &font)
{
    this->text.setFont(font);
}

void Rect::setPos(float x, float y, float offsetX, float offsetY)
{
    this->rect.setPos(x, y);
    this->text.setPos(x + offsetX, y + offsetY);
}

void Rect::setAscii(char c)
{
    this->rect.setAscii(c);
}

const arcDisplay::RectInfo &Rect::getRect() const
{
    return (this->rect);
}

const arcDisplay::TextInfo &Rect::getText() const
{
    return (this->text);
}