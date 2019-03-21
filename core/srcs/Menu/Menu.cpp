/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Menu.cpp
*/

#include "Menu.hpp"

Menu::Menu() : font("./rsc/font/WC_RoughTrad.ttf")
{
    this->width = 960;
    this->height = 540;
}

void Menu::initGames(const std::vector<std::string> &games)
{
    float width = this->width - 15;
    float height = this->height;
    float x = 10;
    float y = 5;

    height = height / 2 - 15;
    for (const auto &game : games) {
        this->games.emplace_back(Rect(game));
    }
    width /= this->games.size() - 5;
    for (auto &game : this->games) {
        game.setFont(this->font);
        game.setSize(width, height, 30);
        game.setPos(x, y, width / 2 + 30, height / 2 + 30);
        game.setAscii('#');
        x += width + 5;
    }
}

void Menu::initLibs(const std::vector<std::string> &libs)
{
    float width = this->width - 15;
    float height = this->height;
    float x = 10;
    float y;

    height = height / 2 - 15;
    y = height + 10;
    for (const auto &lib : libs) {
        this->libs.emplace_back(Rect(lib));
    }
    width /= this->games.size() - 5;
    for (auto &lib : this->libs) {
        lib.setFont(this->font);
        lib.setSize(width, height, 30);
        lib.setPos(x, y, width / 2 + 30, height / 2 + 30);
        lib.setAscii('X');
        x += width + 5;
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

const std::vector<std::reference_wrapper<arcDisplay::IInfoDisplay>> Menu::getInfoDisplay() const
{
    std::vector<std::reference_wrapper<arcDisplay::IInfoDisplay>> infos;

    for (auto &game : this->games) {
        infos.emplace_back(game.getRect());
        infos.emplace_back(game.getText());
    }
    for (auto &lib : this->libs) {
        infos.emplace_back(lib.getRect());
        infos.emplace_back(lib.getText());
    }
    return (infos);
}