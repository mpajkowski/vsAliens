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


template<typename T>
class ObjectContainer : private std::vector<T> {
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
private:
    //
};
