/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** TextInfo.hpp
*/

#ifndef TEXTINFO_HPP_
#define TEXTINFO_HPP_

#include <string>
#include <vector>
#include "IInfoDisplay.hpp"

namespace arcDisplay
{
    class TextInfo : public IInfoDisplay
    {
        private:
            std::string _text;
            size_t _size;
            std::vector <unsigned char> _color;
            std::string _font;
            std::pair<float, float> _pos;

        public:
            explicit TextInfo(const std::string &text = "", size_t size = 20, const std::string &font = "");

            const std::string &getText() const;
            void setText(const std::string &text);

            size_t getSize() const;
            void setSize(size_t size);

            const std::string &getFont() const;
            void setFont(const std::string &font);

            const std::vector<unsigned char> &getColor() const;
            void setColor(unsigned char r, unsigned char g, unsigned char b);

            const std::pair<float, float> &getPos() const;
            void setPos(float x, float y);

            enum TypeInfoDisplay getType() const override;
    };
}

#endif // !TEXTINFO_HPP_