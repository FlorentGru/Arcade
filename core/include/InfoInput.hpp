/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** InfoInput.hpp
*/

#ifndef INFOINPUT_HPP
#define INFOINPUT_HPP

namespace arcDisplay
{
    namespace KeyBoard
    {
        enum KeyID
        {
            UNKNOWN = -1,
            A, B, C, D,
            E, F, G, H,
            I, J, K, L,
            M, N, O, P,
            Q, R, S, T,
            U, V, W, X,
            Y, Z,
            NUM0, NUM1, NUM2, NUM3, NUM4,
            NUM5, NUM6, NUM7, NUM8, NUM9,
            ESCAPE, DELETE, SPACE, ENTER,
            LCONTROL, LSHIFT, LALT,
            LEFT, RIGHT, UP, DOWN,
            ADD, SUBSTRACT,
            F1, F2, F3, F4, F5,
            F6, F7, F8, F9, F10,
            F11, F12
        };
    }

    typedef struct s_InfoInput
    {
        enum KeyBoard::KeyID id;
        bool isPressed;
    } t_InfoInput;
    
} // arcDisplay

#endif