/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Menu.cpp
*/

#include "Menu.hpp"
#include <functional>
#include <iostream>

Menu::Menu() : font("./rsc/font/WC_RoughTrad.ttf")
{
    float size;
    this->width = 64;
    this->height = 36;
    this->selected = 0;

    this->usage.setText("Use Z, Q, S, D to choose and Use Enter to select");
    this->usage.setSize(30);
    size = usage.getText().size();
    this->usage.setPos(width / 2 - size / 2, height - 3);
    this->usage.setFont(this->font);
}

void Menu::initGames(const std::vector<std::string> &_games)
{
    float _width = this->width;
    float _height = this->height;
    float x = 0;
    float y = 0;
    float length = 0;

    _height = _height / 2;
    _height -= 3;

    for (const auto &game : _games) {
        this->games.emplace_back(Rect(game));
    }

    if (!this->games.empty())
        _width /= this->games.size();
    for (auto &game : this->games) {
        length = game.getText().getText().size();
        game.setFont(this->font);
        game.setSize(_width, _height, 30);
        game.setPos(x, y, _width / 2 - (length / 2), _height / 2 - 1);
        game.setAscii(' ');
        x += _width;
    }
}

void Menu::initLibs(const std::vector<std::string> &_libs)
{
    float _width = this->width;
    float _height = this->height;
    float x = 0;
    float y;
    float length = 0;

    _height /= 2;
    y = _height;
    _height -= 3;

    for (const auto &lib : _libs) {
        this->libs.emplace_back(Rect(getLibName(lib)));
    }

    if (!this->libs.empty())
        _width /= this->libs.size();
    for (auto &lib : this->libs) {
        length = lib.getText().getText().size();
        lib.setFont(this->font);
        lib.setSize(_width, _height, 30);
        lib.setPos(x, y, _width / 2 - (length / 2), _height / 2 - 1);
        lib.setAscii(' ');
        x += _width ;
    }
    this->libNames = _libs;
}

const std::string Menu::getLibName(std::string lib) const
{
    lib.erase(lib.rfind(".so"));
    lib.erase(0, lib.rfind("lib_arcade_") + std::string("lib_arcade_").size());
    return (lib);
}

const InitWindow Menu::initWindow()
{
    InitWindow window(this->width, this->height);
    std::vector<std::string> fonts;

    window.setFrame(10);
    window.setName("Menu");

    return (window);
}

const std::string Menu::switchTo(const std::vector<arcDisplay::t_InfoInput> &inputs)
{
    for (auto &input : inputs) {
        if (input.isPressed) {
            switch (input.id) {
                case arcDisplay::KeyBoard::Z:
                    up();
                    break;
                case arcDisplay::KeyBoard::Q:
                    left();
                    break;
                case arcDisplay::KeyBoard::S:
                    down();
                    break;
                case arcDisplay::KeyBoard::D:
                    right();
                    break;
                case arcDisplay::KeyBoard::ENTER:
                    return (select());
                default:
                    break;
            }
        }
    }
    setSelected();
    return ("");
}

const std::string Menu::select()
{
    size_t i = 0;

    if (selected < gamesNames.size()) {
        for (auto &game : gamesNames) {
            if (i == selected)
                return game;
            i++;
        }
    } else {
        for (auto &lib : libNames) {
            if (gamesNames.size() + i == selected)
                return lib;
            i++;
        }
    }
    return ("");
}

void Menu::setSelected()
{
    size_t i = 0;

    if (selected < games.size()) {
        for (auto &game : games) {
            if (i == selected)
                game.setColor(10, 255, 100);
            else
                game.setColor(10, 100, 255);
            i++;
        }
    } else {
        for (auto &lib : libs) {
            if (games.size() + i == selected)
                lib.setColor(10, 255, 100);
            else
                lib.setColor(10, 100, 255);
            i++;
        }
    }
}

void Menu::right()
{
    if (selected < gamesNames.size()) {
        selected++;
        if (selected == gamesNames.size())
            selected = 0;
    } else {
        selected++;
        if (selected - gamesNames.size() == libNames.size()) {
            selected = 0;
        }
    }
}

void Menu::left()
{
    if (selected < gamesNames.size()) {
        if (selected == 0)
            selected = libNames.size() - 1;
        else
            selected--;
    } else {
        if (selected <= gamesNames.size()) {
            selected = libNames.size() - 1;
        } else {
            selected--;
        }
    }
}

void Menu::up()
{
    if (selected >= gamesNames.size() && !gamesNames.empty()) {
        if (selected - gamesNames.size() >= gamesNames.size()) {
            selected = gamesNames.size() - 1;
        } else {
            selected -= gamesNames.size();
        }
    }
}

void Menu::down()
{
    if (selected < gamesNames.size() && !libNames.empty()) {
        if (selected >= libNames.size()) {
            selected = libNames.size() - 1;
        } else {
            selected += gamesNames.size();
        }
    }
}

const std::vector<std::reference_wrapper<const arcDisplay::IInfoDisplay>> &Menu::getInfoDisplay()
{

    this->infos.clear();
    for (auto &game : this->games) {
        infos.emplace_back(std::ref(game.getRect()));
        infos.emplace_back(std::ref(game.getText()));
    }
    for (auto &lib : this->libs) {
        infos.emplace_back(std::ref(lib.getRect()));
        infos.emplace_back(std::ref(lib.getText()));
    }
    infos.emplace_back(std::ref(this->usage));
    return (infos);
}