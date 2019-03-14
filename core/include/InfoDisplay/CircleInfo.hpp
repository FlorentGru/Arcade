/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** CircleInfo.hpp
*/

#ifndef CIRCLEINFO_HPP
#define CIRCLEINFO_HPP

#include "ADrawableInfo.hpp"

namespace arcDisplay
{
    class CircleInfo : public ADrawableInfo
    {
    private:

    public:
        CircleInfo() {};
        ~CircleInfo() {};
        const TypeInfoDisplay getType() const;
    };
}; // arcDisplay

#endif