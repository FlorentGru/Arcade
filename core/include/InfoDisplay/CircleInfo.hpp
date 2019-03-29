/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** CircleInfo
*/

#ifndef CIRCLEINFO_HPP_
#define CIRCLEINFO_HPP_

#include "ADrawableInfo.hpp"

namespace arcDisplay
{
    class CircleInfo : public ADrawableInfo
    {
        public:
            CircleInfo();
            enum TypeInfoDisplay getType() const override;
    };
} //arcDisplay

#endif /* !CIRCLEINFO_HPP_ */
