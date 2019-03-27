/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** SoundInfo.hpp
*/

#ifndef SOUNDINFO_HPP
#define SOUNDINFO_HPP

#include "IInfoDisplay.hpp"
#include <string>

namespace arcDisplay
{
    class SoundInfo : public IInfoDisplay
    {
    private:
        std::string _sound;
        size_t _volume;
        bool _loop;
        bool _start;
    public:
        enum TypeInfoDisplay getType() const override;

        const std::string &getSound() const;
        size_t getVolume() const;
        bool isLoop() const;
        bool isStart() const;

        void setSound(const std::string &);
        void setVolume(size_t);
        void setLoop(bool);
        void setStart(bool);
    };
} // arcDisplay


#endif