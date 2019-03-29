/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** games.cpp
*/

#include "pacman.hpp"

Pacman::Pacman()
{
    map = "XXXXXXXXXXXXXXXXXXX\n
            X........X........X\n\\
            XoXX.XXX.X.XXX.XXoX\n\\
            X.................X\n\\
            X.XX X.XXXXX.X.XX.X\n\\
            X....X...X...X....X\n\\
            XXXX.XXX X XXX.XXXX\n\\
               X.X       X.X   \n\\
            XXXX.X XX XX X.XXXX\n\\
                .  X F X  .    \n\\
            XXXX.X XFFFX X.XXXX\n\\
               X.X XXXXX X.X   \n\\
               X.X       X.X   \n\\
            XXXX.X XXXXX X.XXXX\n\\
            X........X........X\n\\
            X.XX.XXX.X.XXX.XX.X\n\\
            Xo.X.....P.....X.oX\n\\
            XX.X.X.XXXXX.X X.XX\n\\
            X....X...X...X....X\n\\
            X.XXXXXX.X.XXXXXX.X\n\\
            X.................X\n\\
            XXXXXXXXXXXXXXXXXXX\n\\";
    this->isPacInv = false;
    this->isGhostRun = false;
    this->pos_pac.first = ;
    this->pos_pac.second = ;

}