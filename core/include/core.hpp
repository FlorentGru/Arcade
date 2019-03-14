/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** Core.hpp
*/

#ifndef __CORE_HPP__
#define __CORE_HPP__

#include <string>
#include "IDisplayModule.hpp"
#include "IGameModule.hpp"
#include "dlLoader.hpp"

class Core 
{
private:
    DLLoader libLoader;
    std::vector<std::string> gameLibPath;
    int actualGame;
    std::vector<std::string> displayLibPath;
    int actualDisplay;

    IGameModule *game;
    arcDisplay::IDisplayModule *graphical;

    void setGameLibPath(const std::string &dirPath);
    void setDisplayLibPath(const std::string &dirPath);
    void setDisplayModule(const std::string &libName);
    void setGameModule(const std::string &libName);

    void setNextDisplayLib();
    void setPreviousDisplayLib();
    void setNextGameLib();
    void setPreviousGameLib();
public:
    Core();

    int run(const std::string &libName);
};

#endif