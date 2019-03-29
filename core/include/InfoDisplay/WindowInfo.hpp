/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** WindowInfo.hpp
*/

#ifndef WINDOWINFO_HPP_
#define WINDOWINFO_HPP_

#include "IInfoDisplay.hpp"

namespace arcDisplay
{
    class WindowInfo : public IInfoDisplay
    {
        private:
            bool _close;

        public:
            explicit WindowInfo(bool toClose = false);

            bool isClosed() const;
            void setClose(bool);

            enum TypeInfoDisplay getType() const override;
    };
}

#endif // !WINDOWINFO_HPP_