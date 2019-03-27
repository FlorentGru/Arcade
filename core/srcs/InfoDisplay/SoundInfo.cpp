/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** SoundInfo.cpp
*/

#include "SoundInfo.hpp"

/*###############################
## GET TYPE
###############################*/

arcDisplay::TypeInfoDisplay arcDisplay::SoundInfo::getType() const
{
    return (arcDisplay::SOUND);
}

/*###############################
## SETTER AND GETTER
###############################*/

const std::string &arcDisplay::SoundInfo::getSound() const
{  
    return (this->_sound);
}

size_t arcDisplay::SoundInfo::getVolume() const
{
    return (this->_volume);
}

bool arcDisplay::SoundInfo::isLoop() const
{
    return (this->_loop);
}

bool arcDisplay::SoundInfo::isStart() const
{
    return (this->_start);
}

void arcDisplay::SoundInfo::setSound(const std::string &sound)
{
    this->_sound = sound;
}

void arcDisplay::SoundInfo::setVolume(size_t vol)
{
    this->_volume = vol;
}

void arcDisplay::SoundInfo::setLoop(bool loop)
{
    this->_loop = loop;
}

void arcDisplay::SoundInfo::setStart(bool start)
{
    this->_start = start;
}