/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** pacman.hpp
*/

#ifndef __PACMAN_HPP__
#define __PACMAN_HPP__

#include "GameModule.hpp"

class Pacman : public IGameModule
{
    private:
        std::string map;
        std::pair<float, float> pos_pac;
        std::vector<std::pair<float, float>> pos_ghost;
        bool isGhostRun;
        bool isPacInv;
    public:
        Pacman();

        const InitWindow &initWindow();
        bool playGame(const std::vector<arcDisplay::t_InfoInput> &);
        const std::vector<std::reference_wrapper<const arcDisplay::IInfoDisplay>> &getInfoDisplay();
        long int getScore();
};

#endif