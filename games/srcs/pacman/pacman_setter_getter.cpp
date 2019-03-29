/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** pacman_setter_getter.cpp
*/

#include "pacman.hpp"

Pacman::Pacman()
{
    map.pushback("XXXXXXXXXXXXXXXXXXX\n");
    map.pushback("X........X........X\n");
    map.pushback("XoXX.XXX.X.XXX.XXoX\n");
    map.pushback("X.................X\n");
    map.pushback("X.XX X.XXXXX.X.XX.X\n");
    map.pushback("X....X...X...X....X\n");
    map.pushback("XXXX.XXX X XXX.XXXX\n");
    map.pushback("   X.X       X.X   \n");
    map.pushback("XXXX.X XX XX X.XXXX\n");
    map.pushback("    .  X F X  .    \n");
    map.pushback("XXXX.X XFFFX X.XXXX\n");
    map.pushback("   X.X XXXXX X.X   \n");
    map.pushback("   X.X       X.X   \n");
    map.pushback("XXXX.X XXXXX X.XXXX\n");
    map.pushback("X........X........X\n");
    map.pushback("X.XX.XXX.X.XXX.XX.X\n");
    map.pushback("Xo.X.....P.....X.oX\n");
    map.pushback("XX.X.X.XXXXX.X X.XX\n");
    map.pushback("X....X...X...X....X\n");
    map.pushback("X.XXXXXX.X.XXXXXX.X\n");
    map.pushback("X.................X\n");
    map.pushback("XXXXXXXXXXXXXXXXXXX\n");
    this->isPacInv = false;
    this->isGhostRun = false;
    this->pos_pac.first = 10;
    this->pos_pac.second = 18;
    this->pos_ghost.push_back(10, 10);
    this->pos_ghost.push_back(9, 11);
    this->pos_ghost.push_back(10, 11);
    this->pos_ghost.push_back(11, 11);
    this->score = 0;
    this->move_ghost = 0;
    this->move_pac = 0;
}

std::pair<float, float> Pacman::get_pos_pac()
{
    return (this->pos_pac);
}

std::vector<std::pair<float, float>> Pacman::get_pos_ghost()
{
    return (this->pos_ghost);
}

bool Pacman::get_isGhostRun()
{
    return (this->isGhostRun);
}

bool Pacman::get_isPacInv()
{
    return (this->isPacInv);
}

std::string Pacman::get_map()
{
    return (this->map);
}

void Pacman::set_pos_pac(float pos1, float pos2)
{
    this->pos_pac.first = pos1;
    this->pos_pac.second = pos2;
}

void Pacman::set_move_ghost(size_t move)
{
    this->move_ghost = move;
}

void Pacman::set_move_pac(size_t move)
{
    this->move_pac = move;
}

size_t Pacman::get_move_ghost()
{
    return (this->move_ghost);
}

size_t Pacman::get_move_pac()
{
    return (this->move_pac);
}

void Pacman::set_key(arcDisplay::KeyBoard::KeyID _key)
{
    this->key = _key;
}

arcDisplay::KeyBoard::KeyID Pacman::get_key()
{
    return (this->key);
}