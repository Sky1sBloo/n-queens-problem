#pragma once

#include <initializer_list>
#include <array>

template <typename T, int Size>
class IterativeStack {
public:
    IterativeStack(std::initializer_list<T>);

    T& top();
    void push(const T& newValue);
    void pop();

private:
    std::array<T, Size> values;
    int current;
    int length;
};
