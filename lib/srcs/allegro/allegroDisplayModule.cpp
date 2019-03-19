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
}

bool arcDisplay::allegroDisplayModule::display(const std::vector<std::reference_wrapper<IInfoDisplay>> &info)
{
    TypeInfoDisplay type;

    al_clear_to_color(al_map_rgb(0, 0, 0));
    for (auto &entity : info) {
        type = entity.get().getType();
    }
    al_flip_display();
    return (true);
}

bool arcDisplay::allegroDisplayModule::initScreen(InitWindow &info)
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

void draw(const WindowInfo &)
{

}

void draw(const SoundInfo&)
{

}

void draw(const TextInfo&)
{

}

void draw(const SpriteInfo&)
{

}

void draw(const CircleInfo&)
{

}

void draw(const RectInfo&)
{

}

void draw(const LineInfo&)
{
    
}