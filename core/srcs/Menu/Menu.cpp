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
    this->width = 64;
    this->height = 36;
}

void Menu::initGames(const std::vector<std::string> &_games)
{
    float _width = this->width;
    float _height = this->height;
    float x = 0;
    float y = 0;
    size_t length = 0;

    _height = _height / 2;
    for (const auto &game : _games) {
        this->games.emplace_back(Rect(game));
    }
    _width /= this->games.size();
    for (auto &game : this->games) {
        length = game.getText().getText().size();
        game.setFont(this->font);
        game.setSize(_width, _height, 30);
        game.setPos(x, y, _width / 2 - (length / 2), _height / 2 - 1);
        game.setAscii('#');
        x += _width;
    }
}

void Menu::initLibs(const std::vector<std::string> &_libs)
{
    int _width = this->width;
    int _height = this->height;
    int x = 0;
    int y;
    size_t length = 0;

    _height /= 2;
    y = _height;
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
        lib.setAscii('X');
        x += _width ;
    }
}

const std::string Menu::getLibName(std::string lib) const
{
    lib.erase(lib.rfind(".so"));
    lib.erase(0, lib.rfind("lib") + 4);
    return (lib);
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