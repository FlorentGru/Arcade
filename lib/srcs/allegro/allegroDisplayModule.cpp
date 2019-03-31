/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** allegroDisplayModule.cpp
*/

#include "allegroDisplayModule.hpp"
#include <iostream>
#include <string>

extern "C" {
    arcDisplay::allegroDisplayModule *entryPoint()
    {
        return (new arcDisplay::allegroDisplayModule());
    }
}

arcDisplay::allegroDisplayModule::allegroDisplayModule()
{
    this->window = NULL;
    this->_font = NULL;
    this->timer = NULL;
    this->event_queue = NULL;
    this->sample = NULL;
}

bool arcDisplay::allegroDisplayModule::initScreen(const InitWindow &info)
{
    if (!al_init() || !al_init_font_addon() || !al_init_ttf_addon() || !al_init_image_addon() || !al_install_keyboard() || !al_install_audio() || !al_init_acodec_addon() || !al_reserve_samples(1))
        return (false);
    this->event_queue = al_create_event_queue();
    this->_font = NULL;
    this->timer = al_create_timer(1.0 / info.getFrame());
    this->window = al_create_display(info.getWidth() * CHAR_SIZE, info.getHeight() * CHAR_SIZE);
    al_register_event_source(event_queue, al_get_display_event_source(this->window));
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_start_timer(timer);
    if (!this->window || !this->timer || !this->event_queue)
        return (false);
    return (true);
}

bool arcDisplay::allegroDisplayModule::display(const std::vector<std::reference_wrapper<const IInfoDisplay>> &info)
{
    TypeInfoDisplay type;

    if (!this->window)
        return (false);
    al_clear_to_color(al_map_rgb(0, 0, 0));
    for (auto &entity : info) {
        type = entity.get().getType();
        if (!this->window)
            break;
        drawType(type, entity.get());
    }
    if (this->window)
        al_flip_display();
    else
        return (false);
    return (true);
}

bool arcDisplay::allegroDisplayModule::close()
{
    if (this->window != NULL) {
        al_destroy_display(this->window);
        this->window = NULL;
        al_destroy_timer(timer);
        timer = NULL;
        al_destroy_event_queue(event_queue);
        event_queue = NULL;
        return (true);
    }
    return (false);
}

/*#########################
########## DRAW ###########
#########################*/

void arcDisplay::allegroDisplayModule::drawType(TypeInfoDisplay type, std::reference_wrapper<const IInfoDisplay> info)
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

void arcDisplay::allegroDisplayModule::draw(const WindowInfo &info)
{
    if (info.isClosed())
        close();
}

void arcDisplay::allegroDisplayModule::draw(const SoundInfo& sound)
{
    if (this->sample)
        al_destroy_sample(sample);
    sample = al_load_sample(sound.getSound().c_str());
    if (sound.isLoop() == true)
        al_play_sample(sample, sound.getVolume(), 0.0, 1.0, ALLEGRO_PLAYMODE_LOOP, NULL);
    else
        al_play_sample(sample, sound.getVolume(), 0.0, 1.0, ALLEGRO_PLAYMODE_ONCE, NULL);
    
}

void arcDisplay::allegroDisplayModule::draw(const TextInfo& text)
{
    if (_font)
        al_destroy_font(_font);
    this->_font = al_load_font(text.getFont().c_str(), text.getSize(), 0);
    if (this->_font == NULL)
        this->_font = al_create_builtin_font();
    std::vector <unsigned char>color = text.getColor();
    std::pair<float, float> pos = text.getPos();
    al_draw_text(_font, al_map_rgb(color[0], color[1], color[2]), pos.first * CHAR_SIZE, pos.second * CHAR_SIZE, 0, text.getText().c_str());
}

void arcDisplay::allegroDisplayModule::draw(const SpriteInfo& sprite)
{
    std::pair<float, float> pos = sprite.getPos();
    std::pair<float, float> size = sprite.getSize();
    std::vector <unsigned char>color = sprite.getColor();

    if (sprite.getTexture() != "" || al_load_bitmap(sprite.getTexture().c_str()) != NULL) {
        ALLEGRO_BITMAP *bitmap = al_load_bitmap(sprite.getTexture().c_str());
        std::pair<int, int> posRect = sprite.getPosRect();
        std::pair<int, int> sizeRect = sprite.getSizeRect();
        al_draw_bitmap_region(bitmap, posRect.first * CHAR_SIZE, posRect.second * CHAR_SIZE, sizeRect.first * CHAR_SIZE, sizeRect.second * CHAR_SIZE, pos.first * CHAR_SIZE, pos.second * CHAR_SIZE, 0);
        return;
    }
    al_draw_filled_rectangle(pos.first * CHAR_SIZE, pos.second * CHAR_SIZE, (pos.first + size.first) * CHAR_SIZE,\
    (pos.second + size.second) * CHAR_SIZE, al_map_rgb(color[0], color[1], color[2]));
}

