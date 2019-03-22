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

    ~DLLoader()
    {
        this->closeLib();
    }

    void openLib(const std::string &libName)
    {
        this->closeLib();
        this->lib = dlopen("lib_graph1.so", RTLD_LAZY);
        std::cout << libName << std::endl;
        if (!this->lib) {
            std::cout << "ouioui\n";
        }
    }

    T *getClass(const std::string &symbol) const
    {
        T *(*create)();

        create = (T *(*)()) (dlsym(this->lib, symbol.c_str()));
        if (dlerror() != nullptr) {
            std::cout << "nonnon\n";
        }
        return (create());
    }

    void closeLib()
    {
        if (this->lib != NULL) {
            dlclose(this->lib);
        }
    }
};

#endif