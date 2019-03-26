/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** allegroDisplayModule.cpp
*/

#include "allegroDisplayModule.hpp"
#include <string>
#include <iostream>

extern "C" {
    arcDisplay::allegroDisplayModule *create()
    {
        return (new arcDisplay::allegroDisplayModule());
    }
}

arcDisplay::allegroDisplayModule::allegroDisplayModule()
{
}

bool arcDisplay::allegroDisplayModule::initScreen(const InitWindow &info)
{
    al_init();
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_image_addon();
    al_install_keyboard();
    this->event_queue = NULL;
    event_queue = al_create_event_queue();
    al_init_timeout(&timeout, 0.06);
    this->window = al_create_display(info.getWidth(), info.getHeight());
    al_register_event_source(event_queue, al_get_display_event_source(this->window));
// //	al_register_event_source(event_queue, al_get_timer_event_source(timer));
 	al_register_event_source(event_queue, al_get_keyboard_event_source());
    if (!this->window)
        return (false);
    return (true);
}

bool arcDisplay::allegroDisplayModule::display(const std::vector<std::reference_wrapper<const IInfoDisplay>> &info)
{
    TypeInfoDisplay type;

    printf("Display1\n");
    if (this->window == NULL) {
        return (false);
    }
    printf("Display2\n");
    al_clear_to_color(al_map_rgb(0, 0, 0));
    for (auto &entity : info) {
        printf("Displayed\n");
        type = entity.get().getType();
        printf("Displayed1\n");
        drawType(type, entity.get());
        printf("Displayed2\n");
    }
    printf("Display3\n");
    if (this->window != NULL)
        al_flip_display();
    else
        return (false);
    return (true);
}

bool arcDisplay::allegroDisplayModule::close()
{
    if (this->window != NULL) {
        al_destroy_display(this->window);
        return (true);
    }
    return (false);
}

/*#########################
########## DRAW ###########
#########################*/

void arcDisplay::allegroDisplayModule::drawType(TypeInfoDisplay type, std::reference_wrapper<const IInfoDisplay> info)
{
    printf("draw\n");
    switch (type) {
        case WINDOW:
            draw(dynamic_cast<const WindowInfo &>(info.get()));
            break;
        case SOUND:
            draw(dynamic_cast<const SoundInfo &>(info.get()));
            break;
        case TEXT:
            draw(dynamic_cast<const TextInfo &>(info.get()));
            printf("TEXT\n");
            break;
        case SPRITE:
            draw(dynamic_cast<const SpriteInfo &>(info.get()));
            break;
        case CIRCLE:
            draw(dynamic_cast<const CircleInfo &>(info.get()));
            break;
        case RECT:
            printf("RECT\n");
            draw(dynamic_cast<const RectInfo &>(info.get()));
            break;
        case LINE:
            draw(dynamic_cast<const LineInfo &>(info.get()));
            break;
        default:
            break;
    }
}

void arcDisplay::allegroDisplayModule::draw(const WindowInfo &info)
{
    if (info.isClosed())
        al_destroy_display(this->window);
}

void arcDisplay::allegroDisplayModule::draw(const SoundInfo& sound)
{

}

void arcDisplay::allegroDisplayModule::draw(const TextInfo& text)
{
    printf("text1\n");
    ALLEGRO_FONT *_font = al_load_ttf_font(convert_string_to_array(text.getFont()), text.getSize(), 0);

    printf("text2\n");
    std::vector <unsigned char>color = text.getColor();
    std::pair<float, float> pos = text.getPos();
    printf("text3\n");
    std::cout << text.getText() << std::endl;
    std::cout << "font : " << _font << std::endl;
    std::cout << "color 1, 2, 3" << color[0] << " " << color[1] << " " << color[2] << std::endl;
    std::cout << "pos 1, 2" << pos.first << " " << pos.second << std::endl;
    al_draw_text(_font, al_map_rgb(color[0], color[1], color[2]), pos.first, pos.second, 0, text.getText().c_str());
    printf("text4\n");
}

