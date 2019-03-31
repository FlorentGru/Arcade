/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** pacman.hpp
*/

#ifndef __PACMAN_HPP__
#define __PACMAN_HPP__

#include "IGameModule.hpp"
#include "WindowInfo.hpp"
#include "SoundInfo.hpp"
#include "TextInfo.hpp"
#include "SpriteInfo.hpp"
#include "CircleInfo.hpp"
#include "RectInfo.hpp"
#include "LineInfo.hpp"
#include "Ghost.hpp"
#include <functional>
#include <iostream>
#include <fstream>

class Pacman : public IGameModule
{
    private:
        std::vector<std::string> map;
        std::pair<int, int> pos_pac;
        std::vector<std::pair<float, float>> pos_ghost;
        bool isGhostRun;
        bool isPacInv;
        bool loose;
        size_t nb_bubble;
        size_t move_ghost;
        arcDisplay::KeyBoard::KeyID next_key;
        arcDisplay::KeyBoard::KeyID actual_key;
        std::vector<std::reference_wrapper<const arcDisplay::IInfoDisplay>> infos;
        std::vector<arcDisplay::RectInfo> allrect;
        std::vector<arcDisplay::CircleInfo> allbubble;
        std::vector<arcDisplay::CircleInfo> pac;
        std::vector<arcDisplay::RectInfo> inv_wall;

        int counter;
        std::vector<Ghost> ghosts;

        InitWindow window;
        arcDisplay::WindowInfo close;

        long int score;
        arcDisplay::TextInfo scoreDisplay;
        int life;
        arcDisplay::TextInfo lifeDisplay;
public:
        Pacman();

        const InitWindow &initWindow();
        bool playGame(const std::vector<arcDisplay::t_InfoInput> &);
        const std::vector<std::reference_wrapper<const arcDisplay::IInfoDisplay>> &getInfoDisplay();
        long int getScore() const;

        std::pair<float, float> get_pos_pac();
        std::vector<std::pair<float, float>> get_pos_ghost();
        bool get_isGhostRun();
        bool get_isPacInv();
        std::vector<std::string> get_map();
        size_t get_move_ghost();

        void set_pos_pac(float, float);
        void set_move_ghost(size_t);

        void show_case();
        void check_move_pac();
        void move_pac(int, int, int *);
};

#endif