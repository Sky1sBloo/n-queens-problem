#include "IterativeStack.hpp"

template <typename T>
T& IterativeStack<T>::top()
{
    return values[0];
}

template <typename T>
void IterativeStack<T>::push(const T& newValue)
{
    values.push_front(newValue);
}

template <typename T>
void IterativeStack<T>::pop()
{
    values.pop_front();
}
