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
#include <stdio.h>

namespace arcDisplay
{
    class allegroDisplayModule : public IDisplayModule
    {
    private:
        ALLEGRO_DISPLAY *window;
        ALLEGRO_FONT *font;
        ALLEGRO_EVENT event;
        ALLEGRO_TIMEOUT timeout;
        ALLEGRO_EVENT_QUEUE *event_queue;

        std::map<std::string, sf::Texture> texture;
        std::map<std::string, sf::SoundBuffer> soundbuffer;
        std::map<std::string, sf::Font> font;

        void drawType(TypeInfoDisplay, std::reference_wrapper<IInfoDisplay>);
        void draw(const WindowInfo &);  // Draw why not ? 
        void draw(const SoundInfo&);    // Draw why not ?
        void draw(const TextInfo&);
        void draw(const SpriteInfo&);
        void draw(const CircleInfo&);
        void draw(const RectInfo&);
        void draw(const LineInfo&);
    public:
        allegroDisplayModule();
        ~allegroDisplayModule();

        bool initScreen();
        bool close();
        bool display(const std::vector<std::reference_wrapper<IInfoDisplay>> &);
        std::vector<std::reference_wrapper<t_InfoInput>> getInput() const;
    };
} // arcDisplay

#endif