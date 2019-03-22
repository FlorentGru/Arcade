/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** ncursesDiplayModule.cpp
*/

#include "ncursesDisplayModule.hpp"

bool arcDisplay::ncursesDisplayModule::display(const std::vector<std::reference_wrapper<IInfoDisplay>> &info)
{
    getmaxyx(stdscr, maxheight, maxwidth);
    for(int i = 0; i < maxwidth - 1; i++)
    {
        move(0,i);
        addch(term);
    }
    for(int i = 0; i < maxheight - 1 ;i++)
    {
        move(i,0);
        addch(term);
    }
    for(int i = 0; i < maxwidth - 1 ;i++)
    {
        move(maxheight-2,i);
        addch(term);
    }
    for(int i = 0; i < maxheight - 1 ;i++)
    {
        move(i,maxwidth - 2);
        addch(term);
    }
    refresh();
    return (true);
}

bool ncrusesDisplayModule::initScreen()
{
    initscr();
    curs_set(0);
    return (true);
}

bool ncursesDisplayModule::close()
{
    nodelay(stdscr, false);
    getch();
    endwin();
    return (true);
}

ncursesDisplayModule::~ncursesDisplayModule()
{

}

void ncursesDisplayModule::draw(const WindowInfo &info)
{

}

void ncursesDisplayModule::draw(const SoundInfo &info)
{
    return (0);
}

void ncursesDisplayModule::draw(const TextInfo &info)
{

}

void ncursesDisplayModule::draw(const SpriteInfo &info)
{
    return (0);
}

void ncursesDisplayModule::draw(const CircleInfo &info)
{

}

void ncursesDisplayModule::draw(const RectInfo &info)
{

}

void ncursesDisplayModule::draw(const LineInfo &info)
{

}