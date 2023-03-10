/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** ncursesDiplayModule.cpp
*/

#include "ncursesDisplayModule.hpp"
#include <iostream>

extern "C" {
    arcDisplay::ncursesDisplayModule *entryPoint()
    {
        return (new arcDisplay::ncursesDisplayModule());
    }
}

bool arcDisplay::ncursesDisplayModule::display(const std::vector<std::reference_wrapper<const IInfoDisplay>> &info)
{
    TypeInfoDisplay type;
    getmaxyx(stdscr, maxheight, maxwidth);
    clear();
    //if (height > maxheight || width > maxwidth) {
    //    mvprintw(maxheight / 2, maxwidth / 2 - 10, "Terminal too small\n");
    //} else {
        iterator = 0;
        for (auto &entity : info) {
            iterator++;
            type = entity.get().getType();
            if (!drawType(type, entity.get()))
                return (false);
        }
    //}
    refresh();
    usleep(1000000/frame);
    return (true);
}

bool arcDisplay::ncursesDisplayModule::initScreen(const InitWindow &info)
{
    frame = info.getFrame();
    initscr();
    height = info.getHeight();
    width = info.getWidth();
    nodelay(stdscr, true);
    keypad(stdscr, true);
    noecho();
    curs_set(0);
    start_color();
    init_pair(1, COLOR_WHITE, COLOR_BLACK);
    init_pair(2, COLOR_WHITE, COLOR_WHITE);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    init_pair(4, COLOR_RED, COLOR_RED);
    init_pair(5, COLOR_GREEN, COLOR_BLACK);
    init_pair(6, COLOR_GREEN, COLOR_GREEN);
    init_pair(7, COLOR_BLUE, COLOR_BLACK);
    init_pair(8, COLOR_BLUE, COLOR_BLUE);
    init_pair(9, COLOR_YELLOW, COLOR_BLACK);
    init_pair(10, COLOR_YELLOW, COLOR_YELLOW);
    init_pair(11, COLOR_MAGENTA, COLOR_BLACK);
    init_pair(12, COLOR_MAGENTA, COLOR_MAGENTA);
    init_pair(13, COLOR_CYAN, COLOR_BLACK);
    init_pair(14, COLOR_CYAN, COLOR_CYAN);
    if(has_colors() == FALSE) {	
	    endwin();
	    printf("Your terminal does not support color\n");
	exit(1);
	}
    return (true);
}

bool arcDisplay::ncursesDisplayModule::close()
{
    endwin();
    return (true);
}

