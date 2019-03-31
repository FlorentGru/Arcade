/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** nibbler.cpp
*/

#include "nibbler.hpp"
#include "snake.hpp"
#include "food.hpp"

extern "C" {
    Nibbler *gameInstance()
    {
        return (new Nibbler());
    }
}

Nibbler::Nibbler() : window(PIXEL_TO_MAP(960), PIXEL_TO_MAP(650))
{
    this->score = 0;
    this->die = false;

    this->x = 1;
    this->y = 0;

    this->height = window.getHeight() - 1;
    this->width = window.getWidth() - 1;
    this->delay = window.getFrame();
    this->closeWindow.setClose(true);

    this->snake.setWidth(width);
    this->snake.setHeight(height);
    this->snake.setPosSnake(width / 2, height / 2);

    this->fruits.setWidth(width);
    this->fruits.setHeight(height);
    this->fruits.setPosFood(snake);

    int i = 0;

    for (; i < this->width; ++i) {
        this->edges.push_back(arcDisplay::RectInfo());
        this->edges.at(i).setAscii(' ');
        this->edges.at(i).setColor(10, 99, 255);
        this->edges.at(i).setSize(1, 1);
        this->edges.at(i).setPos(i, 0);
    }
    for (int j = 0; j < this->width; ++j) {
        this->edges.push_back(arcDisplay::RectInfo());
        this->edges.at(i).setAscii(' ');
        this->edges.at(i).setColor(10, 99, 255);
        this->edges.at(i).setSize(1, 1);
        this->edges.at(i).setPos(j, height);
        i++;
    }
    for (int j = 0; j < this->height; ++j) {
        this->edges.push_back(arcDisplay::RectInfo());
        this->edges.at(i).setAscii(' ');
        this->edges.at(i).setColor(10, 99, 255);
        this->edges.at(i).setSize(1, 1);
        this->edges.at(i).setPos(0, j);
        i++;
    }
    for (int j = 0; j < this->height + 1; ++j) {
        this->edges.push_back(arcDisplay::RectInfo());
        this->edges.at(i).setAscii(' ');
        this->edges.at(i).setColor(10, 99, 255);
        this->edges.at(i).setSize(1, 1);
        this->edges.at(i).setPos(width, j);
        i++;
    }
    
}

const InitWindow &Nibbler::initWindow()
{
    this->window.setFrame(15);
    this->window.setName("Nibbler");
    return (window);
}

bool    Nibbler::playGame(const std::vector<arcDisplay::t_InfoInput> &inputs)
{
    moveNibbler(inputs);
    return (true);
}

void Nibbler::moveNibbler(const std::vector<arcDisplay::t_InfoInput> &inputs)
{
    for(auto &input : inputs) {
        if (input.isPressed) {
            switch (input.id) {
                case arcDisplay::KeyBoard::Z:
                    if (y != 1) {
                        x = 0;
                        y = -1;
                    }
                    break;
                case arcDisplay::KeyBoard::Q:
                    if (x != 1) {
                        x = -1;
                        y = 0;
                    }
                    break;
                case arcDisplay::KeyBoard::S:
                    if (y != -1) {
                        x = 0;
                        y = 1;
                    }
                    break;
                case arcDisplay::KeyBoard::D:
                    if (x != -1) {
                        x = 1;
                        y = 0;
                    }
                    break;
                default:
                    break;
            }
        }
    }
    if (snake.move(x, y) == false) {
        die = true;
    }
    if (fruits.eatFruits(snake) == true) {
        score += 10;
        snake.grow();
        fruits.setPosFood(snake);
    }
    if (fruits.getFruits().empty()) {
        score += 50;
        die = true;
    }
}

const std::vector<std::reference_wrapper<const arcDisplay::IInfoDisplay>> &Nibbler::getInfoDisplay()
{
    infos.clear();
    if (die == true) {
        infos.emplace_back(std::ref(closeWindow));
        return (infos);
    }
    for (auto &rect : this->snake.getSnake())
        infos.emplace_back(std::ref(rect));
    for (auto &food : this->fruits.getFruits())
        infos.emplace_back(std::ref(food));
    for (auto &wall : this->edges) {
        infos.emplace_back(std::ref(wall));
    }

    return (this->infos);
}

long int Nibbler::getScore() const
{
    return (this->score);
}