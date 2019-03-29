/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** SoundInfo.hpp
*/

#ifndef OOP_ARCADE_2018_SOUNDINFO_HPP
#define OOP_ARCADE_2018_SOUNDINFO_HPP

#include <string>
#include "IInfoDisplay.hpp"

namespace arcDisplay {
    class SoundInfo : public IInfoDisplay {
    public:
        const std::string &getSound() const;
        void setSound(const std::string &sound);
        size_t getVolume() const;
        void setVolume(size_t volume);
        bool isLoop() const;
        void setLoop(bool loop);
        bool isStart() const;
        void setStart(bool start);
        enum TypeInfoDisplay getType() const override;

    private:
        std::string _sound;
        size_t _volume;
        bool _loop;
        bool _start;
    };
}

#endif //OOP_ARCADE_2018_SOUNDINFO_HPP
