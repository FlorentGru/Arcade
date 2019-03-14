/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** IGameModule.hpp
*/

#ifndef IGAMEMODULE_HPP
#define IGAMEMODULE_HPP

#include <vector>

class IGameModule {
private:

public:
    void init(std::reference_wrapper<IDisplayModule>);
    void setInput(std::vector<std::reference_wrapper<InfoInput>>);
    std::vector<std::reference_wrapper<Entity>> getEntity() const;
};

#endif