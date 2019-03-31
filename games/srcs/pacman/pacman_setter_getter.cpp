/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** pacman_setter_getter.cpp
*/

#include "../../games/include/pacman.hpp"

Pacman::Pacman() : window(960, 540), close(true)
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
    this->pos_ghost.push_back(std::make_pair(static_cast<float>(10), static_cast<float>(10)));
    this->pos_ghost.push_back(std::make_pair(static_cast<float>(9), static_cast<float>(11)));
    this->pos_ghost.push_back(std::make_pair(static_cast<float>(10), static_cast<float>(11)));
    this->pos_ghost.push_back(std::make_pair(static_cast<float>(11), static_cast<float>(11)));
    this->nb_bubble = 0;
    this->move_ghost = 0;
    this->window.setWidth(PIXEL_TO_MAP(960));
    this->window.setHeight(PIXEL_TO_MAP(960));
    this->window.setFrame(60);
    for (size_t i = 0; i < this->map.size(); i++) {
        for (size_t k = 0; k < this->map[i].length(); k++) {
            if (this->map[i][k] == 'X') {
                this->allrect.emplace_back(arcDisplay::RectInfo());
                this->allrect.back().setAscii(' ');
                this->allrect.back().setPos(static_cast<float>(k + 20), static_cast<float>(i + 20));
                this->allrect.back().setSize(1, 1);
                this->allrect.back().setColor(0, 0, 255);
            }
            else if (this->map[i][k] == 'P') {
                this->pac.emplace_back(arcDisplay::CircleInfo());
                this->pac.back().setAscii(' ');
                this->pac.back().setPos(static_cast<float>(k + 20), static_cast<float>(i + 20));
                this->pos_pac = std::make_pair(k + 20, i + 20);
                this->pac.back().setSize(1, 1);
                this->pac.back().setColor(255, 255, 50);
            } else if (this->map[i][k] == 'F') {
                this->ghosts.emplace_back(Ghost(static_cast<float>(k + 20), static_cast<float>(i + 20)));
            }
            if (this->map[i][k] == '.')
                this->nb_bubble++;
        }
    }
    this->counter = 0;

    this->life = 3;
    this->lifeDisplay.setSize(30);
    this->lifeDisplay.setFont("./rsc/font/WC_RoughTrad.ttf");
    this->lifeDisplay.setText("Life: " + std::to_string(this->life));
    this->lifeDisplay.setPos(this->window.getWidth() / 3 - 5, this->window.getHeight() - 20);

    this->score = 0;
    this->scoreDisplay.setSize(30);
    this->scoreDisplay.setFont("./rsc/font/WC_RoughTrad.ttf");
    this->scoreDisplay.setText("Score: " + std::to_string(this->score));
    this->scoreDisplay.setPos(this->window.getWidth() * (2.0 / 3.0) - 5, this->window.getHeight() - 20);
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

size_t Pacman::get_move_ghost()
{
    return (this->move_ghost);
}