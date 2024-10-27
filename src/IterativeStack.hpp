#pragma once

#include <initializer_list>
#include <vector>


template <typename T>
class IterativeStack
{
public:
    IterativeStack(std::initializer_list<T>);

    T& top();
    void push();
    void pop();
private:
    std::vector<T> values;
    int current;
};
