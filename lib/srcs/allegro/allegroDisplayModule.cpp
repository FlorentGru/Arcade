/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** allegroDisplayModule.cpp
*/

#include "allegroDisplayModule.hpp"

arcDisplay::allegroDisplayModule::allegroDisplayModule()
{
    al_init();
    al_init_font_addon();
    al_init_ttf_addon();
    al_init_image_addon();
    al_install_keyboard();
    this->event_queue = NULL;
}

bool arcDisplay::allegroDisplayModule::display(const std::vector<std::reference_wrapper<const IInfoDisplay>> &info)
{
    TypeInfoDisplay type;

    al_clear_to_color(al_map_rgb(0, 0, 0));
    for (auto &entity : info) {
        type = entity.get().getType();
    }
    al_flip_display();
    return (true);
}

bool arcDisplay::allegroDisplayModule::initScreen(const InitWindow &info)
{
    this->window = al_create_display(info.getWidth(), info.getHeight());
    if (!this->window)
        return (false);
    return (true);
}

bool arcDisplay::allegroDisplayModule::close()
{
    al_destroy_display(this->window);
    return (true);
}

/*#########################
########## DRAW ###########
#########################*/

void arcDisplay::allegroDisplayModule::draw(const WindowInfo &window)
{
    
}

void arcDisplay::allegroDisplayModule::draw(const SoundInfo& sound)
{

}

void arcDisplay::allegroDisplayModule::draw(const TextInfo& text)
{
    ALLEGRO_FONT *_font = al_load_ttf_font(convert_string_to_array(text.getFont()), text.getSize(), 0);

    std::vector <unsigned char>color = text.getColor();
    std::pair<float, float> pos = text.getPos();
    al_draw_text(_font, al_map_rgb(color[0], color[1], color[2]), pos.first, pos.second, 0, convert_string_to_array(text.getText()));
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

    if (rect.getTexture() != "" || al_load_bitmap(convert_string_to_array(rect.getTexture())) == NULL) {
        ALLEGRO_BITMAP *bitmap = al_load_bitmap(convert_string_to_array(rect.getTexture()));
        al_draw_bitmap_region(bitmap, 0, 0, size.first, size.second, pos.first, pos.second, 0);
    }
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
    bool get_event = al_wait_for_event_until(event_queue, &event, &timeout);
    t_InfoInput input;

    inputs.clear();
    while (get_event) {
        if (event.type == ALLEGRO_EVENT_KEY_DOWN)
            printf("OK IT'S PRESSED\n");
        else if (event.type == ALLEGRO_EVENT_KEY_UP)
            printf("Well, not now...\n");
        if (event.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
            break;
        switch (event.keyboard.keycode) {
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