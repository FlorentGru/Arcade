/*
** EPITECH PROJECT, 2018
** Test
** File description:
** snake.hpp
*/

#include <iostream>
#include <vector>
#include <unistd.h>
#include <ncurses.h>
#include <cstdlib>

#ifndef _SNAKE_H_
#define _SNAKE_H_

struct snakebody {
    int x;
    int y;
    snakebody(int col, int row);
    snakebody();
};

class snakeclass {
    public:
    snakeclass();
    ~snakeclass();
    void start(); 

    private:
    int points;
    int delay;
    int maxwidth;
    int maxheight;
    char direction;
    char snakepart;
    char head;
    char term;
    char foo;
    char wall;
    bool food;
    snakebody locFood;
    std::vector <snakebody> snake;

    void createFood();
    bool collision();
    void movesnake();
};

#endif //_SNAKE_H_