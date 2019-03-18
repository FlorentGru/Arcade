/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** ncursesDisplayModule.hpp
*/

#ifndef NCURSESDISPLAYMODULE_HPP
#define NCURSESDISPLAYMODULE_HPP

#include "IDisplayModule.hpp"
#include "WindowInfo.hpp"
#include "SoundInfo.hpp"
#include "TextInfo.hpp"
#include "SpriteInfo.hpp"
#include "CircleInfo.hpp"
#include "RectInfo.hpp"
#include "LineInfo.hpp"
#include <ncurses.h>
#include <map>

namespace arcDisplay
{
    class ncursesDisplayModule : public IDisplayModule
    {
        private:
            
        public:
            ncursesDisplayModule();
            ~ncursesDisplayModule();

            bool initScreen();
            bool close();
            bool display(const std::vector<std::reference_wrapper<IInfoDisplay>> &);
            std::vector<std::reference_wrapper<t_InfoInput>> getInput() const;
    };
}

#endif