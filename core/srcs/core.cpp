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
    this->graphical = nullptr;
    this->game = nullptr;
    this->actualDisplay = 0;
    this->actualGame = 0;
}

int Core::run(const std::string &libName)
{
    Outcome outcome = UNCHANGED;

    this->setDisplayLibPath("./lib");
    this->setGameLibPath("./games");
    try {
        this->setDisplayModule(libName);
    } catch(const std::exception &e) {
        std::cerr << e.what() << '\n';
        return (84);
    }

    menu.initGames(this->gameLibPath);
    menu.initLibs(this->displayLibPath);

    while (outcome != QUIT) {
        if (outcome == GAME) {
            outcome = this->runGame();
        } else {
            outcome = this->runMenu();
        }
    }
    return (0);
}

Core::Outcome Core::runMenu()
{
    Outcome outcome = UNCHANGED;

    while (outcome == UNCHANGED) {
        outcome = menuLoop();
        switch (outcome) {
            case QUIT:
                return (QUIT);
            case LIB:
                outcome = UNCHANGED;
                break;
            case GAME:
                return (GAME);
            default:
                break;
        }
    }
    return (UNCHANGED);
}

Core::Outcome Core::runGame()
{
    Outcome outcome = UNCHANGED;

    while (outcome == UNCHANGED) {
        outcome = gameLoop();
        switch (outcome) {
            case QUIT:
                return (QUIT);
            case LIB:
                outcome = UNCHANGED;
                break;
            case MENU:
                return (MENU);
            default:
                break;
        }
    }
    return (UNCHANGED);
}

Core::Outcome Core::menuLoop()
{
    std::vector<arcDisplay::t_InfoInput &> inputs;
    Outcome outcome = UNCHANGED;

    graphical->initScreen(menu.init());
    while (outcome == UNCHANGED) {
        inputs = graphical->getInput();
        outcome = menuEvent(inputs);
        graphical->display(menu.getInfoDisplay());
    }
    graphical->close();
    return (outcome);
}

void Core::initGame()
{
    if (!graphical->initScreen(game->init())) {
//        throw ();
    }
}

Core::Outcome Core::gameLoop()
{
    std::vector<arcDisplay::t_InfoInput &> inputs;
    Outcome outcome = UNCHANGED;

    initGame();
    while (outcome == UNCHANGED) {
        inputs = graphical->getInput();
        outcome = gameEvent(inputs);
        game->playGame(inputs);
        graphical->display(game->getInfoDisplay());
    }
    graphical->close();
    return (outcome);
}

Core::Outcome Core::menuEvent(std::vector<arcDisplay::t_InfoInput &> inputs)
{
    for (auto &input : inputs) {
        switch (input.id) {
            case arcDisplay::ESCAPE:
                return (QUIT);
            case arcDisplay::UP:
                this->setNextGameLib();
                return (LIB);
            case arcDisplay::DOWN:
                this->setPreviousGameLib();
                return (LIB);
            default:
                break;
        }
    }
    return (UNCHANGED);
}

Core::Outcome Core::gameEvent(std::vector<arcDisplay::t_InfoInput &> inputs)
{
    for (auto &input : inputs) {
        switch (input.id) {
            case arcDisplay::ESCAPE:
                return (QUIT);
            case arcDisplay::M:
                return (MENU);
            case arcDisplay::UP:
                this->setNextGameLib();
                return (LIB);
            case arcDisplay::DOWN:
                this->setPreviousGameLib();
                return (LIB);
            case arcDisplay::RIGHT:
                this->setNextDisplayLib();
                return (LIB);
            case arcDisplay::LEFT:
                this->setPreviousDisplayLib();
                return (LIB);
            default:
                break;
        }
    }
    return (UNCHANGED);
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

    this->libDisplay.openLib(libName);
    this->graphical = this->libDisplay.getClass("create");

    for (auto &libname : this->gameLibPath) {
        if (libname == libName)
            this->actualGame = i;
        i++;
    }
}

void Core::setGameModule(const std::string &libName)
{
    size_t i = 0;

    this->libGame.openLib(libName);
    this->game = this->libGame.getClass("create");

    for (auto &libname : this->displayLibPath) {
        if (libname == libName)
            this->actualDisplay = i;
        i++;
    }
}