void arcDisplay::allegroDisplayModule::draw(const SpriteInfo& sprite)
{
    std::pair<float, float> pos = sprite.getPos();
    std::pair<float, float> size = sprite.getSize();
    std::vector <unsigned char>color = sprite.getColor();

    if (sprite.getTexture() != "" || al_load_bitmap(convert_string_to_array(sprite.getTexture())) == NULL) {
        ALLEGRO_BITMAP *bitmap = al_load_bitmap(convert_string_to_array(sprite.getTexture()));
        std::pair<int, int> posRect = sprite.getPosRect();
        std::pair<int, int> sizeRect = sprite.getSizeRect();
        al_draw_bitmap_region(bitmap, posRect.first, posRect.second, sizeRect.first, sizeRect.second, pos.first, pos.second, 0);
    }
    al_draw_filled_rectangle(pos.first, pos.second, pos.first + size.first,\
    pos.second + size.second, al_map_rgb(color[0], color[1], color[2]));
}

void arcDisplay::allegroDisplayModule::draw(const CircleInfo& circle)
{
    std::pair<float, float> pos = circle.getPos();
    std::pair<float, float> size = circle.getSize();
    std::vector<unsigned char> color = circle.getColor();

    al_draw_circle(pos.first, pos.second, size.first, al_map_rgb(color[0], color[1], color[2]), 1);
}

void arcDisplay::allegroDisplayModule::draw(const RectInfo& rect)
{
    std::pair<float, float> pos = rect.getPos();
    std::pair<float, float> size = rect.getSize();
    std::vector <unsigned char>color = rect.getColor();

    printf("inside rect\n");
    std::cout << rect.getTexture() << std::endl;
    if (rect.getTexture() != "" && al_load_bitmap(convert_string_to_array(rect.getTexture())) == NULL) {
        ALLEGRO_BITMAP *bitmap = al_load_bitmap(convert_string_to_array(rect.getTexture()));
        printf("inside rect2\n");
        al_draw_bitmap_region(bitmap, 0, 0, size.first, size.second, pos.first, pos.second, 0);
        printf("inside rect3\n");
    }
    printf("inside rect3\n");
    al_draw_filled_rectangle(pos.first, pos.second, pos.first + size.first,\
    pos.second + size.second, al_map_rgb(color[0], color[1], color[2]));
}

void arcDisplay::allegroDisplayModule::draw(const LineInfo& line)
{
    std::pair<float, float> posx = line.getPos();
    std::pair<float, float> posy = line.getPosition2();
    std::vector<unsigned char> color = line.getColor();

    al_draw_line(posx.first, posx.second, posy.first,\
    posy.second, al_map_rgb(color[0], color[1], color[2]), 1);
}

