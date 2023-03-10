/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** IInfoDisplay.hpp
*/

#ifndef IINFODISPLAY_HPP_
#define IINFODISPLAY_HPP_

namespace arcDisplay
{
    enum TypeInfoDisplay
    {
        TEXT,
        SPRITE,
        RECT,
        CIRCLE,
        LINE,
        SOUND,
        WINDOW
    };

    class IInfoDisplay
    {
        public:
            virtual ~IInfoDisplay() = default;

            virtual enum TypeInfoDisplay getType() const = 0;
    };
}

#endif // !IINFODISPLAY_HPP_