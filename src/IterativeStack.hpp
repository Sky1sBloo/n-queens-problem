#pragma once

#include <cstddef>
#include <initializer_list>
#include <stdexcept>
#include <vector>

template <typename T>
class IterativeStack {
public:
    IterativeStack(std::initializer_list<T> newValues, std::size_t newCapacity)
        : values(newValues)
        , capacity(newCapacity)
    {
        values.reserve(capacity);
    }

    T& top() 
    {
        return values.back();
    }

    void push(const T& newValue)
    {
        if (values.size() == capacity) {
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
    const std::vector<T, std::allocator<T>>::const_iterator begin() const
    {
        return values.begin();
    }

    const std::vector<T, std::allocator<T>>::const_iterator end() const
    {
        return values.end();
    }

private:
    std::vector<T> values;
    const std::size_t capacity;
};
