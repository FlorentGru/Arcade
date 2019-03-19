/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** DLLoader.hpp
*/

#ifndef DLLOARDER_HPP
#define DLLOARDER_HPP

#include <string>

template<typename T>
class DLLoader {
private:
    void *lib;
public:
    ~DLLoader();

    void openLib(const std::string &libName);
    void closeLib();
    std::unique_ptr<T> getClass(const std::string &symbol) const;
};

#endif