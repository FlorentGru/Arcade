/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** IDisplayModule.hpp
*/

#ifndef IDISPLAYMODULE_HPP
#define IDISPLAYMODULE_HPP

#include "IInfoDisplay.hpp"
#include "InfoInput.hpp"
#include "InitWindow.hpp"
#include <functional>
#include <vector>

namespace arcDisplay
{
    class IDisplayModule {
    private:

    public:
        virtual bool initScreen(const InitWindow &) = 0;
        virtual bool close() = 0;
        virtual bool display(const std::vector<std::reference_wrapper<const IInfoDisplay>> &) = 0;
        virtual const std::vector<t_InfoInput> &getInput() = 0;
    };
} // arcDisplay

#endif