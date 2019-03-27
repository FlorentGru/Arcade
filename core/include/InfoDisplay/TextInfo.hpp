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
        unsigned int _size;
        std::vector<unsigned char> _color;
        std::string _font;
        std::pair<float, float> _pos;
    public:
        explicit TextInfo(const std::string &text = "no_text", unsigned int size = 30, const std::string &font = "");

        enum TypeInfoDisplay getType() const override;

        const std::string &getText() const;
        const std::pair<float, float> &getPos() const;
        unsigned int getSize() const;
        const std::vector<unsigned char> &getColor() const;
        const std::string &getFont() const;

        void setText(const std::string &);
        void setSize(unsigned int);
        void setColor(unsigned char, unsigned char, unsigned char);
        void setFont(const std::string &);
        void setPos(float, float);
    };
} // arcDisplay


#endif