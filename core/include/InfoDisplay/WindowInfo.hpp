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
        explicit WindowInfo(bool close = false);

        enum TypeInfoDisplay getType() const override;

        bool isClosed() const;
        void setClose(bool);
    };
};

#endif