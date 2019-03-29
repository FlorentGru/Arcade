/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** DrawableInfo.hpp
*/

#ifndef ADRAWABLEINFO_HPP_
#define ADRAWABLEINFO_HPP_

#include <vector>
#include <string>
#include "IInfoDisplay.hpp"

namespace arcDisplay
{
    class ADrawableInfo : public IInfoDisplay
    {
        protected:
            std::string _texture;
            char _ascii;
            std::pair<float, float> _pos;
            std::pair<float, float> _size;
            std::vector<unsigned char> _color;

        public:

            virtual enum TypeInfoDisplay getType() const = 0;

            char getAscii() const;
            void setAscii(char asciiRepresentation);

            const std::string &getTexture() const;
            void setTexture(const std::string &texture);

            const std::pair<float, float> &getPos() const;
            const std::pair<float, float> &getSize() const;
            const std::vector<unsigned char> &getColor() const;
            void setPos(float x, float y);
            void setSize(float h, float w);
            void setColor(unsigned char r, unsigned char g, unsigned char b);
    };
}

#endif // !DRAWABLEINFO_HPP_