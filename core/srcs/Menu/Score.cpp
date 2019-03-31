/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Score.cpp
*/

#include "Menu/Score.hpp"
#include <fstream>
#include <iostream>

Score::Score()
{
    this->scores.setFont("./rsc/font/WC_RoughTrad.ttf");
    this->scores.setSize(30);

    this->_username.setFont("./rsc/font/WC_RoughTrad.ttf");
    this->_username.setSize(30);
    this->_username.setText("Enter username: ");
}

std::vector<std::string> Score::getFile(const std::string &filePath)
{
    std::ifstream file(filePath, std::ios_base::in);
    std::vector<std::string> lines;

    if (!file.is_open()) {
        return (lines);
    }
    for (std::string line; std::getline(file, line); lines.push_back(line));
    file.close();
    return (lines);
}

void Score::readScores(std::string game)
{
    std::ifstream file;
    std::string score;

    if (game.empty())
        return;
    game = std::string("./games/score/").append(game);

    file.open(game, std::ios_base::in);
    if (!file.is_open()) {
        scores.setText("No score yet for " + game);
        scores.setPos(width / 2 - scores.getText().size() / 2, height / 2 - 3);
        return;
    }

    score = "Scores: ";
    for (size_t i = 0; std::getline(file, game); i++) {
        if (!isLineValid(game)) {
            scores.setText("Error: invalid file format (line " + std::to_string(i) + ")");
            scores.setPos(width / 2 - scores.getText().size() / 2, height / 2 - 3);
            file.close();
            return;
        }
        if (score.size() + game.size() < width)
            score += " " + game;
    }
    scores.setText(score);
    scores.setPos(width / 2 - scores.getText().size() / 2, height / 2 - 3);
    file.close();
}

bool Score::isLineValid(const std::string &line)
{
    size_t pos = 0;

    if (line.find('=') == std::string::npos || line.find('=') == 0) {
        return (false);
    }
    pos = line.find('=') + 1;
    try {
        std::stoi(&line[pos]);
    } catch (std::invalid_argument &e) {
        return (false);
    }
    return (true);
}

bool Score::write(long int score, std::string filePath)
{
    std::vector<std::string> file;
    std::ofstream out;
    std::string username = _username.getText();

    username = username.substr(username.rfind(' ') + 1);
    if (filePath.empty())
        return (false);
    if (username.empty()) {
        username = "Player one";
    }
    filePath = std::string("./games/score/").append(filePath);
    file = getFile(filePath);

    for (auto &line : file) {
        if (isHigherScore(line, username, score, file)) {
            line = username + "=" + std::to_string(score);

            out.open(filePath, std::ios_base::out | std::ios_base::trunc);
            if (!out.is_open()) {
                return (false);
            }

            for (auto &add : file)
                out << add << std::endl;
            out.close();
            return (true);
        }
    }
    if (file.size() > 3) {
        return (true);
    }
    out.open(filePath, std::ios_base::app);
    if (!out.is_open())
        return (false);
    out << username << '=' << score << std::endl;
    out.close();
    return (true);
}

bool Score::isHigherScore(const std::string &line, const std::string &username, long int score, std::vector<std::string> file)
{
    size_t pos = line.find('=') + 1;
    long int lineScore = std::stoi(&line[pos]);
    long int otherScore = 0;
    size_t otherPos = 0;

    if (line.substr(0, line.find('=')) == username && lineScore <= score)
        return (true);
    if (file.size() >= 4 && lineScore < score) {
        for (auto &other : file) {
            otherPos = other.find('=') + 1;
            otherScore = std::stoi(&other[otherPos]);
            if (lineScore < otherScore) {
                return (true);
            }
        }
    }
    return (false);
}

void Score::setUsername(const std::vector<arcDisplay::t_InfoInput> &inputs)
{
    std::string username = _username.getText();

    for (auto &input : inputs) {
        if (input.isPressed) {
            switch (input.id) {
                case arcDisplay::KeyBoard::A:
                    username += 'A';
                    break;
                case arcDisplay::KeyBoard::B:
                    username += 'B';
                    break;
                case arcDisplay::KeyBoard::C:
                    username += 'C';
                    break;
                case arcDisplay::KeyBoard::D:
                    username += 'D';
                    break;
                case arcDisplay::KeyBoard::E:
                    username += 'E';
                    break;
                case arcDisplay::KeyBoard::F:
                    username += 'F';
                    break;
                case arcDisplay::KeyBoard::G:
                    username += 'G';
                    break;
                case arcDisplay::KeyBoard::H:
                    username += 'H';
                    break;
                case arcDisplay::KeyBoard::I:
                    username += 'I';
                    break;
                case arcDisplay::KeyBoard::J:
                    username += 'J';
                    break;
                case arcDisplay::KeyBoard::K:
                    username += 'K';
                    break;
                case arcDisplay::KeyBoard::L:
                    username += 'L';
                    break;
                case arcDisplay::KeyBoard::M:
                    username += 'M';
                    break;
                case arcDisplay::KeyBoard::N:
                    username += 'N';
                    break;
                case arcDisplay::KeyBoard::O:
                    username += 'O';
                    break;
                case arcDisplay::KeyBoard::P:
                    username += 'P';
                    break;
                case arcDisplay::KeyBoard::Q:
                    username += 'Q';
                    break;
                case arcDisplay::KeyBoard::R:
                    username += 'R';
                    break;
                case arcDisplay::KeyBoard::S:
                    username += 'S';
                    break;
                case arcDisplay::KeyBoard::T:
                    username += 'T';
                    break;
                case arcDisplay::KeyBoard::U:
                    username += 'U';
                    break;
                case arcDisplay::KeyBoard::V:
                    username += 'V';
                    break;
                case arcDisplay::KeyBoard::W:
                    username += 'W';
                    break;
                case arcDisplay::KeyBoard::X:
                    username += 'X';
                    break;
                case arcDisplay::KeyBoard::Y:
                    username += 'Y';
                    break;
                case arcDisplay::KeyBoard::Z:
                    username += 'Z';
                    break;
                case arcDisplay::KeyBoard::DELETE:
                    if (username.size() > 16)
                        username.pop_back();
                    break;
                default:
                    break;
            }
        }
    }
    this->_username.setText(username);
}

void Score::setWindowSize(unsigned int _width, unsigned int _height)
{
    this->width = _width;
    this->height = _height;

    this->_username.setPos(width / 4, height / 2);
}

const arcDisplay::TextInfo &Score::getUsername()
{
    return (this->_username);
}

const arcDisplay::TextInfo &Score::getScore()
{
    return (this->scores);
}