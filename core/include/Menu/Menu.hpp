/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Menu.hpp
*/

#ifndef OOP_ARCADE_2018_MENU_HPP
#define OOP_ARCADE_2018_MENU_HPP

#include "IDisplayModule.hpp"
#include "InitWindow.hpp"
#include "Rect.hpp"
#include <vector>
#include <string>

class Menu
{
private:
    std::vector<Rect> games;
    std::vector<Rect> libs;

    std::string font;
    unsigned int width;
    unsigned int height;

    std::vector<std::reference_wrapper<const arcDisplay::IInfoDisplay>> infos;

    size_t selected;
    std::vector<std::string> gamesNames;
    std::vector<std::string> libNames;

    const std::string select();
    void right();
    void left();
    void up();
    void down();
    void setSelected();

    const std::string getLibName(std::string) const;
public:
    Menu();

    void initGames(const std::vector<std::string> &);
    void initLibs(const std::vector<std::string> &);

    const InitWindow initWindow();
    const std::string switchTo(const std::vector<arcDisplay::t_InfoInput> &inputs);
    const std::vector<std::reference_wrapper<const arcDisplay::IInfoDisplay>> &getInfoDisplay();
};

#endif //OOP_ARCADE_2018_MENU_HPP
