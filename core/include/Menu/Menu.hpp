/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Menu.hpp
*/

#ifndef OOP_ARCADE_2018_MENU_HPP
#define OOP_ARCADE_2018_MENU_HPP

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

    const std::string getLibName(std::string) const;
public:
    Menu();


    void initGames(const std::vector<std::string> &);
    void initLibs(const std::vector<std::string> &);

    const InitWindow init();

    const std::vector<std::reference_wrapper<const arcDisplay::IInfoDisplay>> getInfoDisplay() const;
};

#endif //OOP_ARCADE_2018_MENU_HPP
