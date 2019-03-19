/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** sfmlDisplayModule.cpp
*/

#include "sfmlDisplayModule.hpp"
#include <memory>

extern "C" {
    arcDisplay::sfmlDisplayModule create()
    {
        return (arcDisplay::sfmlDisplayModule());
    }
}

bool arcDisplay::sfmlDisplayModule::initScreen(const InitWindow &info)
{
    window.create(sf::VideoMode(info.getWidth(), info.getHeight()), info.getName());

    this->soundbuffer.clear();
    this->font.clear();
    this->texture.clear();
    for (auto &texture : info.getTextures()) {
        this->texture.emplace(texture, sf::Texture());
        if (!this->texture.at(texture).loadFromFile(texture))
            return (false);
    }
    for (auto &sound : info.getSounds()) {
        this->soundbuffer.emplace(sound, sf::SoundBuffer());
        if (!this->soundbuffer.at(sound).loadFromFile(sound))
            return (false);
    }
    for (auto &font : info.getFonts()) {
        this->font.emplace(font, sf::Font());
        if (!this->font.at(font).loadFromFile(font))
            return (false);
    }
    return (true);
}

bool arcDisplay::sfmlDisplayModule::display(const std::vector<std::reference_wrapper<IInfoDisplay>> &info)
{
    TypeInfoDisplay type;

    this->window.clear();
    for (auto &entity : info) {
        type = entity.get().getType();
        drawType(type, entity.get());
    }
    this->window.display();
    return (true);
}

bool arcDisplay::sfmlDisplayModule::close()
{
    window.close();
    return (true);
}

void arcDisplay::sfmlDisplayModule::drawType(TypeInfoDisplay type, std::reference_wrapper<IInfoDisplay> info)
{
    switch (type) {
        case WINDOW:
            draw(dynamic_cast<WindowInfo &>(info.get()));
            break;
        case SOUND:
            draw(dynamic_cast<SoundInfo &>(info.get()));
            break;
        case TEXT:
            draw(dynamic_cast<TextInfo &>(info.get()));
            break;
        case SPRITE:
            draw(dynamic_cast<SpriteInfo &>(info.get()));
            break;
        case CIRCLE:
            draw(dynamic_cast<CircleInfo &>(info.get()));
            break;
        case RECT:
            draw(dynamic_cast<RectInfo &>(info.get()));
            break;
        case LINE:
            draw(dynamic_cast<LineInfo &>(info.get()));
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
        sprite.setTexture(texture.at(info.getTexture()));
    sprite.setPosition(info.getPos().first, info.getPos().second);
    sprite.setTextureRect(sf::Rect<int>(info.getPosRect().first, info.getPosRect().second, info.getSizeRect().first, info.getSizeRect().second));
    sprite.setColor(sf::Color(color.at(0), color.at(1), color.at(2)));
    window.draw(sprite);
}

void arcDisplay::sfmlDisplayModule::draw(const CircleInfo &info)
{
    std::vector<unsigned char> color = info.getColor();

    if (texture.find(info.getTexture()) != texture.end())
        circle.setTexture(&texture.at(info.getTexture()));
    circle.setRadius(info.getSize().first);
    circle.setPosition(info.getPos().first, info.getPos().second);
    circle.setFillColor(sf::Color(color.at(0), color.at(1), color.at(2)));
    window.draw(circle);
}

void arcDisplay::sfmlDisplayModule::draw(const RectInfo &info)
{
    std::vector<unsigned char> color = info.getColor();

    if (texture.find(info.getTexture()) != texture.end())
        rect.setTexture(&texture.at(info.getTexture()));
    rect.setSize(sf::Vector2<float>(info.getSize().first, info.getSize().second));
    rect.setPosition(info.getPos().first, info.getPos().second);
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