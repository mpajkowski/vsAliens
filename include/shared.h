/**
 * vsAliens
 * shared.h
 *
 * shared includes and settings
 */

#pragma once
/////////////////////////////
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "settings.h"

typedef unsigned int uint;

template<typename T>
class ObjectContainer : private std::vector<T>
{
public:
    typedef std::vector<T> Vector;
    using Vector::clear;
    using Vector::at;
    using Vector::begin;
    using Vector::size_type;
    using Vector::size;
    using Vector::operator[];
    using Vector::push_back;
    using Vector::erase;
    using Vector::iterator;
    using Vector::const_iterator;
    using Vector::end;
    using Vector::cbegin;
    using Vector::cend;
    void test() { printf("%d\n", this->size()); }
    virtual ~ObjectContainer() {}
private:
    //
};
