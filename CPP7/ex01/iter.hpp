#pragma once

#include <cstddef>

template <typename T>
void iter(T *array, const size_t len, void (*f)(T &))
{
    if (!array || !f)
        return;

    for (size_t i = 0; i < len; ++i)
        f(array[i]);
}

template <typename T>
void iter(const T *array, const size_t len, void (*f)(const T &))
{
    if (!array || !f)
        return;

    for (size_t i = 0; i < len; ++i)
        f(array[i]);
}
