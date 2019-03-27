/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** ncursesDiplayModule.cpp
*/

#include "ncursesDisplayModule.hpp"

bool arcDisplay::ncursesDisplayModule::display(const std::vector<std::reference_wrapper<IInfoDisplay>> &info)
{
    TypeInfoDisplay type;
    getmaxyx(stdscr, maxheight, maxwidth);

    for (auto &entity : info) {
        type = entity.get().getType();
        drawType(type, entity.get());
    }
    refresh();
    return (true);
}

bool arcDisplay::ncursesDisplayModule::initScreen()
{
    initscr();
    curs_set(0);
    nodelay(stdscr, false);
    return (true);
}

bool arcDisplay::ncursesDisplayModule::close()
{
    getch();
    endwin();
    return (true);
}

void arcDisplay::ncursesDisplayModule::drawType(TypeInfoDisplay type, std::reference_wrapper<const IInfoDisplay> info)
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

void arcDisplay::ncursesDisplayModule::draw(const WindowInfo &info)
{
    if (info.isClosed()) {
        endwin();
    }
}

void arcDisplay::ncursesDisplayModule::draw(const SoundInfo &info)
{
    return;
}

void arcDisplay::ncursesDisplayModule::draw(const TextInfo &info)
{
    std::vector<unsigned char> color = info.getColor();

    if(has_colors() == FALSE)
	{	endwin();
		printf("Your terminal does not support color\n");
		exit(1);
	}
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    attron(COLOR_PAIR(1));
    move(static_cast<int> (info.getPos().first), static_cast<int> (info.getPos().second));
    printw(info.getText().c_str());
    refresh();
    attroff(COLOR_PAIR(1));
}

void arcDisplay::ncursesDisplayModule::draw(const SpriteInfo &info)
{
    return;
}

void arcDisplay::ncursesDisplayModule::draw(const CircleInfo &info)
{
    for (int i = 0; i < info.getSize().first; i++) {
        for (int j = 0; j < info.getSize().second; j++)
            mvprintw(static_cast<int> (info.getPos().first) + i, static_cast<int> (info.getPos().second) + j, "%c", info.getAscii());
    }
}

void arcDisplay::ncursesDisplayModule::draw(const RectInfo &info)
{
    std::vector<unsigned char> color = info.getColor();

    for (int i = 0; i < info.getSize().first; i++) {
        for (int j = 0; j < info.getSize().second; j++)
            mvprintw(static_cast<int> (info.getPos().first) + i, static_cast<int> (info.getPos().second) + j, "%c", info.getAscii());
    }
}

void arcDisplay::ncursesDisplayModule::draw(const LineInfo &info)
{
    return;
}

const std::vector<arcDisplay::t_InfoInput> &arcDisplay::ncursesDisplayModule::getInput()
{
    int temp = getch();
    t_InfoInput input;
    inputs.clear;

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
                case 127:
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
                default:
                    break;
            }
    return (inputs);
}