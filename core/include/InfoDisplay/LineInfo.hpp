/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** LineInfo.hpp
*/

#ifndef LINEINFO_HPP_
#define LINEINFO_HPP_

#include "ADrawableInfo.hpp"

namespace arcDisplay
{
    class LineInfo : public ADrawableInfo
    {
        private:
            std::pair<float, float> _pos2;

        public:
            LineInfo();

            const std::pair<float, float> &getPos2() const;
            void setPos2(float x, float y);
            enum TypeInfoDisplay getType() const override;
    };
}

#endif // !LINEINFO_HPP_