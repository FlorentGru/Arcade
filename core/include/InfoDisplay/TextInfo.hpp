/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** TextInfo.hpp
*/

#ifndef TEXTINFO_HPP
#define TEXTINFO_HPP

#include "IInfoDisplay.hpp"
#include <string>
#include <vector>
#include <utility>

namespace arcDisplay
{
    class TextInfo : public IInfoDisplay
    {
    private:
        std::string _text;
        std::string _font;
        size_t _size;
        std::pair<float, float> _pos;
        std::vector<unsigned char> _color;
    public:
        TextInfo();

        TypeInfoDisplay getType() const;

        const std::string &getText() const;
        const std::pair<float, float> &getPos() const;
        size_t getSize() const;
        const std::vector<unsigned char> &getColor() const;
        const std::string &getFont() const;

        void setText(const std::string &);
        void setSize(size_t);
        void setColor(const unsigned char, const unsigned char, const unsigned char);
        void setFont(const std::string &);
        void setPos(const float, const float);
    };
} // arcDisplay


#endif