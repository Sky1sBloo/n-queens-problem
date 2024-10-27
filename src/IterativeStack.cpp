#include "IterativeStack.hpp"

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
    auto decrementChecker = [this](int newValue) {
        if (length - 1 >= 0) {
            this->current = newValue;
        }
    };
    if (current > 0) {
        current--;
        length--;
    } else {
        if (length > 0) {
            current = length - 1;
        }
    }
}
