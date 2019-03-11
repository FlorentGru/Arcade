/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** DLLoader.hpp
*/

#ifndef DLLOARDER_HPP
#define DLLOARDER_HPP

#include <string>

class DLLoader {
private:
    void *lib;
public:
    DLLoader();
    DLLoader(const std::string &libName);
    ~DLLoader();

    void openLib(const std::string &libName);
    void closeLib();
    
    template<typename T>
    T *getClass(const std::string &symbol) const;
};

#endif