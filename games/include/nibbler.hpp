/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** games.hpp
*/

#ifndef __NIBBLER_HPP__
#define __NIBBLER_HPP__

#include "IGameModule.hpp"
#include "WindowInfo.hpp"
#include "SoundInfo.hpp"
#include "TextInfo.hpp"
#include "SpriteInfo.hpp"
#include "CircleInfo.hpp"
#include "RectInfo.hpp"
#include "LineInfo.hpp"
#include "snake.hpp"
#include "food.hpp"
#include <vector>
#include <functional>
#include <unistd.h>

class Nibbler : public IGameModule
{
    private:
        int score;
        int width;
        int height;
        bool die;

        int delay;
        int x;
        int y;

        arcDisplay::KeyBoard::KeyID key;
        std::vector<arcDisplay::RectInfo> edges;
        InitWindow window;
        arcDisplay::WindowInfo closeWindow;
        Snake snake;
        Food fruits;

        std::vector<std::reference_wrapper<const arcDisplay::IInfoDisplay>> infos;
    public:
        Nibbler();

        const InitWindow &initWindow();
        bool playGame(const std::vector<arcDisplay::t_InfoInput> &);
        const std::vector<std::reference_wrapper<const arcDisplay::IInfoDisplay>> &getInfoDisplay();
        long int getScore() const;
    
        void moveNibbler(const std::vector<arcDisplay::t_InfoInput> &);
};

#endif //_NIBBLER_HPP_