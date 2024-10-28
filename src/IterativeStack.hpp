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

    const T& top() const
    {
        *(values.end());
    }

    void push(const T& newValue)
    {
        if (values.size() == capacity) {
            throw std::length_error("Tried pushing a full stack");
        }

        values[values.size() - 1] = newValue;
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
    const T* begin() const
    {
        return values.begin();
    }

    const T* end() const
    {
        return values.end();
    }

private:
    std::vector<T> values;
    const std::size_t capacity;
};
