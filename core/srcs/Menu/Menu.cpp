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
    this->width = 960;
    this->height = 540;
}

void Menu::initGames(const std::vector<std::string> &_games)
{
    float _width = this->width - 15;
    float _height = this->height;
    float x = 10;
    float y = 5;

    _height = height / 2 - 15;
    for (const auto &game : _games) {
        this->games.emplace_back(Rect(game));
    }
    _width /= this->games.size() - 5;
    for (auto &game : this->games) {
        game.setFont(this->font);
        game.setSize(_width, _height, 30);
        game.setPos(x, y, _width / 2 + 30, _height / 2 + 30);
        game.setAscii('#');
        x += _width + 5;
    }
}

void Menu::initLibs(const std::vector<std::string> &_libs)
{
    float _width = this->width - 15;
    float _height = this->height;
    float x = 10;
    float y;

    _height = _height / 2 - 15;
    y = _height + 10;
    for (const auto &lib : _libs) {
        this->libs.emplace_back(Rect(lib));
    }
    if (!this->games.empty())
        _width = _width / this->games.size() - 5;
    for (auto &lib : this->libs) {
        lib.setFont(this->font);
        lib.setSize(_width, _height, 30);
        lib.setPos(x, y, _width / 2 + 30, _height / 2 + 30);
        lib.setAscii('X');
        x += _width + 5;
    }
}

const InitWindow Menu::init()
{
    InitWindow window(this->width, this->height);
    std::vector<std::string> fonts;

    window.setFrame(10);
    window.setName("Menu");

    fonts.emplace_back(this->font);
    window.setFonts(fonts);
    return (window);
}

const std::vector<std::reference_wrapper<const arcDisplay::IInfoDisplay>> Menu::getInfoDisplay() const
{
    std::vector<std::reference_wrapper<const arcDisplay::IInfoDisplay>> infos;

    for (auto &game : this->games) {
        infos.emplace_back(std::ref(game.getRect()));
        infos.emplace_back(std::ref(game.getText()));
    }
    for (auto &lib : this->libs) {
        infos.emplace_back(std::ref(lib.getRect()));
        infos.emplace_back(std::ref(lib.getText()));
    }
    return (infos);
}