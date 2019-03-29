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
        long int score;
        size_t move_pac;
        size_t move_ghost;
        arcDisplay::KeyBoard::KeyID key;
    public:
        Pacman();

        const InitWindow &initWindow();
        bool playGame(const std::vector<arcDisplay::t_InfoInput> &);
        const std::vector<std::reference_wrapper<const arcDisplay::IInfoDisplay>> &getInfoDisplay();
        long int getScore();

        std::pair<float, float> get_pos_pac();
        std::vector<std::pair<float, float>> get_pos_ghost();
        bool get_isGhostRun();
        bool get_isPacInv();
        std::string get_map();
        size_t get_move_ghost();
        size_t get_move_pac();

        void set_pos_pac(float, float);
        void set_move_ghost(size_t);
        void set_move_pac(size_t);
};

#endif