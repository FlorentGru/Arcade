/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** Score.hpp
*/

#ifndef OOP_ARCADE_2018_SCORE_HPP
#define OOP_ARCADE_2018_SCORE_HPP

#include "TextInfo.hpp"
#include "InfoInput.hpp"
#include <vector>
#include <string>

class Score
{
private:
    unsigned int width;
    unsigned int height;

    arcDisplay::TextInfo scores;
    arcDisplay::TextInfo _username;

    std::vector<std::string> getFile(const std::string &filePath);
    bool isHigherScore(const std::string &line, const std::string &username, long int score, std::vector<std::string> file);
public:
    Score();

    void setUsername(const std::vector<arcDisplay::t_InfoInput> &input);
    const arcDisplay::TextInfo &getUsername();

    void readScores(std::string game);
    const arcDisplay::TextInfo &getScore();

    bool write(long int score, std::string);
    bool isLineValid(const std::string &line);

    void setWindowSize(unsigned int, unsigned int);
};


#endif //OOP_ARCADE_2018_SCORE_HPP
