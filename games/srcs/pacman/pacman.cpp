/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** games.cpp
*/

#include "../../games/include/pacman.hpp"

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
                    next_key = arcDisplay::KeyBoard::Z;
                    break;
                case arcDisplay::KeyBoard::Q:
                    next_key = arcDisplay::KeyBoard::Q;
                    break;
                case arcDisplay::KeyBoard::S:
                    next_key = arcDisplay::KeyBoard::S;
                    break;
                case arcDisplay::KeyBoard::D:
                    next_key = arcDisplay::KeyBoard::D;
                    break;
                default:
                    break;
            }
        }
    }
    check_move_pac();
    show_case();
    this->scoreDisplay.setText("Score: " + std::to_string(this->score));
    this->lifeDisplay.setText("Life: " + std::to_string(this->life));
    return (true);
}

const std::vector<std::reference_wrapper<const arcDisplay::IInfoDisplay>> &Pacman::getInfoDisplay()
{
    this->infos.clear();
    if (this->nb_bubble == 0) {
        infos.emplace_back(std::ref(this->close));
        return (infos);
    }
    for (const auto &rect : this->allrect) {
        infos.emplace_back(std::ref(rect));
    }
    for (const auto &bubble : this->allbubble) {
        infos.emplace_back(std::ref(bubble));
    }
    for (const auto &pacm : this->pac) {
        infos.emplace_back(std::ref(pacm));
    }
    for (const auto &ghost : this->ghosts) {
        infos.emplace_back(std::ref(ghost.getRect()));
    }
    infos.emplace_back(lifeDisplay);
    infos.emplace_back(scoreDisplay);

    return (infos);
}

long int Pacman::getScore() const
{
    return (this->score);
}

void Pacman::show_case()
{
    allbubble.clear();
    for (size_t i = 0; i < this->map.size(); i++) {
        for (size_t k = 0; k < this->map[i].length(); k++) {
            if (this->map[i][k] == '.') {
                this->allbubble.emplace_back(arcDisplay::CircleInfo());
                this->allbubble.back().setAscii('o');
                this->allbubble.back().setPos(static_cast<float>(k + 0.4 + 20), static_cast<float>(i + 0.4 + 20));
                this->allbubble.back().setSize(0.2, 0.2);
                this->allbubble.back().setColor(255, 255, 255);
            }
            else if (this->map[i][k] == 'o') {
                this->allbubble.emplace_back(arcDisplay::CircleInfo());
                this->allbubble.back().setAscii('O');
                this->allbubble.back().setPos(static_cast<float>(k + 0.2 + 20), static_cast<float>(i + 0.2 + 20));
                this->allbubble.back().setSize(0.6, 0.6);
                this->allbubble.back().setColor(255, 255, 255);
            }
        }
    }
}

void Pacman::check_move_pac()
{
    static int count = 0;

    if ((count % 10) == 0 ) {
        if (next_key == arcDisplay::KeyBoard::S && map[pos_pac.second - 20 + 1][pos_pac.first - 20] != 'X')
            actual_key = next_key;
        if (next_key == arcDisplay::KeyBoard::Z && map[pos_pac.second  - 20 - 1][pos_pac.first - 20] != 'X')
            actual_key = next_key;
        if (next_key == arcDisplay::KeyBoard::D && map[pos_pac.second - 20][pos_pac.first + 1 - 20] != 'X')
            actual_key = next_key;
        if (next_key == arcDisplay::KeyBoard::Q && map[pos_pac.second - 20][pos_pac.first - 1 - 20] != 'X')
            actual_key = next_key;
    }
    if (actual_key == arcDisplay::KeyBoard::S)
        move_pac(1, 0, &count);
    if (actual_key == arcDisplay::KeyBoard::Z)
        move_pac(-1, 0, &count);
    if (actual_key == arcDisplay::KeyBoard::Q)
        move_pac(0, -1, &count);
    if (actual_key == arcDisplay::KeyBoard::D)
        move_pac(0, 1, &count);
    count++;
    if (count > 10)
        count = 10;
    this->pac.back().setPos(this->pac.back().getPos().first, this->pac.back().getPos().second);

    if (counter == 10) {
        counter = 0;
    }
    for (auto &ghost: ghosts) {
        ghost.move(counter, this->map);
    }
    counter++;
}

void Pacman::move_pac(int x, int y, int *count)
{
    if (*count % 10 == 0 && map[pos_pac.second - 20 + x][pos_pac.first - 20 + y] == 'X')
            return;
    if (*count % 10 == 0) {
        if (map[pos_pac.second - 20][pos_pac.first - 20] == '.') {
            map[pos_pac.second - 20][pos_pac.first - 20] = ' ';
            score++;
            nb_bubble--;
        }else if (map[pos_pac.second - 20][pos_pac.first - 20] == 'o') {
            map[pos_pac.second - 20][pos_pac.first - 20] = ' ';
            this->isPacInv = true;
            this->isGhostRun = true;
            score += 15;
        }
        this->pac.back().setPos(pos_pac.first, pos_pac.second);
        pos_pac.second += x;
        pos_pac.first += y;
        *count = 0;
    }
    this->pac.back().setPos(this->pac.back().getPos().first + static_cast<float>(y / 10.0), this->pac.back().getPos().second + static_cast<float>(x / 10.0));
}