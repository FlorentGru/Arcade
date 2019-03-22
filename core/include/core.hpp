/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** Core.hpp
*/

#ifndef __CORE_HPP__
#define __CORE_HPP__

#include "IDisplayModule.hpp"
#include "IGameModule.hpp"
#include "dlLoader.hpp"
#include "Menu.hpp"
#include <string>
#include <memory>

class Core 
{
private:
    enum Outcome {
        QUIT,
        MENU,
        UNCHANGED,
        LIB,
        GAME
    };

    DLLoader<IGameModule> libGame;
    DLLoader<arcDisplay::IDisplayModule> libDisplay;

    std::vector<std::string> gameLibPath;
    size_t actualGame;
    std::vector<std::string> displayLibPath;
    size_t actualDisplay;

    Menu menu;
    std::unique_ptr<IGameModule> game;
    std::unique_ptr<arcDisplay::IDisplayModule> graphical;

    void setGameLibPath(const std::string &dirPath);
    void setDisplayLibPath(const std::string &dirPath);
    void setDisplayModule(const std::string &libName);
    void setGameModule(const std::string &libName);

    void setNextDisplayLib();
    void setPreviousDisplayLib();
    void setNextGameLib();
    void setPreviousGameLib();

    Outcome runMenu();
    Outcome menuLoop();
    Outcome menuEvent(const std::vector<arcDisplay::t_InfoInput> &);

    Outcome runGame();
    void initGame();
    Outcome gameLoop();
    Outcome gameEvent(const std::vector<arcDisplay::t_InfoInput> &);

public:
    Core();

    int run(const std::string &libName);
};

#endif