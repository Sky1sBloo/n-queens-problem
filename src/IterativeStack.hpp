#pragma once

#include <initializer_list>
#include <forward_list>

template <typename T>
class IterativeStack {
public:
    IterativeStack(std::initializer_list<T>);

    T& top();
    void push(const T& newValue);
    void pop();

private:
    std::forward_list<T> values;
};
