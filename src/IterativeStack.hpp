#pragma once

#include <cstddef>
#include <stdexcept>
#include <vector>

template <typename T>
class IterativeStack {
public:
    IterativeStack(std::size_t newCapacity)
    {
        values.reserve(newCapacity);
    }

    T& top() 
    {
        return values.back();
    }

    void push(const T& newValue)
    {
        if (values.size() == values.capacity()) {
            throw std::length_error("Tried pushing a full stack");
        }
        values.push_back(newValue);
    }

    void pop()
    {
        if (values.size() == 0) {
            throw std::length_error("Tried popping an empty stack");
        }
        values.pop_back();
    }

    bool isEmpty() const { return values.size() == 0; }
    std::size_t getLength() const { return values.size(); }

    // Iterators
    std::vector<T>::iterator begin() 
    {
        return values.begin();
    }

    std::vector<T>::iterator end() 
    {
        return values.end();
    }

private:
    std::vector<T> values;
};
