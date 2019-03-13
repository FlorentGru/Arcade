/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** DLLoader.cpp
*/

#include "DLLoader.hpp"
#include <dlfcn.h>
#include <exception>

DLLoader::DLLoader(const std::string &libName)
{
    this->openLib(libName);
}

DLLoader::DLLoader() {}

DLLoader::~DLLoader()
{
    this->closeLib();
}

void DLLoader::openLib(const std::string &libName)
{
    this->closeLib();
    this->lib = dlopen(libName.c_str(), RTLD_LAZY);
    if (lib == NULL) {
        return (84);
    }
}

template<typename T>
T *DLLoader::getClass(const std::string &symbol) const
{
    T *classPtr;

    if (this->lib == NULL) {
        return (NULL);
    }
    classPtr = dynamic_cast<T *> dlsym(this->lib, symbol);
    if (dlerror != NULL) {
        return (NULL);
    }
    return (classPtr);
}

void DLLoader::closeLib()
{
    if (this->lib != NULL) {
        dlclose(this->lib);
    }
}