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
    window.setFramerateLimit(info.getFrame());

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

    if (!window.isOpen()) {
        return (false);
    }
    this->window.clear();
    for (auto &entity : info) {
        type = entity.get().getType();
        drawType(type, entity.get());
    }
    if (window.isOpen())
        this->window.display();
    else
        return (false);
    return (true);
}

bool arcDisplay::sfmlDisplayModule::close()
{
    if (window.isOpen())
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
            draw(dynamic_cast<const TextInfo &>(info.get()));
            break;
        case SPRITE:
            draw(dynamic_cast<const SpriteInfo &>(info.get()));
            break;
        case CIRCLE:
            draw(dynamic_cast<const CircleInfo &>(info.get()));
            break;
        case RECT:
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

    if (texture.find(info.getTexture()) != texture.end())
        rect.setTexture(&texture.at(info.getTexture()), true);
    else
        rect.setTexture(nullptr, true);
    rect.setSize(sf::Vector2<float>(info.getSize().first, info.getSize().second));
    rect.setPosition(info.getPos().first, info.getPos().second);
//    std::cout << "size: "<< info.getSize().first << " " << info.getSize().second << std::endl;
//    std::cout << "pos: "<< (int) info.getPos().first << " " << info.getPos().second << std::endl;
//    std::cout << "color: "<< (int) color.at(0) << " " << (int) color.at(1) << " " << (int) color.at(2) << std::endl;
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
}

