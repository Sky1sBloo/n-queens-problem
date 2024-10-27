#pragma once

#include <initializer_list>
#include <list>

template <typename T>
class IterativeStack {
public:
    IterativeStack(std::initializer_list<T>);

    T& top();
    void push(const T& newValue);
    void pop();

private:
    std::list<T> values;
};
