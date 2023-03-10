/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** DisplayModule.hpp
*/

#ifndef ALLEGRODISPLAYMODULE_HPP
#define ALLEGRODISPLAYMODULE_HPP

#include "IDisplayModule.hpp"
#include "WindowInfo.hpp"
#include "SoundInfo.hpp"
#include "TextInfo.hpp"
#include "SpriteInfo.hpp"
#include "CircleInfo.hpp"
#include "RectInfo.hpp"
#include "LineInfo.hpp"
#include <map>
#include <allegro5/allegro.h>
#include <allegro5/allegro_ttf.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>
#include <stdio.h>

namespace arcDisplay
{
    int CHAR_SIZE = 15;

    class allegroDisplayModule : public IDisplayModule
    {
    private:
        ALLEGRO_DISPLAY *window;
        ALLEGRO_FONT *_font;
        ALLEGRO_TIMER *timer;
        ALLEGRO_EVENT_QUEUE *event_queue;
        ALLEGRO_SAMPLE *sample;

        std::vector<arcDisplay::t_InfoInput> inputs;

        void drawType(TypeInfoDisplay, std::reference_wrapper<const IInfoDisplay>);
        void draw(const WindowInfo &);  // Draw why not ? 
        void draw(const SoundInfo&);    // Draw why not ?
        void draw(const TextInfo&);
        void draw(const SpriteInfo&);
        void draw(const CircleInfo&);
        void draw(const RectInfo&);
        void draw(const LineInfo&);
    public:
        allegroDisplayModule();
        bool initScreen(const InitWindow &info) override;
        bool close() override;
        bool display(const std::vector<std::reference_wrapper<const IInfoDisplay>> &) override;
        const std::vector<t_InfoInput> &getInput() override;
        bool check_event(ALLEGRO_EVENT &event);
    };
} // arcDisplay

#endif