void arcDisplay::allegroDisplayModule::draw(const CircleInfo& circle)
{
    std::pair<float, float> pos = circle.getPos();
    std::pair<float, float> size = circle.getSize();
    std::vector<unsigned char> color = circle.getColor();

    al_draw_filled_circle(pos.first * CHAR_SIZE + (size.first * CHAR_SIZE / 2), pos.second * CHAR_SIZE + (size.first * CHAR_SIZE / 2), size.first * CHAR_SIZE / 2, al_map_rgb(color[0], color[1], color[2]));
}

void arcDisplay::allegroDisplayModule::draw(const RectInfo& rect)
{
    std::pair<float, float> pos = rect.getPos();
    std::pair<float, float> size = rect.getSize();
    std::vector <unsigned char>color = rect.getColor();

    if (rect.getTexture() != "" && al_load_bitmap(rect.getTexture().c_str()) != NULL) {
        ALLEGRO_BITMAP *bitmap = al_load_bitmap(rect.getTexture().c_str());
        if (bitmap != NULL) {
            al_draw_bitmap_region(bitmap, 0, 0, al_get_bitmap_width(bitmap), al_get_bitmap_height(bitmap), 0, 0 , 0);
            return;
        }
    }
    al_draw_filled_rectangle(pos.first * CHAR_SIZE, pos.second * CHAR_SIZE, (pos.first + size.first) * CHAR_SIZE,\
    (pos.second + size.second) * CHAR_SIZE, al_map_rgb(color[0], color[1], color[2]));
}

void arcDisplay::allegroDisplayModule::draw(const LineInfo& line)
{
    std::pair<float, float> posx = line.getPos();
    std::pair<float, float> posy = line.getPos2();
    std::vector<unsigned char> color = line.getColor();

    al_draw_line(posx.first * CHAR_SIZE, posx.second * CHAR_SIZE, posy.first * CHAR_SIZE,\
    posy.second  * CHAR_SIZE, al_map_rgb(color[0], color[1], color[2]), 1);
}

