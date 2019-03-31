/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** games.cpp
*/

#include "pacman.hpp"

extern "C" {
    Pacman *gameInstance()
    {
        return (new Pacman());
    }
}

const InitWindow &Pacman::initWindow()
{
     return (window);
}

bool Pacman::playGame(const std::vector<arcDisplay::t_InfoInput> &inputs)
{
    for (auto &input : inputs) {
        if (input.isPressed) {
            switch (input.id) {
                case arcDisplay::KeyBoard::Z:
                    set_pos_pac(get_pos_pac().first, get_pos_pac().second - 1);
                    check_move_pac(arcDisplay::KeyBoard::Z);
                    break;
                case arcDisplay::KeyBoard::Q:
                    set_pos_pac(get_pos_pac().first - 1, get_pos_pac().second);
                    check_move_pac(arcDisplay::KeyBoard::Q);
                    break;
                case arcDisplay::KeyBoard::S:
                    set_pos_pac(get_pos_pac().first, get_pos_pac().second + 1);
                    check_move_pac(arcDisplay::KeyBoard::S);
                    break;
                case arcDisplay::KeyBoard::D:
                    set_pos_pac(get_pos_pac().first + 1, get_pos_pac().second);
                    check_move_pac(arcDisplay::KeyBoard::D);
                    break;
                default:
                    break;
            }
        }
    }
    for (size_t i = 0; i < this->map.size(); i++) {
        for (size_t k = 0; k < this->map[i].length(); k++) {
            if (this->map[i][k] == '.') {
                this->allbubble.push_back(arcDisplay::CircleInfo());
                this->allbubble.back().setAscii('o');
                this->allbubble.back().setPos(static_cast<float>(k * 3 + PIXEL_TO_MAP(27.5) - 0.5), static_cast<float>(i * 3 + PIXEL_TO_MAP(27.5) - 0.5));
                this->allbubble.back().setSize(0.5, 0.5);
                this->allbubble.back().setColor(255, 255, 255);
            }
            if (this->map[i][k] == 'o') {
                this->allbubble.emplace_back(arcDisplay::CircleInfo());
                this->allbubble.back().setAscii('O');
                this->allbubble.back().setPos(static_cast<float>(k * 3 + PIXEL_TO_MAP(27.5) - 1), static_cast<float>(i * 3 + PIXEL_TO_MAP(27.5) - 1));
                this->allbubble.back().setSize(1, 1);
                this->allbubble.back().setColor(255, 255, 255);
            }
            if (this->map[i][k] == 'F') {
                this->allrect.emplace_back(arcDisplay::RectInfo());
                this->allrect.back().setAscii(' ');
                this->allrect.back().setPos(static_cast<float>(k * 3), static_cast<float>(i * 3));
                this->allrect.back().setSize(2, 2);
                this->allrect.back().setColor(255, 0, 255);
            }
            if (this->map[i][k] == 'P') {
                this->allrect.emplace_back(arcDisplay::RectInfo());
                this->allrect.back().setAscii('0');
                this->allrect.back().setPos(static_cast<float>(k * 3), static_cast<float>(i * 3));
                this->allrect.back().setSize(2, 2);
                this->allrect.back().setColor(255, 255, 50);
            }
        }
    }
    return (true);
}

const std::vector<std::reference_wrapper<const arcDisplay::IInfoDisplay>> &Pacman::getInfoDisplay()
{
    this->infos.clear();
    // infos.emplace_back(std::ref(this->usage));
    for (const auto &rect : this->allrect)
        infos.emplace_back(std::ref(rect));
    for (const auto &bubble : this->allbubble)
        infos.emplace_back(std::ref(bubble));
    //     infos.emplace_back(std::ref(lib.getText()));
    // }
    return (infos);
}

long int Pacman::getScore() const
{
    return (0);
}

void check_move_pac(arcDisplay::KeyBoard::KeyID key)
{
    (void) key;
}