/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** SpriteInfo.hpp
*/

#ifndef SPRITEINFO_HPP
#define SPRITEINFO_HPP

#include "ADrawableInfo.hpp"

namespace arcDisplay
{
    class SpriteInfo : public ADrawableInfo
    {
    private:
        std::pair<int, int> _posRect;
        std::pair<int, int> _sizeRect;
    public:
        const TypeInfoDisplay getType() const;

        const std::pair<int, int> getPosRect() const;
        const std::pair<int, int> getSizeRect() const;

        void setPosRect(int, int);
        void setSizeRect(int, int);
    };
} // arcDisplay


#endif