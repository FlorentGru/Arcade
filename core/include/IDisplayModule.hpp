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
#include <vector>

namespace arcDisplay
{
    class IDisplayModule {
    private:

    public:
        bool initScreen();
        bool close();
        bool display(const std::vector<std::reference_wrapper<IInfoDisplay>> &);
        std::vector<std::reference_wrapper<t_InfoInput>> getInput() const;
    };
} // arcDisplay

#endif