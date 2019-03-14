/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** WindowInfo.hpp
*/

#ifndef WINDOWINFO_HPP
#define WINDOWINFO_HPP

#include "IInfoDisplay.hpp"

namespace arcDisplay
{
    class WindowInfo : public IInfoDisplay
    {
    private:
        bool _close;
    public:
        WindowInfo();

        const TypeInfoDisplay getType() const;

        bool isClosed() const;
        void setClose(bool);
    };
};

#endif