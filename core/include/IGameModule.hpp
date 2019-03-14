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
#include <vector>

class IGameModule {
private:

public:
    bool init(std::reference_wrapper<arcDisplay::IDisplayModule>);
    bool playGame(const std::vector<const arcDisplay::t_InfoInput &> &);
    const std::vector<std::reference_wrapper<arcDisplay::IInfoDisplay>> &getInfoDisplay() const;
    long int getScore() const;
};

#endif