/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** DisplayModule.hpp
*/

#ifndef SFMLDISPLAYMODULE_HPP
#define SFMLDISPLAYMODULE_HPP

#include "IDisplayModule.hpp"
#include "WindowInfo.hpp"
#include "SoundInfo.hpp"
#include "TextInfo.hpp"
#include "SpriteInfo.hpp"
#include "CircleInfo.hpp"
#include "RectInfo.hpp"
#include "LineInfo.hpp"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <map>
#include <functional>

namespace arcDisplay
{
    class sfmlDisplayModule : public IDisplayModule
    {
    private:
        sf::RenderWindow window;
        sf::Text text;
        sf::Sound sound;
        sf::Sprite sprite;
        sf::RectangleShape rect;
        sf::CircleShape circle;
        std::vector<sf::Vertex> line;

        std::map<std::string, sf::Texture> texture;
        std::map<std::string, sf::SoundBuffer> soundbuffer;
        std::map<std::string, sf::Font> font;

        std::vector<arcDisplay::t_InfoInput> inputs;

        void drawType(TypeInfoDisplay, std::reference_wrapper<const IInfoDisplay>);
        void draw(const WindowInfo &);
        void draw(const SoundInfo &);
        void draw(const TextInfo &);
        void draw(const SpriteInfo &);
        void draw(const CircleInfo &);
        void draw(const RectInfo &);
        void draw(const LineInfo &);
    public:
        bool initScreen(const InitWindow &info) override;
        bool close() override;
        bool display(const std::vector<std::reference_wrapper<const IInfoDisplay>> &) override;
        const std::vector<t_InfoInput> &getInput() const override;
    };
} // arcDisplay

#endif