bool arcDisplay::ncursesDisplayModule::drawType(TypeInfoDisplay type, std::reference_wrapper<const IInfoDisplay> info)
{
    switch (type) {
        case WINDOW:
            return (draw(dynamic_cast<const WindowInfo &>(info.get())));
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
    return (true);
}

bool arcDisplay::ncursesDisplayModule::draw(const WindowInfo &info)
{
    if (info.isClosed()) {
        endwin();
        return (false);
    }
    return (true);
}

void arcDisplay::ncursesDisplayModule::draw(const SoundInfo &info)
{
    (void) info;
    return;
}

void arcDisplay::ncursesDisplayModule::draw(const TextInfo &info)
{
    short nb = convertColor(info.getColor().at(0), info.getColor().at(1), info.getColor().at(2)) + 1;
    attron(COLOR_PAIR(nb));
    move(static_cast<int> (info.getPos().second), static_cast<int> (info.getPos().first));
    printw(info.getText().c_str());
}

void arcDisplay::ncursesDisplayModule::draw(const SpriteInfo &info)
{
    (void) info;
    return;
}

void arcDisplay::ncursesDisplayModule::draw(const CircleInfo &info)
{
    std::vector<unsigned char> color = info.getColor();

    short nb = convertColor(color.at(0), color.at(1), color.at(2)) + 1;
    if (info.getAscii() != ' ')
        attron(COLOR_PAIR(nb));
    else
        attron(COLOR_PAIR(nb + 1));
    for (int i = 0; i < info.getSize().second; i++) {
        for (int j = 0; j < info.getSize().first; j++)
            mvprintw(static_cast<int> (info.getPos().second) + i, static_cast<int> (info.getPos().first) + j, "%c", info.getAscii());
    }
}

void arcDisplay::ncursesDisplayModule::draw(const RectInfo &info)
{
    std::vector<unsigned char> color = info.getColor();

    short nb = convertColor(color.at(0), color.at(1), color.at(2)) + 1;
    if (info.getAscii() != ' ')
        attron(COLOR_PAIR(nb));
    else
        attron(COLOR_PAIR(nb + 1));
    for (int i = 0; i < info.getSize().second; i++) {
        for (int j = 0; j < info.getSize().first; j++)
            mvprintw(static_cast<int> (info.getPos().second) + i, static_cast<int> (info.getPos().first) + j, "%c", info.getAscii());
    }
}

void arcDisplay::ncursesDisplayModule::draw(const LineInfo &info)
{
    std::vector<unsigned char> color = info.getColor();

    short nb = convertColor(color.at(0), color.at(1), color.at(2)) + 1;
    if (info.getAscii() != ' ')
        attron(COLOR_PAIR(nb));
    else
        attron(COLOR_PAIR(nb + 1));
    for (int i = 0; i < info.getSize().second; i++) {
        for (int j = 0; j < info.getSize().first; j++)
            mvprintw(static_cast<int> (info.getPos().second) + i, static_cast<int> (info.getPos().first) + j, "%c", info.getAscii());
    }
}

const std::vector<arcDisplay::t_InfoInput> &arcDisplay::ncursesDisplayModule::getInput()
{
    int temp = getch();
    t_InfoInput input;
    inputs.clear();

    if (temp >= 'a' && temp <= 'z')
            temp -= 32;

    switch (temp) {
        case 'A':
            input.id = arcDisplay::KeyBoard::A;
            inputs.emplace_back(input);
            break;
        case 'B':
            input.id = arcDisplay::KeyBoard::B;
            inputs.emplace_back(input);
            break;
        case 'C':
            input.id = arcDisplay::KeyBoard::C;
            inputs.emplace_back(input);
            break;
        case 'D':
            input.id = arcDisplay::KeyBoard::D;
            inputs.emplace_back(input);
            break;
        case 'E':
            input.id = arcDisplay::KeyBoard::E;
            inputs.emplace_back(input);
            break;
        case 'F':
            input.id = arcDisplay::KeyBoard::F;
            inputs.emplace_back(input);
            break;
        case 'G':
            input.id = arcDisplay::KeyBoard::G;
            inputs.emplace_back(input);
            break;
        case 'H':
            input.id = arcDisplay::KeyBoard::H;
            inputs.emplace_back(input);
            break;
        case 'I':
            input.id = arcDisplay::KeyBoard::I;
            inputs.emplace_back(input);
            break;
        case 'J':
            input.id = arcDisplay::KeyBoard::J;
            inputs.emplace_back(input);
            break;
        case 'K':
            input.id = arcDisplay::KeyBoard::K;
            inputs.emplace_back(input);
            break;
        case 'L':
            input.id = arcDisplay::KeyBoard::L;
            inputs.emplace_back(input);
            break;
        case 'M':
            input.id = arcDisplay::KeyBoard::M;
            inputs.emplace_back(input);
            break;
        case 'N':
            input.id = arcDisplay::KeyBoard::N;
            inputs.emplace_back(input);
            break;
        case 'O':
            input.id = arcDisplay::KeyBoard::O;
            inputs.emplace_back(input);
            break;
        case 'P':
            input.id = arcDisplay::KeyBoard::P;
            inputs.emplace_back(input);
            break;
        case 'Q':
            input.id = arcDisplay::KeyBoard::Q;
            inputs.emplace_back(input);
            break;
        case 'R':
            input.id = arcDisplay::KeyBoard::R;
            inputs.emplace_back(input);
            break;
        case 'S':
            input.id = arcDisplay::KeyBoard::S;
            inputs.emplace_back(input);
            break;
        case 'T':
            input.id = arcDisplay::KeyBoard::T;
            inputs.emplace_back(input);
            break;
        case 'U':
            input.id = arcDisplay::KeyBoard::U;
            inputs.emplace_back(input);
            break;
        case 'V':
            input.id = arcDisplay::KeyBoard::V;
            inputs.emplace_back(input);
            break;
        case 'W':
            input.id = arcDisplay::KeyBoard::W;
            inputs.emplace_back(input);
            break;
        case 'X':
            input.id = arcDisplay::KeyBoard::X;
            inputs.emplace_back(input);
            break;
        case 'Y':
            input.id = arcDisplay::KeyBoard::Y;
            inputs.emplace_back(input);
            break;
        case 'Z':
            input.id = arcDisplay::KeyBoard::Z;
            inputs.emplace_back(input);
            break;
        case 27:
            input.id = arcDisplay::KeyBoard::ESCAPE;
            inputs.emplace_back(input);
            break;
        case 32:
            input.id = arcDisplay::KeyBoard::SPACE;
            inputs.emplace_back(input);
            break;
        case 10:
            input.id = arcDisplay::KeyBoard::ENTER;
            inputs.emplace_back(input);
            break;
        case KEY_BACKSPACE:
            input.id = arcDisplay::KeyBoard::DELETE;
            inputs.emplace_back(input);
            break;
        case KEY_LEFT:
            input.id = arcDisplay::KeyBoard::LEFT;
            inputs.emplace_back(input);
            break;
        case KEY_RIGHT:
            input.id = arcDisplay::KeyBoard::RIGHT;
            inputs.emplace_back(input);
            break;
        case KEY_UP:
            input.id = arcDisplay::KeyBoard::UP;
            inputs.emplace_back(input);
            break;
        case KEY_DOWN:
            input.id = arcDisplay::KeyBoard::DOWN;
            inputs.emplace_back(input);
            break;
        case '+':
            input.id = arcDisplay::KeyBoard::ADD;
            inputs.emplace_back(input);
            break;
        case '-':
            input.id = arcDisplay::KeyBoard::SUBSTRACT;
            inputs.emplace_back(input);
            break;
        case '0':
            input.id = arcDisplay::KeyBoard::NUM0;
            inputs.emplace_back(input);
            break;
        case '1':
            input.id = arcDisplay::KeyBoard::NUM1;
            inputs.emplace_back(input);
            break;
        case '2':
            inputs.emplace_back(input);
            input.id = arcDisplay::KeyBoard::NUM2;
            break;
        case '3':
            input.id = arcDisplay::KeyBoard::NUM3;
            inputs.emplace_back(input);
            break;
        case '4':
            input.id = arcDisplay::KeyBoard::NUM4;
            inputs.emplace_back(input);
            break;
        case '5':
            input.id = arcDisplay::KeyBoard::NUM5;
            inputs.emplace_back(input);
            break;
        case '6':
            input.id = arcDisplay::KeyBoard::NUM6;
            inputs.emplace_back(input);
            break;
        case '7':
            input.id = arcDisplay::KeyBoard::NUM7;
            inputs.emplace_back(input);
            break;
        case '8':
            input.id = arcDisplay::KeyBoard::NUM8;
            inputs.emplace_back(input);
            break;
        case '9':
            input.id = arcDisplay::KeyBoard::NUM9;
            inputs.emplace_back(input);
            break;
        case KEY_F(1):
            input.id = arcDisplay::KeyBoard::F1;
            inputs.emplace_back(input);
            break;
        case KEY_F(2):
            input.id = arcDisplay::KeyBoard::F2;
            inputs.emplace_back(input);
            break;
        case KEY_F(3):
            input.id = arcDisplay::KeyBoard::F3;
            inputs.emplace_back(input);
            break;
        case KEY_F(4):
            input.id = arcDisplay::KeyBoard::F4;
            inputs.emplace_back(input);
            break;
        case KEY_F(5):
            input.id = arcDisplay::KeyBoard::F5;
            inputs.emplace_back(input);
            break;
        case KEY_F(6):
            input.id = arcDisplay::KeyBoard::F6;
            inputs.emplace_back(input);
            break;
        case KEY_F(7):
            input.id = arcDisplay::KeyBoard::F7;
            inputs.emplace_back(input);
            break;
        case KEY_F(8):
            input.id = arcDisplay::KeyBoard::F8;
            inputs.emplace_back(input);
            break;
        case KEY_F(9):
            input.id = arcDisplay::KeyBoard::F9;
            inputs.emplace_back(input);
            break;
        case KEY_F(10):
            input.id = arcDisplay::KeyBoard::F10;
            inputs.emplace_back(input);
            break;
        case KEY_F(11):
            input.id = arcDisplay::KeyBoard::F11;
            inputs.emplace_back(input);
            break;
        case KEY_F(12):
            input.id = arcDisplay::KeyBoard::F12;
            inputs.emplace_back(input);
            break;
        default:
            break;
        }
    return (inputs);
}

short arcDisplay::ncursesDisplayModule::convertColor(unsigned char R, unsigned char G, unsigned char B)
{
    if (R > 200 && G < 100 && B < 100)
        return arcDisplay::ncursesDisplayModule::RED;
    if (R < 100 && G > 200 && B < 100)
        return arcDisplay::ncursesDisplayModule::GREEN;
    if (R < 100 && G < 100 && B > 200)
        return arcDisplay::ncursesDisplayModule::BLUE;
    if (R > 200 && G > 200 && B < 100)
        return arcDisplay::ncursesDisplayModule::YELLOW;
    if (R < 100 && G > 200 && B > 200)
        return arcDisplay::ncursesDisplayModule::CYAN;
    if (R > 200 && G < 100 && B > 200)
        return arcDisplay::ncursesDisplayModule::MAGENTA;
    return arcDisplay::ncursesDisplayModule::WHITE;
}