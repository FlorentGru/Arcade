/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** pacman_setter_getter.cpp
*/

#include "pacman.hpp"

Pacman::Pacman() : window(960, 540)
{
    map.push_back("XXXXXXXXXXXXXXXXXXX\n");
    map.push_back("X........X........X\n");
    map.push_back("XoXX.XXX.X.XXX.XXoX\n");
    map.push_back("X.................X\n");
    map.push_back("X.XX.X.XXXXX.X.XX.X\n");
    map.push_back("X....X...X...X....X\n");
    map.push_back("XXXX.XXX X XXX.XXXX\n");
    map.push_back("   X.X       X.X   \n");
    map.push_back("XXXX.X XX XX X.XXXX\n");
    map.push_back("    .  X F X  .    \n");
    map.push_back("XXXX.X XFFFX X.XXXX\n");
    map.push_back("   X.X XXXXX X.X   \n");
    map.push_back("   X.X       X.X   \n");
    map.push_back("XXXX.X XXXXX X.XXXX\n");
    map.push_back("X........X........X\n");
    map.push_back("X.XX.XXX.X.XXX.XX.X\n");
    map.push_back("Xo.X.....P.....X.oX\n");
    map.push_back("XX.X.X.XXXXX.X.X.XX\n");
    map.push_back("X....X...X...X....X\n");
    map.push_back("X.XXXXXX.X.XXXXXX.X\n");
    map.push_back("X.................X\n");
    map.push_back("XXXXXXXXXXXXXXXXXXX\n");
    this->isPacInv = false;
    this->isGhostRun = false;
    this->pos_pac.first = 10;
    this->pos_pac.second = 18;
    this->pos_ghost.push_back(std::make_pair(static_cast<float>(10), static_cast<float>(10)));
    this->pos_ghost.push_back(std::make_pair(static_cast<float>(9), static_cast<float>(11)));
    this->pos_ghost.push_back(std::make_pair(static_cast<float>(10), static_cast<float>(11)));
    this->pos_ghost.push_back(std::make_pair(static_cast<float>(11), static_cast<float>(11)));
    this->score = 0;
    this->move_ghost = 0;
    this->move_pac = 0;
    this->window.setWidth(PIXEL_TO_MAP(960));
    this->window.setHeight(PIXEL_TO_MAP(960));
    std::cout << map.size() << std::endl;
    for (size_t i = 0; i < this->map.size(); i++) {
        for (size_t k = 0; k < this->map[i].length(); k++) {
            if (this->map[i][k] == 'X') {
                printf("Yolo\n");
                this->allrect.emplace_back(arcDisplay::RectInfo());
                this->allrect.back().setAscii(' ');
                this->allrect.back().setPos(static_cast<float>(k * 3), static_cast<float>(i * 3));
                this->allrect.back().setSize(3, 3);
                this->allrect.back().setColor(255, 0, 0);
            }
        }
    }
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

std::vector<std::string> Pacman::get_map()
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