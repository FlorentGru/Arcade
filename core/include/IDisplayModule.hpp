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
#include <functional>
#include <vector>

namespace arcDisplay
{
    class IDisplayModule {
    private:

    public:
        virtual bool initScreen() = 0;
        virtual bool close() = 0;
        virtual bool display(const std::vector<std::reference_wrapper<IInfoDisplay>> &) = 0;
        virtual std::vector<std::reference_wrapper<t_InfoInput>> getInput() const = 0;
    };
} // arcDisplay

#endif