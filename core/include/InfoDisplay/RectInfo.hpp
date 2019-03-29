/*
** EPITECH PROJECT, 2019
** OOP_arcade_2018
** File description:
** RectInfo
*/

#ifndef RECTINFO_HPP_
#define RECTINFO_HPP_

#include "ADrawableInfo.hpp"

namespace arcDisplay
{
    class RectInfo : public ADrawableInfo
    {
        public:
            RectInfo();
            enum TypeInfoDisplay getType() const override;
    };
} //arcDisplay

#endif /* !RECTINFO_HPP_ */
