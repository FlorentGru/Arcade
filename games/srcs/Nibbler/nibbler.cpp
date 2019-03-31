/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** nibbler.cpp
*/

#include "nibbler.hpp"
#include "snake.hpp"

extern "C" {
    Nibbler *gameInstance()
    {
        return (new Nibbler());
    }
}


Nibbler::Nibbler() : window(PIXEL_TO_MAP(960), PIXEL_TO_MAP(960))
{
    this->score = 100;
    this->food = 0;
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
}

const InitWindow &Nibbler::initWindow()
{
    this->window.setFrame(30);
    this->window.setName("Nibbler");
    return (window);
}

bool    Nibbler::playGame(const std::vector<arcDisplay::t_InfoInput> &inputs)
{
    //while(1){
    // if (collision()) {
    //     info.setPos(width / 2, height / 2);
    //     info.setText("Game Over");
    //     break;
    // }
    moveNibbler(inputs);
    //usleep(delay);
    //}
    return (true);
}

// bool Nibbler::collision()
// {
//     if (snake.getSnake().at(0) == 0 || snake.getSnake().at(0) == widht || snake.getSnake().at(0) == height)
//         return (true);
//     if (body.at(0) == ) {
//         food = true;
//         createFood();
//         score += 10;
//         //Move
//         setText(score);
//         if ((score % 100) == 0)
//             delay -= 1000;
//     }else
//         food = false;
//     return (false);
// }

void Nibbler::createFood()
{
    return;
}

void Nibbler::moveNibbler(const std::vector<arcDisplay::t_InfoInput> &inputs)
{
    for(auto input : inputs) {
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
    // if (direction == 'l') {
    //     snake.move(-1, 0);
    // } else if(direction == 'r') {
    //     snake.move(1, 0);
    // } else if(direction == 'u') {
    //     snake.move(0, -1);
    // } else if (direction == 'd') {
    //     snake.move(0, 1);
    // } 
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
    
    return (this->infos);
}

long int Nibbler::getScore() const
{
    return (score);
}