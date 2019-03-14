/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** RectInfo.hpp
*/

#ifndef RECTINFO_HPP
#define RECTINFO_HPP

#include "ADrawableInfo.hpp"

namespace arcDisplay
{
    class RectInfo : public ADrawableInfo
    {
    private:

    public:
        const TypeInfoDisplay getType() const;
    };
} // arcDisplay

#endif