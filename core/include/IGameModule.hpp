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
    const InitWindow &init();
    bool playGame(const std::vector<arcDisplay::t_InfoInput &> &);
    const std::vector<std::reference_wrapper<arcDisplay::IInfoDisplay>> &getInfoDisplay() const;
    long int getScore() const;
};

#endif