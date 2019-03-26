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
    this->game.release();
    this->graphical.release();
    this->libDisplay.closeLib();
    this->libGame.closeLib();
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
    Outcome outcome = UNCHANGED;

    graphical->initScreen(menu.init());
    while (outcome == UNCHANGED) {
        auto inputs = graphical->getInput();
        outcome = menuEvent(inputs);
        if (outcome != UNCHANGED) {
            return (outcome);
        }
        if (!graphical->display(menu.getInfoDisplay()))
            outcome = QUIT;
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
    Outcome outcome = UNCHANGED;

    initGame();
    while (outcome == UNCHANGED) {
        auto inputs = graphical->getInput();
        outcome = gameEvent(inputs);
        if (outcome != UNCHANGED)
            break;
        game->playGame(inputs);
        if (!graphical->display(game->getInfoDisplay()))
            outcome = QUIT;
    }
    graphical->close();
    return (outcome);
}

Core::Outcome Core::menuEvent(const std::vector<arcDisplay::t_InfoInput> &inputs)
{
    for (auto input : inputs) {
        if (input.isPressed) {
            switch (input.id) {
                case arcDisplay::KeyBoard::ESCAPE:
                    return (QUIT);
                case arcDisplay::KeyBoard::UP:
                    this->setNextGameLib();
                    return (LIB);
                case arcDisplay::KeyBoard::DOWN:
                    this->setPreviousGameLib();
                    return (LIB);
                case arcDisplay::KeyBoard::LEFT:
                    std::cout << "Left arrow pressed" << std::endl;
                    this->setPreviousDisplayLib();
                    return (LIB);
                case arcDisplay::KeyBoard::RIGHT:
                    std::cout << "Right arrow pressed" << std::endl;
                    this->setNextDisplayLib();
                    return (LIB);
                default:
                    break;
            }
        }
    }
    return (UNCHANGED);
}

Core::Outcome Core::gameEvent(const std::vector<arcDisplay::t_InfoInput> &inputs)
{
    for (auto input : inputs) {
        switch (input.id) {
            case arcDisplay::KeyBoard::ESCAPE:
                return (QUIT);
            case arcDisplay::KeyBoard::M:
                return (MENU);
            case arcDisplay::KeyBoard::UP:
                this->setNextGameLib();
                return (LIB);
            case arcDisplay::KeyBoard::DOWN:
                this->setPreviousGameLib();
                return (LIB);
            case arcDisplay::KeyBoard::RIGHT:
                this->setNextDisplayLib();
                return (LIB);
            case arcDisplay::KeyBoard::LEFT:
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
    this->graphical->close();
    this->actualDisplay += 1;
    if (this->actualDisplay >= this->displayLibPath.size())
        this->actualDisplay = 0;
    std::cout << "SWITCHING TO: " << this->displayLibPath.at(this->actualDisplay) << std::endl;
    this->setDisplayModule(this->displayLibPath.at(this->actualDisplay));
}

void Core::setPreviousDisplayLib()
{
    this->graphical->close();
    if (this->actualDisplay == 0)
        this->actualDisplay = this->displayLibPath.size() - 1;
    else
        this->actualDisplay -= 1;
    std::cout << "SWITCHING TO: " << this->displayLibPath.at(this->actualDisplay) << std::endl;
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
    if (this->actualGame == 0)
        this->actualGame = this->gameLibPath.size() - 1;
    else
        this->actualGame -= 1;
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
            std::cout << filename << std::endl;
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
            std::cout << filename << std::endl;
        }
    }
    std::cout << "\nEND OF LOAD\n";
}

void Core::setDisplayModule(const std::string &libName)
{
    size_t i = 0;
    arcDisplay::IDisplayModule *graph;

    this->graphical.reset();
    std::cout << "Opening Lib" << std::endl;
    this->libDisplay.openLib(libName);
    graph = this->libDisplay.getClass("create");
    std::cout << "Got the instance" << std::endl;
    this->graphical.reset(graph);
    std::cout << "LIB reseted" << std::endl;

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
    this->game.reset(this->libGame.getClass("create"));

    for (auto &libname : this->displayLibPath) {
        if (libname == libName)
            this->actualDisplay = i;
        i++;
    }
}