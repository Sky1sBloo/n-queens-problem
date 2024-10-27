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
    auto decrementChecker = [&](int newValue) {
        if (length - 1 >= 0) {
            current = newValue;
            length--;
        }
    };

    if (current > 0) {
        decrementChecker(--current);
    } else {
        decrementChecker(Size - 1);
    }
}
