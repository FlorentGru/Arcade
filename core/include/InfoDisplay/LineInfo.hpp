/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** LineInfo.hpp
*/

#ifndef LINEINFO_HPP
#define LINEINFO_HPP

#include "ADrawableInfo.hpp"

namespace arcDisplay
{
    class LineInfo
    {
    private:
        std::pair<float, float> _position2;
    public:
        const TypeInfoDisplay getType();

        const std::pair<float, float> &getPosition2();
        void setPosition2(const float, const float);
    };
} // arcDisplay


#endif