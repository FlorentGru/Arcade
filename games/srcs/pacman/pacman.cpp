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
//                    set_pos_pac(get_pos_pac().first, get_pos_pac().second);
                    check_move_pac(arcDisplay::KeyBoard::Z);
                    break;
                case arcDisplay::KeyBoard::Q:
//                    set_pos_pac(get_pos_pac().first - (1/15), get_pos_pac().second);
                    check_move_pac(arcDisplay::KeyBoard::Q);
                    break;
                case arcDisplay::KeyBoard::S:
//                    set_pos_pac(get_pos_pac().first, get_pos_pac().second + (1/15));
                    check_move_pac(arcDisplay::KeyBoard::S);
                    break;
                case arcDisplay::KeyBoard::D:
//                    set_pos_pac(get_pos_pac().first + (1/15), get_pos_pac().second);
                    check_move_pac(arcDisplay::KeyBoard::D);
                    break;
                default:
                    break;
            }
        }
    }
    show_case();
    this->pac.back().setPos(static_cast<float>(pos_pac.first), static_cast<float>(pos_pac.second));
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
    for (const auto &pacm : this->pac)
        infos.emplace_back(std::ref(pacm));
    return (infos);
}

long int Pacman::getScore() const
{
    return (0);
}

void Pacman::show_case()
{
    for (size_t i = 0; i < this->map.size(); i++) {
        for (size_t k = 0; k < this->map[i].length(); k++) {
            if (this->map[i][k] == '.') {
                this->allbubble.push_back(arcDisplay::CircleInfo());
                this->allbubble.back().setAscii('o');
                this->allbubble.back().setPos(static_cast<float>(k + 0.4), static_cast<float>(i + 0.4));
                this->allbubble.back().setSize(0.2, 0.2);
                this->allbubble.back().setColor(255, 255, 255);
            }
            else if (this->map[i][k] == 'o') {
                this->allbubble.emplace_back(arcDisplay::CircleInfo());
                this->allbubble.back().setAscii('O');
                this->allbubble.back().setPos(static_cast<float>(k + 0.2), static_cast<float>(i + 0.2));
                this->allbubble.back().setSize(0.6, 0.6);
                this->allbubble.back().setColor(255, 255, 255);
            }
            else if (this->map[i][k] == 'F') {
                this->allrect.emplace_back(arcDisplay::RectInfo());
                this->allrect.back().setAscii(' ');
                this->allrect.back().setPos(static_cast<float>(k), static_cast<float>(i));
                this->allrect.back().setSize(1, 1);
                this->allrect.back().setColor(255, 0, 255);
            }
        }
    }
}

void Pacman::check_move_pac(arcDisplay::KeyBoard::KeyID key)
{
    // if ((this->pos_pac.first % 15) == 0)
        
    std::cout << pos_pac.first << " & " << pos_pac.second << std::endl;
    if (key == arcDisplay::KeyBoard::S)
        if ((pac.second - static_cast<int>pac.second) == 0)
        this->pos_pac.second += 0.1;
    if (key == arcDisplay::KeyBoard::Z)
        this->pos_pac.second -= 0.1;
    if (key == arcDisplay::KeyBoard::Q)
        this->pos_pac.first -= 0.1;
    if (key == arcDisplay::KeyBoard::D)
        this->pos_pac.first += 0.1;
    this->pac.back().setPos(static_cast<float>(pos_pac.first), static_cast<float>(pos_pac.second)); 
}