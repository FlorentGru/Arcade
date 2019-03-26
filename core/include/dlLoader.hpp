/*
** EPITECH PROJECT, 2018
** OOP_arcade_2018
** File description:
** DLLoader.hpp
*/

#ifndef DLLOARDER_HPP
#define DLLOARDER_HPP

#include <dlfcn.h>
#include <memory>
#include <string>
#include <iostream>

template<typename T>
class DLLoader
{
private:
    void *lib;
public:
    DLLoader()
    {
        this->lib = NULL;
    }

    void openLib(const std::string &libName)
    {
        this->closeLib();
        this->lib = dlopen(libName.c_str(), RTLD_LAZY);
        if (this->lib == NULL) {
            std::cout << "lib not open\n";
        }
    }

    T *getClass(const std::string &symbol) const
    {
        T *(*create)();

        create = (T *(*)()) (dlsym(this->lib, symbol.c_str()));
        if (dlerror() != nullptr) {
            std::cout << "symbol error\n";
        }
        return (create());
    }

    void closeLib()
    {
        if (this->lib != NULL) {
            if (dlclose(this->lib) != 0) {
                std::cerr << dlerror() << std::endl;
            }
        }
    }
};

#endif