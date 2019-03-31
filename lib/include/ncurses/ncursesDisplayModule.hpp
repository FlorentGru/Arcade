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
#include <unistd.h>
#include <map>

namespace arcDisplay
{
    class ncursesDisplayModule : public IDisplayModule
    {
        private:
        int maxheight;
        int maxwidth;
        int height;
        int width;
        short iterator;
        size_t frame;

        std::vector<arcDisplay::t_InfoInput> inputs;

        bool drawType(TypeInfoDisplay, std::reference_wrapper<const IInfoDisplay>);
        bool draw(const WindowInfo &);
        void draw(const SoundInfo &);
        void draw(const TextInfo &);
        void draw(const SpriteInfo &);
        void draw(const CircleInfo &);
        void draw(const RectInfo &);
        void draw(const LineInfo &);
            
        public:
            ncursesDisplayModule() {};

            bool initScreen(const InitWindow &info) override;
            bool close();
            bool display(const std::vector<std::reference_wrapper<const IInfoDisplay>> &) override;
            const std::vector<t_InfoInput> &getInput() override;
    };
}

#endif