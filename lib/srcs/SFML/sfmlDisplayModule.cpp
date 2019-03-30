/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** sfmlDisplayModule.cpp
*/

#include "sfmlDisplayModule.hpp"
#include <memory>
#include <iostream>
#include <exception>

extern "C" {
    arcDisplay::sfmlDisplayModule *entryPoint()
    {
        return (new arcDisplay::sfmlDisplayModule());
    }
}

bool arcDisplay::sfmlDisplayModule::initScreen(const InitWindow &info)
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    window.create(sf::VideoMode(info.getWidth() * CHAR_SIZE, info.getHeight() * CHAR_SIZE), info.getName(), sf::Style::Default, settings);
    window.setFramerateLimit(info.getFrame());
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
        try {
            drawType(type, entity.get());
        } catch (std::exception &e) {
            std::cerr << e.what() << std::endl;
            return (false);
        }
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

    this->texture.clear();
    this->soundbuffer.clear();
    this->font.clear();

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
    else if (!info.getSound().empty()) {
        this->soundbuffer.emplace(info.getSound(), sf::SoundBuffer());
        if (!this->soundbuffer.at(info.getSound()).loadFromFile(info.getSound()))
            throw std::exception();
        sound.setBuffer(soundbuffer.at(info.getSound()));
    }
    sound.setLoop(info.isLoop());
    sound.setVolume(info.getVolume());
    if (info.isStart())
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
    if (font.find(info.getFont()) != font.end()) {
        text.setFont(font.at(info.getFont()));
    } else if (!info.getFont().empty()) {
        this->font.emplace(info.getFont(), sf::Font());
        if (!this->font.at(info.getFont()).loadFromFile(info.getFont()))
            throw std::exception();
        text.setFont(font.at(info.getFont()));
    }
    text.setPosition(info.getPos().first * CHAR_SIZE, info.getPos().second * CHAR_SIZE);
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

    if (texture.find(info.getTexture()) != texture.end()) {
        rect.setTexture(&texture.at(info.getTexture()), true);
    } else if (!info.getTexture().empty()) {
        this->texture.emplace(info.getTexture(), sf::Texture());
        if (!this->texture.at(info.getTexture()).loadFromFile(info.getTexture()))
            throw std::exception();
        rect.setTexture(&texture.at(info.getTexture()), true);
    } else {
        rect.setTexture(nullptr, true);
    }
    rect.setSize(sf::Vector2<float>(info.getSize().first * CHAR_SIZE, info.getSize().second * CHAR_SIZE));
    rect.setPosition(info.getPos().first * CHAR_SIZE, info.getPos().second * CHAR_SIZE);
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
    line[0].position = sf::Vector2<float>(info.getPos().first * CHAR_SIZE, info.getPos().second * CHAR_SIZE);
    line[1].position = sf::Vector2<float>(info.getPos2().first * CHAR_SIZE, info.getPos2().second * CHAR_SIZE);

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
                    inputs.push_back(input);
                    break;
                case sf::Keyboard::B:
                    input.id = arcDisplay::KeyBoard::B;
                    inputs.push_back(input);
                    break;
                case sf::Keyboard::C:
                    input.id = arcDisplay::KeyBoard::C;
                    inputs.push_back(input);
                    break;
                case sf::Keyboard::D:
                    input.id = arcDisplay::KeyBoard::D;
                    inputs.push_back(input);
                    break;
                case sf::Keyboard::E:
                    input.id = arcDisplay::KeyBoard::E;
                    inputs.push_back(input);
                    break;
                case sf::Keyboard::F:
                    input.id = arcDisplay::KeyBoard::F;
                    inputs.push_back(input);
                    break;
                case sf::Keyboard::G:
                    input.id = arcDisplay::KeyBoard::G;
                    inputs.push_back(input);
                    break;
                case sf::Keyboard::H:
                    input.id = arcDisplay::KeyBoard::H;
                    inputs.push_back(input);
                    break;
                case sf::Keyboard::I:
                    input.id = arcDisplay::KeyBoard::I;
                    inputs.push_back(input);
                    break;
                case sf::Keyboard::J:
                    input.id = arcDisplay::KeyBoard::J;
                    inputs.push_back(input);
                    break;
                case sf::Keyboard::K:
                    input.id = arcDisplay::KeyBoard::K;
                    inputs.push_back(input);
                    break;
                case sf::Keyboard::L:
                    input.id = arcDisplay::KeyBoard::L;
                    inputs.push_back(input);
                    break;
                case sf::Keyboard::M:
                    input.id = arcDisplay::KeyBoard::M;
                    inputs.push_back(input);
                    break;
                case sf::Keyboard::N:
                    input.id = arcDisplay::KeyBoard::N;
                    inputs.push_back(input);
                    break;
                case sf::Keyboard::O:
                    input.id = arcDisplay::KeyBoard::O;
                    inputs.push_back(input);
                    break;
                case sf::Keyboard::P:
                    input.id = arcDisplay::KeyBoard::P;
                    inputs.push_back(input);
                    break;
                case sf::Keyboard::Q:
                    input.id = arcDisplay::KeyBoard::Q;
                    inputs.push_back(input);
                    break;
                case sf::Keyboard::R:
                    input.id = arcDisplay::KeyBoard::R;
                    inputs.push_back(input);
                    break;
                case sf::Keyboard::S:
                    input.id = arcDisplay::KeyBoard::S;
                    inputs.push_back(input);
                    break;
                case sf::Keyboard::T:
                    input.id = arcDisplay::KeyBoard::T;
                    inputs.push_back(input);
                    break;
                case sf::Keyboard::U:
                    input.id = arcDisplay::KeyBoard::U;
                    inputs.push_back(input);
                    break;
                case sf::Keyboard::V:
                    input.id = arcDisplay::KeyBoard::V;
                    inputs.push_back(input);
                    break;
                case sf::Keyboard::W:
                    input.id = arcDisplay::KeyBoard::W;
                    inputs.push_back(input);
                    break;
                case sf::Keyboard::X:
                    input.id = arcDisplay::KeyBoard::X;
                    inputs.push_back(input);
                    break;
                case sf::Keyboard::Y:
                    input.id = arcDisplay::KeyBoard::Y;
                    inputs.push_back(input);
                    break;
                case sf::Keyboard::Z:
                    input.id = arcDisplay::KeyBoard::Z;
                    inputs.push_back(input);
                    break;
                case sf::Keyboard::Escape:
                    input.id = arcDisplay::KeyBoard::ESCAPE;
                    inputs.push_back(input);
                    break;
                case sf::Keyboard::Space:
                    input.id = arcDisplay::KeyBoard::SPACE;
                    inputs.push_back(input);
                    break;
                case sf::Keyboard::Return:
                    input.id = arcDisplay::KeyBoard::ENTER;
                    inputs.push_back(input);
                    break;
                case sf::Keyboard::LControl:
                    input.id = arcDisplay::KeyBoard::LCONTROL;
                    inputs.push_back(input);
                    break;
                case sf::Keyboard::Delete:
                    input.id = arcDisplay::KeyBoard::DELETE;
                    inputs.push_back(input);
                    break;
                case sf::Keyboard::LShift:
                    input.id = arcDisplay::KeyBoard::LSHIFT;
                    inputs.push_back(input);
                    break;
                case sf::Keyboard::LAlt:
                    input.id = arcDisplay::KeyBoard::LALT;
                    inputs.push_back(input);
                    break;
                case sf::Keyboard::Left:
                    input.id = arcDisplay::KeyBoard::LEFT;
                    inputs.push_back(input);
                    break;
                case sf::Keyboard::Right:
                    input.id = arcDisplay::KeyBoard::RIGHT;
                    inputs.push_back(input);
                    break;
                case sf::Keyboard::Up:
                    input.id = arcDisplay::KeyBoard::UP;
                    inputs.push_back(input);
                    break;
                case sf::Keyboard::Down:
                    input.id = arcDisplay::KeyBoard::DOWN;
                    inputs.push_back(input);
                    break;
                case sf::Keyboard::Add:
                    input.id = arcDisplay::KeyBoard::ADD;
                    inputs.push_back(input);
                    break;
                case sf::Keyboard::Subtract:
                    input.id = arcDisplay::KeyBoard::SUBSTRACT;
                    inputs.push_back(input);
                    break;
                case sf::Keyboard::Num0:
                    input.id = arcDisplay::KeyBoard::NUM0;
                    inputs.push_back(input);
                    break;
                case sf::Keyboard::Num1:
                    input.id = arcDisplay::KeyBoard::NUM1;
                    inputs.push_back(input);
                    break;
                case sf::Keyboard::Num2:
                    input.id = arcDisplay::KeyBoard::NUM2;
                    inputs.push_back(input);
                    break;
                case sf::Keyboard::Num3:
                    input.id = arcDisplay::KeyBoard::NUM3;
                    inputs.push_back(input);
                    break;
                case sf::Keyboard::Num4:
                    input.id = arcDisplay::KeyBoard::NUM4;
                    inputs.push_back(input);
                    break;
                case sf::Keyboard::Num5:
                    input.id = arcDisplay::KeyBoard::NUM5;
                    inputs.push_back(input);
                    break;
                case sf::Keyboard::Num6:
                    input.id = arcDisplay::KeyBoard::NUM6;
                    inputs.push_back(input);
                    break;
                case sf::Keyboard::Num7:
                    input.id = arcDisplay::KeyBoard::NUM7;
                    inputs.push_back(input);
                    break;
                case sf::Keyboard::Num8:
                    input.id = arcDisplay::KeyBoard::NUM8;
                    inputs.push_back(input);
                    break;
                case sf::Keyboard::Num9:
                    input.id = arcDisplay::KeyBoard::NUM9;
                    inputs.push_back(input);
                    break;
                case sf::Keyboard::F1:
                    input.id = arcDisplay::KeyBoard::F1;
                    inputs.push_back(input);
                    break;
                case sf::Keyboard::F2:
                    input.id = arcDisplay::KeyBoard::F2;
                    inputs.push_back(input);
                    break;
                case sf::Keyboard::F3:
                    input.id = arcDisplay::KeyBoard::F3;
                    inputs.push_back(input);
                    break;
                case sf::Keyboard::F4:
                    input.id = arcDisplay::KeyBoard::F4;
                    inputs.push_back(input);
                    break;
                case sf::Keyboard::F5:
                    input.id = arcDisplay::KeyBoard::F5;
                    inputs.push_back(input);
                    break;
                case sf::Keyboard::F6:
                    input.id = arcDisplay::KeyBoard::F6;
                    inputs.push_back(input);
                    break;
                case sf::Keyboard::F7:
                    input.id = arcDisplay::KeyBoard::F7;
                    inputs.push_back(input);
                    break;
                case sf::Keyboard::F8:
                    input.id = arcDisplay::KeyBoard::F8;
                    inputs.push_back(input);
                    break;
                case sf::Keyboard::F9:
                    input.id = arcDisplay::KeyBoard::F9;
                    inputs.push_back(input);
                    break;
                case sf::Keyboard::F10:
                    input.id = arcDisplay::KeyBoard::F10;
                    inputs.push_back(input);
                    break;
                case sf::Keyboard::F11:
                    input.id = arcDisplay::KeyBoard::F11;
                    inputs.push_back(input);
                    break;
                case sf::Keyboard::F12:
                    input.id = arcDisplay::KeyBoard::F12;
                    inputs.push_back(input);
                    break;
                default:
                    break;
            }
        }
    }
    return (inputs);
}