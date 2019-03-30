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

const InitWindow &Nibbler::initWindow()
{
    return (window);
}

Nibbler::Nibbler() : window(960, 540)
{
    this->direction = 'l';
    this->score = 0;
    this->food = 0;
    this->height = window.getHeight() - 1;
    this->widht = window.getWidth() - 1;
    this->window.setHeight(PIXEL_TO_MAP(960));
    this->window.setWidth(PIXEL_TO_MAP(960));
    this->window.setFrame(30);
    this->window.setName("Nibbler");
    this->delay = window.getFrame() / 110000;
}

bool    Nibbler::playGame(const std::vector<arcDisplay::t_InfoInput> &inputs)
{
    // while(1){
    //     // if (collision()) {
    //     //     info.setPos(width / 2, height / 2);
    //     //     info.setText("Game Over");
    //     //     break;
    //     // }
    //     moveNibbler(inputs);
    //     usleep(delay);
    // }
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
                    if (direction != 'd')
                        direction = 'u';
                    break;
                case arcDisplay::KeyBoard::Q:
                    if (direction != 'l')
                        direction = 'r';
                    break;
                case arcDisplay::KeyBoard::S:
                    if (direction != 'u')
                        direction = 'd';
                    break;
                case arcDisplay::KeyBoard::D:
                    if (direction != 'r')
                        direction = 'l';
                    break;
                default:
                    break;
            }
        }
    }
    if (direction == 'l') {
        snake.move(-1, 0);
    } else if(direction == 'r') {
        snake.move(1, 0);
    } else if(direction == 'u') {
        snake.move(0, 1);
    } else if (direction == 'd') {
        snake.move(0, -1);
    } 
}

const std::vector<std::reference_wrapper<const arcDisplay::IInfoDisplay>> &Nibbler::getInfoDisplay()
{

}

long int Nibbler::getScore() const
{

}