const std::vector<arcDisplay::t_InfoInput> &arcDisplay::sfmlDisplayModule::getInput()
{
    sf::Event event;
    t_InfoInput input;

    inputs.clear();
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        if (event.type == sf::Event::KeyPressed || event.type == sf::Event::KeyReleased) {
            if (event.type == sf::Event::KeyPressed)
                input.isPressed = true;
            else if (event.type == sf::Event::KeyReleased)
                input.isPressed = false;
            switch (event.key.code) {
                case sf::Keyboard::A:
                    input.id = arcDisplay::KeyBoard::A;
                    inputs.emplace_back(input);
                    break;
                case sf::Keyboard::B:
                    input.id = arcDisplay::KeyBoard::B;
                    inputs.emplace_back(input);

                    break;
                case sf::Keyboard::C:
                    input.id = arcDisplay::KeyBoard::C;
                    inputs.emplace_back(input);
                    break;
                case sf::Keyboard::D:
                    input.id = arcDisplay::KeyBoard::D;
                    inputs.emplace_back(input);
                    break;
                case sf::Keyboard::E:
                    input.id = arcDisplay::KeyBoard::E;
                    inputs.emplace_back(input);
                    break;
                case sf::Keyboard::F:
                    input.id = arcDisplay::KeyBoard::F;
                    inputs.emplace_back(input);
                    break;
                case sf::Keyboard::G:
                    input.id = arcDisplay::KeyBoard::G;
                    inputs.emplace_back(input);
                    break;
                case sf::Keyboard::H:
                    input.id = arcDisplay::KeyBoard::H;
                    inputs.emplace_back(input);
                    break;
                case sf::Keyboard::I:
                    input.id = arcDisplay::KeyBoard::I;
                    inputs.emplace_back(input);
                    break;
                case sf::Keyboard::J:
                    input.id = arcDisplay::KeyBoard::J;
                    inputs.emplace_back(input);
                    break;
                case sf::Keyboard::K:
                    input.id = arcDisplay::KeyBoard::K;
                    inputs.emplace_back(input);
                    break;
                case sf::Keyboard::L:
                    input.id = arcDisplay::KeyBoard::L;
                    inputs.emplace_back(input);
                    break;
                case sf::Keyboard::M:
                    input.id = arcDisplay::KeyBoard::M;
                    inputs.emplace_back(input);
                    break;
                case sf::Keyboard::N:
                    input.id = arcDisplay::KeyBoard::N;
                    inputs.emplace_back(input);
                    break;
                case sf::Keyboard::O:
                    input.id = arcDisplay::KeyBoard::O;
                    inputs.emplace_back(input);
                    break;
                case sf::Keyboard::P:
                    input.id = arcDisplay::KeyBoard::P;
                    inputs.emplace_back(input);
                    break;
                case sf::Keyboard::Q:
                    input.id = arcDisplay::KeyBoard::Q;
                    inputs.emplace_back(input);
                    break;
                case sf::Keyboard::R:
                    input.id = arcDisplay::KeyBoard::R;
                    inputs.emplace_back(input);
                    break;
                case sf::Keyboard::S:
                    input.id = arcDisplay::KeyBoard::S;
                    inputs.emplace_back(input);
                    break;
                case sf::Keyboard::T:
                    input.id = arcDisplay::KeyBoard::T;
                    inputs.emplace_back(input);
                    break;
                case sf::Keyboard::U:
                    input.id = arcDisplay::KeyBoard::U;
                    inputs.emplace_back(input);
                    break;
                case sf::Keyboard::V:
                    input.id = arcDisplay::KeyBoard::V;
                    inputs.emplace_back(input);
                    break;
                case sf::Keyboard::W:
                    input.id = arcDisplay::KeyBoard::W;
                    inputs.emplace_back(input);
                    break;
                case sf::Keyboard::X:
                    input.id = arcDisplay::KeyBoard::X;
                    inputs.emplace_back(input);
                    break;
                case sf::Keyboard::Y:
                    input.id = arcDisplay::KeyBoard::Y;
                    inputs.emplace_back(input);
                    break;
                case sf::Keyboard::Z:
                    input.id = arcDisplay::KeyBoard::Z;
                    inputs.emplace_back(input);
                    break;
                case sf::Keyboard::Escape:
                    input.id = arcDisplay::KeyBoard::ESCAPE;
                    inputs.emplace_back(input);
                    break;
                case sf::Keyboard::Space:
                    input.id = arcDisplay::KeyBoard::SPACE;
                    inputs.emplace_back(input);
                    break;
                case sf::Keyboard::Return:
                    input.id = arcDisplay::KeyBoard::ENTER;
                    inputs.emplace_back(input);
                    break;
                case sf::Keyboard::LControl:
                    input.id = arcDisplay::KeyBoard::LCONTROL;
                    inputs.emplace_back(input);
                    break;
                case sf::Keyboard::Delete:
                    input.id = arcDisplay::KeyBoard::DELETE;
                    inputs.emplace_back(input);
                    break;
                case sf::Keyboard::LShift:
                    input.id = arcDisplay::KeyBoard::LSHIFT;
                    inputs.emplace_back(input);
                    break;
                case sf::Keyboard::LAlt:
                    input.id = arcDisplay::KeyBoard::LALT;
                    inputs.emplace_back(input);
                    break;
                case sf::Keyboard::Left:
                    input.id = arcDisplay::KeyBoard::LEFT;
                    inputs.emplace_back(input);
                    break;
                case sf::Keyboard::Right:
                    input.id = arcDisplay::KeyBoard::RIGHT;
                    inputs.emplace_back(input);
                    break;
                case sf::Keyboard::Up:
                    input.id = arcDisplay::KeyBoard::UP;
                    inputs.emplace_back(input);
                    break;
                case sf::Keyboard::Down:
                    input.id = arcDisplay::KeyBoard::DOWN;
                    inputs.emplace_back(input);
                    break;
                case sf::Keyboard::Add:
                    input.id = arcDisplay::KeyBoard::ADD;
                    inputs.emplace_back(input);
                    break;
                case sf::Keyboard::Subtract:
                    input.id = arcDisplay::KeyBoard::SUBSTRACT;
                    inputs.emplace_back(input);
                    break;
                case sf::Keyboard::Num0:
                    input.id = arcDisplay::KeyBoard::NUM0;
                    inputs.emplace_back(input);
                    break;
                case sf::Keyboard::Num1:
                    input.id = arcDisplay::KeyBoard::NUM1;
                    inputs.emplace_back(input);
                    break;
                case sf::Keyboard::Num2:
                    inputs.emplace_back(input);
                    input.id = arcDisplay::KeyBoard::NUM2;
                    break;
                case sf::Keyboard::Num3:
                    input.id = arcDisplay::KeyBoard::NUM3;
                    inputs.emplace_back(input);
                    break;
                case sf::Keyboard::Num4:
                    input.id = arcDisplay::KeyBoard::NUM4;
                    inputs.emplace_back(input);
                    break;
                case sf::Keyboard::Num5:
                    input.id = arcDisplay::KeyBoard::NUM5;
                    inputs.emplace_back(input);
                    break;
                case sf::Keyboard::Num6:
                    input.id = arcDisplay::KeyBoard::NUM6;
                    inputs.emplace_back(input);
                    break;
                case sf::Keyboard::Num7:
                    input.id = arcDisplay::KeyBoard::NUM7;
                    inputs.emplace_back(input);
                    break;
                case sf::Keyboard::Num8:
                    input.id = arcDisplay::KeyBoard::NUM8;
                    inputs.emplace_back(input);
                    break;
                case sf::Keyboard::Num9:
                    input.id = arcDisplay::KeyBoard::NUM9;
                    inputs.emplace_back(input);
                    break;
                case sf::Keyboard::F1:
                    input.id = arcDisplay::KeyBoard::F1;
                    inputs.emplace_back(input);
                    break;
                case sf::Keyboard::F2:
                    input.id = arcDisplay::KeyBoard::F2;
                    inputs.emplace_back(input);
                    break;
                case sf::Keyboard::F3:
                    input.id = arcDisplay::KeyBoard::F3;
                    inputs.emplace_back(input);
                    break;
                case sf::Keyboard::F4:
                    input.id = arcDisplay::KeyBoard::F4;
                    inputs.emplace_back(input);
                    break;
                case sf::Keyboard::F5:
                    input.id = arcDisplay::KeyBoard::F5;
                    inputs.emplace_back(input);
                    break;
                case sf::Keyboard::F6:
                    input.id = arcDisplay::KeyBoard::F6;
                    inputs.emplace_back(input);
                    break;
                case sf::Keyboard::F7:
                    input.id = arcDisplay::KeyBoard::F7;
                    inputs.emplace_back(input);
                    break;
                case sf::Keyboard::F8:
                    input.id = arcDisplay::KeyBoard::F8;
                    inputs.emplace_back(input);
                    break;
                case sf::Keyboard::F9:
                    input.id = arcDisplay::KeyBoard::F9;
                    inputs.emplace_back(input);
                    break;
                case sf::Keyboard::F10:
                    input.id = arcDisplay::KeyBoard::F10;
                    inputs.emplace_back(input);
                    break;
                case sf::Keyboard::F11:
                    input.id = arcDisplay::KeyBoard::F11;
                    inputs.emplace_back(input);
                    break;
                case sf::Keyboard::F12:
                    input.id = arcDisplay::KeyBoard::F12;
                    inputs.emplace_back(input);
                    break;
                default:
                    break;
            }
        }
    }
    return (inputs);
}