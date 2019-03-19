/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** ADrawableInfo.hpp
*/

#ifndef ADRAWABLEINFO_HPP
#define ADRAWABLEINFO_HPP

#include "IInfoDisplay.hpp"
#include <vector>
#include <string>
#include <utility>

namespace arcDisplay
{
    class ADrawableInfo : public IInfoDisplay
    {
    private:
        std::pair<float, float> _pos;
        std::pair<float, float> _size;
        std::vector<unsigned char> _color;
        char _ascii;
        std::string _texture;
    public:
        ADrawableInfo();

        virtual TypeInfoDisplay getType() const = 0;

        const std::pair<float, float> &getPos() const;
        const std::pair<float, float> &getSize() const;
        const std::vector<unsigned char> &getColor() const;
        char getAscii() const;
        const std::string &getTexture() const;

        void setPos(float, float);
        void setSize(float, float);
        void setColor(unsigned char, unsigned char, unsigned char);
        void setAscii(char);
        void setTexture(const std::string &);
    };
} // arcDisplay


#endif