const std::vector<arcDisplay::t_InfoInput> &arcDisplay::allegroDisplayModule::getInput()
{
    printf("LOL1\n");
    al_wait_for_event_until(this->event_queue, this->event, &this->timeout);
    printf("LOL1.5\n");
    t_InfoInput input;

    printf("LOL2\n");
    inputs.clear();
    while (al_is_event_queue_empty(this->event_queue) == false) {
        al_wait_for_event(this->event_queue, this->event);
        if (event->type == ALLEGRO_EVENT_KEY_DOWN)
            input.isPressed = true;
        else if (event->type == ALLEGRO_EVENT_KEY_UP)
            input.isPressed = false;
        if (event->type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            break;
        printf("LOL3\n");
        switch (event->keyboard.keycode) {
        case ALLEGRO_KEY_A:
          	input.id = arcDisplay::KeyBoard::A;
          	inputs.emplace_back(input);
            break;
        case ALLEGRO_KEY_B:
          	input.id = arcDisplay::KeyBoard::B;
          	inputs.emplace_back(input);
            break;
        case ALLEGRO_KEY_C:
          	input.id = arcDisplay::KeyBoard::C;
          	inputs.emplace_back(input);
            break;
        case ALLEGRO_KEY_D:
          	input.id = arcDisplay::KeyBoard::D;
          	inputs.emplace_back(input);
            break;
        case ALLEGRO_KEY_E:
          	input.id = arcDisplay::KeyBoard::E;
          	inputs.emplace_back(input);
            break;
        case ALLEGRO_KEY_F:
          	input.id = arcDisplay::KeyBoard::F;
          	inputs.emplace_back(input);
            break;
        case ALLEGRO_KEY_G:
          	input.id = arcDisplay::KeyBoard::G;
          	inputs.emplace_back(input);
            break;
        case ALLEGRO_KEY_H:
          	input.id = arcDisplay::KeyBoard::H;
          	inputs.emplace_back(input);
            break;
        case ALLEGRO_KEY_I:
          	input.id = arcDisplay::KeyBoard::I;
          	inputs.emplace_back(input);
            break;
        case ALLEGRO_KEY_J:
          	input.id = arcDisplay::KeyBoard::J;
          	inputs.emplace_back(input);
            break;
        case ALLEGRO_KEY_K:
          	input.id = arcDisplay::KeyBoard::K;
          	inputs.emplace_back(input);
            break;
        case ALLEGRO_KEY_L:
          	input.id = arcDisplay::KeyBoard::L;
          	inputs.emplace_back(input);
            break;
        case ALLEGRO_KEY_M:
          	input.id = arcDisplay::KeyBoard::M;
          	inputs.emplace_back(input);
            break;
        case ALLEGRO_KEY_N:
          	input.id = arcDisplay::KeyBoard::N;
          	inputs.emplace_back(input);
            break;
        case ALLEGRO_KEY_O:
          	input.id = arcDisplay::KeyBoard::O;
          	inputs.emplace_back(input);
            break;
        case ALLEGRO_KEY_P:
          	input.id = arcDisplay::KeyBoard::P;
          	inputs.emplace_back(input);
            break;
        case ALLEGRO_KEY_Q:
          	input.id = arcDisplay::KeyBoard::Q;
          	inputs.emplace_back(input);
            break;
        case ALLEGRO_KEY_R:
          	input.id = arcDisplay::KeyBoard::R;
          	inputs.emplace_back(input);
            break;
        case ALLEGRO_KEY_S:
          	input.id = arcDisplay::KeyBoard::S;
          	inputs.emplace_back(input);
            break;
        case ALLEGRO_KEY_T:
          	input.id = arcDisplay::KeyBoard::T;
          	inputs.emplace_back(input);
            break;
        case ALLEGRO_KEY_U:
          	input.id = arcDisplay::KeyBoard::U;
          	inputs.emplace_back(input);
            break;
        case ALLEGRO_KEY_V:
          	input.id = arcDisplay::KeyBoard::V;
          	inputs.emplace_back(input);
            break;
        case ALLEGRO_KEY_W:
          	input.id = arcDisplay::KeyBoard::W;
          	inputs.emplace_back(input);
            break;
        case ALLEGRO_KEY_X:
          	input.id = arcDisplay::KeyBoard::X;
          	inputs.emplace_back(input);
            break;
        case ALLEGRO_KEY_Y:
          	input.id = arcDisplay::KeyBoard::Y;
          	inputs.emplace_back(input);
            break;
        case ALLEGRO_KEY_Z:
          	input.id = arcDisplay::KeyBoard::Z;
          	inputs.emplace_back(input);
            break;
        case ALLEGRO_KEY_ESCAPE:
          	input.id = arcDisplay::KeyBoard::ESCAPE;
          	inputs.emplace_back(input);
            break;
        case ALLEGRO_KEY_SPACE:
          	input.id = arcDisplay::KeyBoard::SPACE;
          	inputs.emplace_back(input);
            break;
        case ALLEGRO_KEY_BACKSPACE:
          	input.id = arcDisplay::KeyBoard::ENTER;
          	inputs.emplace_back(input);
            break;
        case ALLEGRO_KEY_LCTRL:
          	input.id = arcDisplay::KeyBoard::LCONTROL;
          	inputs.emplace_back(input);
            break;
        case ALLEGRO_KEY_DELETE:
          	input.id = arcDisplay::KeyBoard::DELETE;
          	inputs.emplace_back(input);
            break;
        case ALLEGRO_KEY_LSHIFT:
          	input.id = arcDisplay::KeyBoard::LSHIFT;
          	inputs.emplace_back(input);
            break;
        case ALLEGRO_KEY_ALT:
          	input.id = arcDisplay::KeyBoard::LALT;
          	inputs.emplace_back(input);
            break;
        case ALLEGRO_KEY_LEFT:
          	input.id = arcDisplay::KeyBoard::LEFT;
          	inputs.emplace_back(input);
            break;
        case ALLEGRO_KEY_RIGHT:
          	input.id = arcDisplay::KeyBoard::RIGHT;
          	inputs.emplace_back(input);
            break;
        case ALLEGRO_KEY_UP:
          	input.id = arcDisplay::KeyBoard::UP;
          	inputs.emplace_back(input);
            break;
        case ALLEGRO_KEY_DOWN:
          	input.id = arcDisplay::KeyBoard::DOWN;
          	inputs.emplace_back(input);
            break;
        case ALLEGRO_KEY_PAD_PLUS:
          	input.id = arcDisplay::KeyBoard::ADD;
          	inputs.emplace_back(input);
            break;
        case ALLEGRO_KEY_PAD_MINUS:
          	input.id = arcDisplay::KeyBoard::SUBSTRACT;
          	inputs.emplace_back(input);
            break;
        case ALLEGRO_KEY_0:
          	input.id = arcDisplay::KeyBoard::NUM0;
          	inputs.emplace_back(input);
            break;
        case ALLEGRO_KEY_1:
          	input.id = arcDisplay::KeyBoard::NUM1;
          	inputs.emplace_back(input);
            break;
        case ALLEGRO_KEY_2:
          	inputs.emplace_back(input);
          	input.id = arcDisplay::KeyBoard::NUM2;
            break;
        case ALLEGRO_KEY_3:
          	input.id = arcDisplay::KeyBoard::NUM3;
          	inputs.emplace_back(input);
            break;
        case ALLEGRO_KEY_4:
          	input.id = arcDisplay::KeyBoard::NUM4;
          	inputs.emplace_back(input);
            break;
        case ALLEGRO_KEY_5:
          	input.id = arcDisplay::KeyBoard::NUM5;
          	inputs.emplace_back(input);
            break;
        case ALLEGRO_KEY_6:
          	input.id = arcDisplay::KeyBoard::NUM6;
          	inputs.emplace_back(input);
            break;
        case ALLEGRO_KEY_7:
          	input.id = arcDisplay::KeyBoard::NUM7;
          	inputs.emplace_back(input);
            break;
        case ALLEGRO_KEY_8:
          	input.id = arcDisplay::KeyBoard::NUM8;
          	inputs.emplace_back(input);
            break;
        case ALLEGRO_KEY_9:
          	input.id = arcDisplay::KeyBoard::NUM9;
          	inputs.emplace_back(input);
            break;
        case ALLEGRO_KEY_F1:
          	input.id = arcDisplay::KeyBoard::F1;
          	inputs.emplace_back(input);
            break;
        case ALLEGRO_KEY_F2:
          	input.id = arcDisplay::KeyBoard::F2;
          	inputs.emplace_back(input);
            break;
        case ALLEGRO_KEY_F3:
          	input.id = arcDisplay::KeyBoard::F3;
          	inputs.emplace_back(input);
            break;
        case ALLEGRO_KEY_F4:
          	input.id = arcDisplay::KeyBoard::F4;
          	inputs.emplace_back(input);
            break;
        case ALLEGRO_KEY_F5:
          	input.id = arcDisplay::KeyBoard::F5;
          	inputs.emplace_back(input);
            break;
        case ALLEGRO_KEY_F6:
          	input.id = arcDisplay::KeyBoard::F6;
          	inputs.emplace_back(input);
            break;
        case ALLEGRO_KEY_F7:
          	input.id = arcDisplay::KeyBoard::F7;
          	inputs.emplace_back(input);
            break;
        case ALLEGRO_KEY_F8:
          	input.id = arcDisplay::KeyBoard::F8;
          	inputs.emplace_back(input);
            break;
        case ALLEGRO_KEY_F9:
          	input.id = arcDisplay::KeyBoard::F9;
          	inputs.emplace_back(input);
            break;
        case ALLEGRO_KEY_F10:
          	input.id = arcDisplay::KeyBoard::F10;
          	inputs.emplace_back(input);
            break;
        case ALLEGRO_KEY_F11:
          	input.id = arcDisplay::KeyBoard::F11;
          	inputs.emplace_back(input);
            break;
        case ALLEGRO_KEY_F12:
          	input.id = arcDisplay::KeyBoard::F12;
          	inputs.emplace_back(input);
            break;
        default:
            break;
        }
    }
    return (inputs);
}

char *convert_string_to_array(std::string str)
{
    char *convstr = new char[str.length() + 1];
    strcpy(convstr, str.c_str());
    return (convstr);
}