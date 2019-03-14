/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** IInfoDisplay.hpp
*/

#ifndef IINFODISPLAY_HPP
#define IINFODISPLAY_HPP

namespace arcDisplay
{
    enum TypeInfoDisplay
    {
        TEXT,
        SPRITE,
        RECT,
        CIRCLE,
        LINE,
        SOUND
    };

    class IInfoDisplay
    {
    private:

    public:
        virtual const TypeInfoDisplay getType() const = 0;
    };
}


#endif