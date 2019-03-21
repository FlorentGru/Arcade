/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** DLLoader.cpp
*/

#include "dlLoader.hpp"
#include <dlfcn.h>

template<typename T>
DLLoader<T>::~DLLoader()
{
    this->closeLib();
}

template<typename T>
void DLLoader<T>::openLib(const std::string &libName)
{
    this->closeLib();
    this->lib = dlopen(libName.c_str(), RTLD_LAZY);
}

template<typename T>
std::unique_ptr<T> DLLoader<T>::getClass(const std::string &symbol) const
{
    T (*create)();

    if (this->lib == nullptr) {
//      throw
    }
    create = static_cast<T (*)()>(dlsym(this->lib, symbol));
    if (dlerror() != nullptr) {
//      throw
    }
    return (std::make_unique<T>(create()));
}

template<typename T>
void DLLoader<T>::closeLib()
{
    if (this->lib != NULL) {
        dlclose(this->lib);
    }
}