const std::vector<arcDisplay::t_InfoInput> &arcDisplay::allegroDisplayModule::getInput()
{
    ALLEGRO_EVENT event;
    t_InfoInput input;

    inputs.clear();
    for (;check_event(event);) {
        if (event.type == ALLEGRO_EVENT_KEY_DOWN)
            input.isPressed = true;
        else if (event.type == ALLEGRO_EVENT_KEY_UP)
            input.isPressed = false;
        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            close();
            break;
        }
        if (event.type == ALLEGRO_EVENT_KEY_CHAR) {
            if (event.keyboard.keycode  == ALLEGRO_KEY_A) {
                input.id = arcDisplay::KeyBoard::A;
                inputs.push_back(input);
                continue;}
            if (event.keyboard.keycode  == ALLEGRO_KEY_B) {
                input.id = arcDisplay::KeyBoard::B;
                inputs.push_back(input);
                continue;}
            if (event.keyboard.keycode  == ALLEGRO_KEY_C) {
                input.id = arcDisplay::KeyBoard::C;
                inputs.push_back(input);
                continue;}
            if (event.keyboard.keycode  == ALLEGRO_KEY_D) {
                input.id = arcDisplay::KeyBoard::D;
                inputs.push_back(input);
                continue;}
            if (event.keyboard.keycode  == ALLEGRO_KEY_E) {
                input.id = arcDisplay::KeyBoard::E;
                inputs.push_back(input);
                continue;}
            if (event.keyboard.keycode  == ALLEGRO_KEY_F) {
                input.id = arcDisplay::KeyBoard::F;
                inputs.push_back(input);
                continue;}
            if (event.keyboard.keycode  == ALLEGRO_KEY_G) {
                input.id = arcDisplay::KeyBoard::G;
                inputs.push_back(input);
                continue;}
            if (event.keyboard.keycode  == ALLEGRO_KEY_H) {
                input.id = arcDisplay::KeyBoard::H;
                inputs.push_back(input);
                continue;}
            if (event.keyboard.keycode  == ALLEGRO_KEY_I) {
                input.id = arcDisplay::KeyBoard::I;
                inputs.push_back(input);
                continue;}
            if (event.keyboard.keycode  == ALLEGRO_KEY_J) {
                input.id = arcDisplay::KeyBoard::J;
                inputs.push_back(input);
                continue;}
            if (event.keyboard.keycode  == ALLEGRO_KEY_K) {
                input.id = arcDisplay::KeyBoard::K;
                inputs.push_back(input);
                continue;}
            if (event.keyboard.keycode  == ALLEGRO_KEY_L) {
                input.id = arcDisplay::KeyBoard::L;
                inputs.push_back(input);
                continue;}
            if (event.keyboard.keycode  == ALLEGRO_KEY_M) {
                input.id = arcDisplay::KeyBoard::M;
                inputs.push_back(input);
                continue;}
            if (event.keyboard.keycode  == ALLEGRO_KEY_N) {
                input.id = arcDisplay::KeyBoard::N;
                inputs.push_back(input);
                continue;}
            if (event.keyboard.keycode  == ALLEGRO_KEY_O) {
                input.id = arcDisplay::KeyBoard::O;
                inputs.push_back(input);
                continue;}
            if (event.keyboard.keycode  == ALLEGRO_KEY_P) {
                input.id = arcDisplay::KeyBoard::P;
                inputs.push_back(input);
                continue;}
            if (event.keyboard.keycode  == ALLEGRO_KEY_Q) {
                input.id = arcDisplay::KeyBoard::Q;
                inputs.push_back(input);
                continue;}
            if (event.keyboard.keycode  == ALLEGRO_KEY_R) {
                input.id = arcDisplay::KeyBoard::R;
                inputs.push_back(input);
                continue;}
            if (event.keyboard.keycode  == ALLEGRO_KEY_S) {
                input.id = arcDisplay::KeyBoard::S;
                inputs.push_back(input);
                continue;}
            if (event.keyboard.keycode  == ALLEGRO_KEY_T) {
                input.id = arcDisplay::KeyBoard::T;
                inputs.push_back(input);
                continue;}
            if (event.keyboard.keycode  == ALLEGRO_KEY_U) {
                input.id = arcDisplay::KeyBoard::U;
                inputs.push_back(input);
                continue;}
            if (event.keyboard.keycode  == ALLEGRO_KEY_V) {
                input.id = arcDisplay::KeyBoard::V;
                inputs.push_back(input);
                continue;}
            if (event.keyboard.keycode  == ALLEGRO_KEY_W) {
                input.id = arcDisplay::KeyBoard::W;
                inputs.push_back(input);
                continue;}
            if (event.keyboard.keycode  == ALLEGRO_KEY_X) {
                input.id = arcDisplay::KeyBoard::X;
                inputs.push_back(input);
                continue;}
            if (event.keyboard.keycode  == ALLEGRO_KEY_Y) {
                input.id = arcDisplay::KeyBoard::Y;
                inputs.push_back(input);
                continue;}
            if (event.keyboard.keycode  == ALLEGRO_KEY_Z) {
                input.id = arcDisplay::KeyBoard::Z;
                inputs.push_back(input);
                continue;}
            if (event.keyboard.keycode  == ALLEGRO_KEY_ESCAPE) {
                input.id = arcDisplay::KeyBoard::ESCAPE;
                inputs.push_back(input);
                continue;}
            if (event.keyboard.keycode  == ALLEGRO_KEY_SPACE) {
                input.id = arcDisplay::KeyBoard::SPACE;
                inputs.push_back(input);
                continue;}
            if (event.keyboard.keycode  == ALLEGRO_KEY_ENTER) {
                input.id = arcDisplay::KeyBoard::ENTER;
                inputs.push_back(input);
                continue;}
            if (event.keyboard.keycode  == ALLEGRO_KEY_LCTRL) {
                input.id = arcDisplay::KeyBoard::LCONTROL;
                inputs.push_back(input);
                continue;}
            if (event.keyboard.keycode  == ALLEGRO_KEY_BACKSPACE) {
                input.id = arcDisplay::KeyBoard::DELETE;
                inputs.push_back(input);
                continue;}
            if (event.keyboard.keycode  == ALLEGRO_KEY_LSHIFT) {
                input.id = arcDisplay::KeyBoard::LSHIFT;
                inputs.push_back(input);
                continue;}
            if (event.keyboard.keycode  == ALLEGRO_KEY_ALT) {
                input.id = arcDisplay::KeyBoard::LALT;
                inputs.push_back(input);
                continue;}
            if (event.keyboard.keycode  == ALLEGRO_KEY_LEFT) {
                input.id = arcDisplay::KeyBoard::LEFT;
                inputs.push_back(input);
                continue;}
            if (event.keyboard.keycode  == ALLEGRO_KEY_RIGHT) {
                input.id = arcDisplay::KeyBoard::RIGHT;
                inputs.push_back(input);
                continue;}
            if (event.keyboard.keycode  == ALLEGRO_KEY_UP) {
                input.id = arcDisplay::KeyBoard::UP;
                inputs.push_back(input);
                continue;}
            if (event.keyboard.keycode  == ALLEGRO_KEY_DOWN) {
                input.id = arcDisplay::KeyBoard::DOWN;
                inputs.push_back(input);
                continue;}
            if (event.keyboard.keycode  == ALLEGRO_KEY_PAD_PLUS) {
                input.id = arcDisplay::KeyBoard::ADD;
                inputs.push_back(input);
                continue;}
            if (event.keyboard.keycode  == ALLEGRO_KEY_PAD_MINUS) {
                input.id = arcDisplay::KeyBoard::SUBSTRACT;
                inputs.push_back(input);
                continue;}
            if (event.keyboard.keycode  == ALLEGRO_KEY_0) {
                input.id = arcDisplay::KeyBoard::NUM0;
                inputs.push_back(input);
                continue;}
            if (event.keyboard.keycode  == ALLEGRO_KEY_1) {
                input.id = arcDisplay::KeyBoard::NUM1;
                inputs.push_back(input);
                continue;}
            if (event.keyboard.keycode  == ALLEGRO_KEY_2) {
                inputs.push_back(input);
                input.id = arcDisplay::KeyBoard::NUM2;
                continue;}
            if (event.keyboard.keycode  == ALLEGRO_KEY_3) {
                input.id = arcDisplay::KeyBoard::NUM3;
                inputs.push_back(input);
                continue;}
            if (event.keyboard.keycode  == ALLEGRO_KEY_4) {
                input.id = arcDisplay::KeyBoard::NUM4;
                inputs.push_back(input);
                continue;}
            if (event.keyboard.keycode  == ALLEGRO_KEY_5) {
                input.id = arcDisplay::KeyBoard::NUM5;
                inputs.push_back(input);
                continue;}
            if (event.keyboard.keycode  == ALLEGRO_KEY_6) {
                input.id = arcDisplay::KeyBoard::NUM6;
                inputs.push_back(input);
                continue;}
            if (event.keyboard.keycode  == ALLEGRO_KEY_7) {
                input.id = arcDisplay::KeyBoard::NUM7;
                inputs.push_back(input);
                continue;}
            if (event.keyboard.keycode  == ALLEGRO_KEY_8) {
                input.id = arcDisplay::KeyBoard::NUM8;
                inputs.push_back(input);
                continue;}
            if (event.keyboard.keycode  == ALLEGRO_KEY_9) {
                input.id = arcDisplay::KeyBoard::NUM9;
                inputs.push_back(input);
                continue;}
            if (event.keyboard.keycode  == ALLEGRO_KEY_F1) {
                input.id = arcDisplay::KeyBoard::F1;
                inputs.push_back(input);
                continue;}
            if (event.keyboard.keycode  == ALLEGRO_KEY_F2) {
                input.id = arcDisplay::KeyBoard::F2;
                inputs.push_back(input);
                continue;}
            if (event.keyboard.keycode  == ALLEGRO_KEY_F3) {
                input.id = arcDisplay::KeyBoard::F3;
                inputs.push_back(input);
                continue;}
            if (event.keyboard.keycode  == ALLEGRO_KEY_F4) {
                input.id = arcDisplay::KeyBoard::F4;
                inputs.push_back(input);
                continue;}
            if (event.keyboard.keycode  == ALLEGRO_KEY_F5) {
                input.id = arcDisplay::KeyBoard::F5;
                inputs.push_back(input);
                continue;}
            if (event.keyboard.keycode  == ALLEGRO_KEY_F6) {
                input.id = arcDisplay::KeyBoard::F6;
                inputs.push_back(input);
                continue;}
            if (event.keyboard.keycode  == ALLEGRO_KEY_F7) {
                input.id = arcDisplay::KeyBoard::F7;
                inputs.push_back(input);
                continue;}
            if (event.keyboard.keycode  == ALLEGRO_KEY_F8) {
                input.id = arcDisplay::KeyBoard::F8;
                inputs.push_back(input);
                continue;}
            if (event.keyboard.keycode  == ALLEGRO_KEY_F9) {
                input.id = arcDisplay::KeyBoard::F9;
                inputs.push_back(input);
                continue;}
            if (event.keyboard.keycode  == ALLEGRO_KEY_F10) {
                input.id = arcDisplay::KeyBoard::F10;
                inputs.push_back(input);
                continue;}
            if (event.keyboard.keycode  == ALLEGRO_KEY_F11) {
                input.id = arcDisplay::KeyBoard::F11;
                inputs.push_back(input);
                continue;}
            if (event.keyboard.keycode  == ALLEGRO_KEY_F12) {
                input.id = arcDisplay::KeyBoard::F12;
                inputs.push_back(input);
                continue;}
        }
    }
    return (inputs);
}

bool arcDisplay::allegroDisplayModule::check_event(ALLEGRO_EVENT &event)
{
    static bool wait = false;

    al_wait_for_event(this->event_queue, &event);
    if (event.type == ALLEGRO_EVENT_TIMER)
        wait = true;
    if (wait == true && al_is_event_queue_empty(event_queue)) {
        wait = false;
        return (false);
    }
    return (true);
}