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

    if (ac != 2) {
        std::cout << "USAGE" << std::endl;
        std::cout << "\t./arcade <path_to_graphical_lib>" << std::endl;
        return (84);
    }
    return (core.run(av[1]));                                                                                                                                                                                                                                                                                                                                                                                                                                                                            
}