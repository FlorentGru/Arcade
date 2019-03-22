/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** IGameModule.hpp
*/

#ifndef IGAMEMODULE_HPP
#define IGAMEMODULE_HPP

#include "IInfoDisplay.hpp"
#include "InfoInput.hpp"
#include "InitWindow.hpp"
#include <vector>

class IGameModule {
private:

public:
    virtual const InitWindow &init() = 0;
    virtual bool playGame(const std::vector<arcDisplay::t_InfoInput > &) = 0;
    virtual const std::vector<std::reference_wrapper<const arcDisplay::IInfoDisplay>> &getInfoDisplay() const = 0;
    virtual long int getScore() const = 0;
};

#endif