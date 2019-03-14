/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** Core.cpp
*/

#include "core.hpp"
#include <iostream>
#include <experimental/filesystem>

Core::Core()
{
    this->graphical = NULL;
    this->game = NULL;
    this->actualDisplay = -1;
    this->actualGame = -1;
}

int Core::run(const std::string &libName)
{
    this->setDisplayLibPath("./lib");
    this->setGameLibPath("./games");
    try {
        this->setDisplayModule(libName);
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
        return (84);
    }
}

void Core::setNextDisplayLib()
{
    this->actualDisplay += 1;
    if (this->actualDisplay >= this->displayLibPath.size())
        this->actualDisplay = 0;
    this->setDisplayModule(this->displayLibPath.at(this->actualDisplay));
}

void Core::setPreviousDisplayLib()
{
    this->actualDisplay -= 1;
    if (this->actualDisplay < 0)
        this->actualDisplay = this->displayLibPath.size() - 1;
    this->setDisplayModule(this->displayLibPath.at(this->actualDisplay));
}

void Core::setNextGameLib()
{
    this->actualGame += 1;
    if (this->actualGame >= this->gameLibPath.size())
        this->actualGame = 0;
    this->setGameModule(this->gameLibPath.at(this->actualGame));
}

void Core::setPreviousGameLib()
{
    this->actualGame -= 1;
    if (this->actualGame < 0)
        this->actualGame = this->gameLibPath.size() - 1;
    this->setGameModule(this->gameLibPath.at(this->actualGame));
}

void Core::setDisplayLibPath(const std::string &dirPath)
{
    std::string filename;

    for (auto &filepath : std::experimental::filesystem::directory_iterator(dirPath)) {
        filename = filepath.path().string();
        if (std::experimental::filesystem::is_regular_file(filepath.path()) 
        && filename.rfind(".so") == filename.size() - 3) {
            this->displayLibPath.push_back(filename);
        }
    }
}

void Core::setGameLibPath(const std::string &dirPath)
{
    std::string filename;

    for (auto &filepath : std::experimental::filesystem::directory_iterator(dirPath)) {
        filename = filepath.path().string();
        if (std::experimental::filesystem::is_regular_file(filepath.path()) 
        && filename.rfind(".so") == filename.size() - 3) {
            this->gameLibPath.push_back(filename);
        }
    }
}

void Core::setDisplayModule(const std::string &libName)
{
    size_t i = 0;

    this->libLoader.openLib(libName);
    this->graphical = this->libLoader.template getClass<IDisplayModule>("DisplayModule");
    this->libLoader.closeLib();

    for (auto &libname : this->gameLibPath) {
        if (libname == libName)
            this->actualGame = i;
        i++;
    }
}

void Core::setGameModule(const std::string &libName)
{
    size_t i = 0;

    this->libLoader.openLib(libName);
    this->game = this->libLoader.template getClass<IGameModule>("GameModule");
    this->libLoader.closeLib();

    for (auto &libname : this->displayLibPath) {
        if (libname == libName)
            this->actualDisplay = i;
        i++;
    }
}