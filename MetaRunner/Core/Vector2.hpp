//
// Code Taken from SFML Github - https://github.com/SFML/SFML/blob/master/include/SFML/System/Vector2.hpp
// Vector2ui8 and Vector2ui16 added
//
// SFML - Simple and Fast Multimedia Library
// Copyright (C) 2007-2018 Laurent Gomila (laurent@sfml-dev.org)
//
// This software is provided 'as-is', without any express or implied warranty.
// In no event will the authors be held liable for any damages arising from the use of this software.
//
// Permission is granted to anyone to use this software for any purpose,
// including commercial applications, and to alter it and redistribute it freely,
// subject to the following restrictions:
//
// 1. The origin of this software must not be misrepresented;
//    you must not claim that you wrote the original software.
//    If you use this software in a product, an acknowledgment
//    in the product documentation would be appreciated but is not required.
//
// 2. Altered source versions must be plainly marked as such,
//    and must not be misrepresented as being the original software.
//
// 3. This notice may not be removed or altered from any source distribution.
//
#ifndef RUNNER_GAMEBUINO_VECTOR2_H
#define RUNNER_GAMEBUINO_VECTOR2_H

template <typename T>
class Vector2
{
public:

    Vector2();

    Vector2(T X, T Y);

    template <typename U>
    explicit Vector2(const Vector2<U>& vector);

    T x;
    T y;

};

template <typename T>
Vector2<T> operator -(const Vector2<T>& right);

template <typename T>
Vector2<T>& operator +=(Vector2<T>& left, const Vector2<T>& right);

template <typename T>
Vector2<T>& operator -=(Vector2<T>& left, const Vector2<T>& right);

template <typename T>
Vector2<T> operator +(const Vector2<T>& left, const Vector2<T>& right);

template <typename T>
Vector2<T> operator -(const Vector2<T>& left, const Vector2<T>& right);

template <typename T>
Vector2<T> operator *(const Vector2<T>& left, T right);

template <typename T>
Vector2<T> operator *(T left, const Vector2<T>& right);

template <typename T>
Vector2<T> operator *=(const Vector2<T>& left, T right);

template <typename T>
Vector2<T> operator /(const Vector2<T>& left, T right);

template <typename T>
Vector2<T>& operator /=(Vector2<T>& left, T right);

template <typename T>
bool operator ==(const Vector2<T>& left, const Vector2<T>& right);

template <typename T>
bool operator !=(const Vector2<T>& left, const Vector2<T>& right);

#include <stdint-gcc.h>
#include "Vector2.cpp"

typedef Vector2<int>            Vector2i
typedef Vector2<unsigned int>   Vector2u;
typedef Vector2<uint8_t>        Vector2ui8;
typedef Vector2<uint16_t>       Vector2ui16;

typedef Vector2<float> Vector2f






#endif
