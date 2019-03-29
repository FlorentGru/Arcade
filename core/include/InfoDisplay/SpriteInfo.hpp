/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** SpriteInfo.hpp
*/

#ifndef OOP_ARCADE_2018_SPRITEINFO_HPP
#define OOP_ARCADE_2018_SPRITEINFO_HPP

#include <string>
#include "ADrawableInfo.hpp"

namespace arcDisplay
{
    class SpriteInfo : public ADrawableInfo
    {
        public:
            SpriteInfo();

            enum TypeInfoDisplay getType() const override;
            
            void setPosRect(int x, int y);
            const std::pair<int, int> &getPosRect() const;

            void setSizeRect(int width, int height);
            const std::pair<int, int> &getSizeRect() const;

        private:
            std::pair<int, int> _posRect;
            std::pair<int, int> _sizeRect;
    };
} // arcDisplay

#endif //OOP_ARCADE_2018_SPRITEINFO_HPP
