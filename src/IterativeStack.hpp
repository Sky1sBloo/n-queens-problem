#pragma once

#include <array>
#include <initializer_list>
#include <stdexcept>

template <typename T, int Size>
class IterativeStack {
public:
    IterativeStack(std::initializer_list<T> newValues)
        : values(newValues)
    {
    }

    T& top()
    {
        return values[current];
    }

    void push(const T& newValue)
    {
        if (length == Size - 1) {
            throw std::length_error("Tried pushing a full stack");
        }

        if (current < Size - 1) {
            values[++current] = newValue;
        } else {
            values[0] = newValue;
        }

        length++;
    }

    void pop()
    {
        if (length == 0) {
            throw std::length_error("Tried popping an empty stack");
        }

        if (current > 0) {
            current--;
            length--;
        } else {
            current = (--length > 0) ? (Size - 1) : 0;
        }
    }

private:
    std::array<T, Size> values;
    int current;
    int length;
};
