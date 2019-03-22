/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** sfmlDisplayModule.cpp
*/

#include "sfmlDisplayModule.hpp"
#include <memory>
#include <iostream>

extern "C" {
    arcDisplay::sfmlDisplayModule *create()
    {
        return (new arcDisplay::sfmlDisplayModule());
    }
}

bool arcDisplay::sfmlDisplayModule::initScreen(const InitWindow &info)
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    window.create(sf::VideoMode(info.getWidth(), info.getHeight()), info.getName(), sf::Style::Default, settings);

    this->soundbuffer.clear();
    this->font.clear();
    this->texture.clear();
    for (auto &_texture : info.getTextures()) {
        this->texture.emplace(_texture, sf::Texture());
        if (!this->texture.at(_texture).loadFromFile(_texture))
            return (false);
    }
    for (auto &_sound : info.getSounds()) {
        this->soundbuffer.emplace(_sound, sf::SoundBuffer());
        if (!this->soundbuffer.at(_sound).loadFromFile(_sound))
            return (false);
    }
    for (auto &_font : info.getFonts()) {
        this->font.emplace(_font, sf::Font());
        if (!this->font.at(_font).loadFromFile(_font))
            return (false);
    }
    return (true);
}

bool arcDisplay::sfmlDisplayModule::display(const std::vector<std::reference_wrapper<const IInfoDisplay>> &info)
{
    TypeInfoDisplay type;

    std::cout << "new: " << std::endl;
    this->window.clear();
    for (auto &entity : info) {
        type = entity.get().getType();
        drawType(type, entity.get());
    }
    this->window.display();
    return (true);
}

const std::vector<arcDisplay::t_InfoInput> &arcDisplay::sfmlDisplayModule::getInput() const
{
    return (inputs);
}

bool arcDisplay::sfmlDisplayModule::close()
{
    window.close();
    return (true);
}

void arcDisplay::sfmlDisplayModule::drawType(TypeInfoDisplay type, std::reference_wrapper<const IInfoDisplay> info)
{
    switch (type) {
        case WINDOW:
            draw(dynamic_cast<const WindowInfo &>(info.get()));
            break;
        case SOUND:
            draw(dynamic_cast<const SoundInfo &>(info.get()));
            break;
        case TEXT:
            std::cout << "text" << std::endl;
            draw(dynamic_cast<const TextInfo &>(info.get()));
            break;
        case SPRITE:
            draw(dynamic_cast<const SpriteInfo &>(info.get()));
            break;
        case CIRCLE:
            draw(dynamic_cast<const CircleInfo &>(info.get()));
            break;
        case RECT:
            std::cout << "rect" << std::endl;
            draw(dynamic_cast<const RectInfo &>(info.get()));
            break;
        case LINE:
            draw(dynamic_cast<const LineInfo &>(info.get()));
            break;
        default:
            break;
    }
}

void arcDisplay::sfmlDisplayModule::draw(const WindowInfo &info)
{
    if (info.isClosed()) {
        window.close();
    }
}

void arcDisplay::sfmlDisplayModule::draw(const SoundInfo &info)
{
    if (soundbuffer.find(info.getSound()) != soundbuffer.end())
        sound.setBuffer(soundbuffer.at(info.getSound()));
    sound.setLoop(info.getLoop());
    sound.setVolume(info.getVolume());
    if (info.getStart())
        sound.play();
    else
        sound.stop();
//  surement avoir besoin de plusieurs sons (un par buffer)
}

void arcDisplay::sfmlDisplayModule::draw(const TextInfo &info)
{
    std::vector<unsigned char> color = info.getColor();

    text.setCharacterSize(info.getSize());
    text.setFillColor(sf::Color(color.at(0), color.at(1), color.at(2)));
    if (font.find(info.getFont()) != font.end())
        text.setFont(font.at(info.getFont()));
    text.setPosition(info.getPos().first, info.getPos().second);
    text.setString(info.getText());
    window.draw(text);
}

void arcDisplay::sfmlDisplayModule::draw(const SpriteInfo &info)
{
    std::vector<unsigned char> color = info.getColor();

    if (texture.find(info.getTexture()) != texture.end())
        sprite.setTexture(texture.at(info.getTexture()), true);
    sprite.setPosition(info.getPos().first, info.getPos().second);
    sprite.setTextureRect(sf::Rect<int>(info.getPosRect().first, info.getPosRect().second, info.getSizeRect().first, info.getSizeRect().second));
    sprite.setColor(sf::Color(color.at(0), color.at(1), color.at(2)));
    window.draw(sprite);
}

void arcDisplay::sfmlDisplayModule::draw(const CircleInfo &info)
{
    std::vector<unsigned char> color = info.getColor();

    if (texture.find(info.getTexture()) != texture.end())
        circle.setTexture(&texture.at(info.getTexture()), true);
    else
        circle.setTexture(nullptr, true);
    circle.setRadius(info.getSize().first);
    circle.setPosition(info.getPos().first, info.getPos().second);
    circle.setFillColor(sf::Color(color.at(0), color.at(1), color.at(2)));
    window.draw(circle);
}

void arcDisplay::sfmlDisplayModule::draw(const RectInfo &info)
{
    std::vector<unsigned char> color = info.getColor();

//    if (texture.find(info.getTexture()) != texture.end())
//        rect.setTexture(&texture.at(info.getTexture()), true);
//    else
//        rect.setTexture(nullptr, true);
    rect.setSize(sf::Vector2<float>(info.getSize().first, info.getSize().second));
    rect.setPosition(info.getPos().first, info.getPos().second);
    std::cout << "size: "<< info.getSize().first << " " << info.getSize().second << std::endl;
    std::cout << "pos: "<< (int) info.getPos().first << " " << info.getPos().second << std::endl;
    std::cout << "color: "<< (int) color.at(0) << " " << (int) color.at(1) << " " << (int) color.at(2) << std::endl;
    rect.setFillColor(sf::Color(color.at(0), color.at(1), color.at(2)));
    window.draw(rect);
}

void arcDisplay::sfmlDisplayModule::draw(const LineInfo &info)
{
    std::vector<unsigned char> color = info.getColor();

    line[0].color = sf::Color(color.at(0), color.at(1), color.at(2));
    line[1].color = sf::Color(color.at(0), color.at(1), color.at(2));
    line[0].position = sf::Vector2<float>(info.getPos().first, info.getPos().second);
    line[1].position = sf::Vector2<float>(info.getPosition2().first, info.getPosition2().second);

    window.draw(&line[0], line.size(), sf::Lines);
;}