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

#define MAP_TO_PIXEL(value) (value * 15)
#define PIXEL_TO_MAP(value) (value / 15)

class IGameModule {
private:

public:
    virtual ~IGameModule() = default;

    virtual const InitWindow &initWindow() = 0;
    virtual bool playGame(const std::vector<arcDisplay::t_InfoInput> &) = 0;
    virtual const std::vector<std::reference_wrapper<const arcDisplay::IInfoDisplay>> &getInfoDisplay() = 0;
    virtual long int getScore() const = 0;
};

#endif