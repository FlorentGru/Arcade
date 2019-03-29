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
#include <exception>

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
            std::cerr << "Error: cannot open library\n";
            throw std::exception();
        }
    }

    T *getClass(const std::string &symbol) const
    {
        T *(*create)();

        create = (T *(*)()) (dlsym(this->lib, symbol.c_str()));
        if (dlerror() != nullptr) {
            std::cerr << "Error: entry point not found\n";
            throw std::exception();
        }
        return (create());
    }

    void closeLib()
    {
        if (this->lib != NULL) {
            if (dlclose(this->lib) != 0) {
                std::cerr << dlerror() << std::endl;
                throw std::exception();
            }
        }
    }
};

#endif