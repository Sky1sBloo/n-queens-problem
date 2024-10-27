#include "IterativeStack.hpp"

template <typename T>
T& IterativeStack<T>::top()
{
    return values[current];
}

template <typename T>
void IterativeStack<T>::push()
{

}
template <typename T>
void IterativeStack<T>::pop()
{
    if (current > 0)
    {
        current--;
    }
    else {
        current = values.size() - 1;
    }
}
