/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** IDisplayModule.hpp
*/

#ifndef IDISPLAYMODULE_HPP
#define IDISPLAYMODULE_HPP

#include <vector>

class IDisplayModule {
private:

public:
    bool initScreen();
    bool close();
    bool display(std::vector<std::reference_wrapper<Entity>>);
    std::vector<std::reference_wrapper<InfoInput>> getInput() const;
};

#endif