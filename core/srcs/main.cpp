/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** main.c
*/

#include <iostream>
#include "core.hpp"

int main(int ac, char const *av[])
{
    Core core;

    if (ac < 2 || ac > 2) {
        std::cout << "c pa com sa kon utilize le jeu" << std::endl;
        return (84);
    }
    return (core.run(av[1]));                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
}