/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** games.cpp
*/

#include "pacman.hpp"

const InitWindow &Pacman::initWindow()
{
    InitWindow window(PIXEL_TO_MAP(960, PIXEL_TO_MAP(540)));

    return (window);
}

bool Pacman::playGame(const std::vector<arcDisplay::t_InfoInput> &inputs)
{
     for (auto input : inputs) {
        if (input.isPressed) {
            switch (input.id) {
                case arcDisplay::KeyBoard::Z:
                    set_pos_pac(get_pos_pac().first, get_pos_pac().second - 1);
                    check_move_pack(arcDisplay::KeyBoard::Z);
                    break;
                case arcDisplay::KeyBoard::Q:
                    set_pos_pac(get_pos_pac().first - 1, get_pos_pac().second);
                    check_move_pack(arcDisplay::KeyBoard::Q);
                    break;
                case arcDisplay::KeyBoard::S:
                    set_pos_pac(get_pos_pac().first, get_pos_pac().second + 1);
                    check_move_pack(arcDisplay::KeyBoard::S);
                    break;
                case arcDisplay::KeyBoard::D:
                    set_pos_pac(get_pos_pac().first + 1, get_pos_pac().second);
                    check_move_pack(arcDisplay::KeyBoard::D);
                    break;
                default
                    break;
            }
        }
    }
    for (size_t i = 0; i < this->map.size(); i++) {
        for (size_t k = 0; k < this->map[i].length(); k++)
            if (this->map[i][k] == 'X')
                
            if (this->map[i][k] == '.')
            if (this->map[i][k] == 'o')
            if (this->map[i][k] == 'F')
            if (this->map[i][k] == 'P')
    }
}

const std::vector<std::reference_wrapper<const arcDisplay::IInfoDisplay>> &Pacman::getInfoDisplay()
{
    return (this->infos);
}

void check_move_pack(arcDisplay::KeyBoard::KeyID key)
{
    
}