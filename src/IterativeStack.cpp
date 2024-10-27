#include "IterativeStack.hpp"
#include <stdexcept>

template <typename T, int Size>
T& IterativeStack<T, Size>::top()
{
    return values[current];
}

template <typename T, int Size>
void IterativeStack<T, Size>::push(const T& newValue)
{
}

template <typename T, int Size>
void IterativeStack<T, Size>::pop()
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
