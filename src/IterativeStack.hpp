#pragma once

#include <cstddef>
#include <initializer_list>
#include <stdexcept>
#include <vector>

template <typename T>
class IterativeStack {
public:
    IterativeStack(std::initializer_list<T> newValues, std::size_t newCapacity)
        : values(newValues), current(0), length(newValues.size()), capacity(newCapacity)
    {
        values.reserve(capacity);
    }

    const T& top() const
    {
        return values[current];
    }

    void push(const T& newValue)
    {
        if (length == capacity - 1) {
            throw std::length_error("Tried pushing a full stack");
        }

        if (current < capacity - 1) {
            values[++current] = newValue;
        } else {
            values[0] = newValue;
        }

        length++;
    }

    void pop()
    {
        if (length == 0) {
            throw std::length_error("Tried popping an empty stack");
        }

        if (current > 0) {
            current--;
            length--;
        } else {
            current = (--length > 0) ? (capacity - 1) : 0;
        }
    }

    bool isEmpty() const { return length == 0; }
    std::size_t getLength() const { return length; }

    // Iterators
    const T* begin() const
    {
        return &(values[current]);
    }

    const T* end() const
    {
        return &(values[(current + length) % capacity]);
    }

private:
    std::vector<T> values;
    std::size_t current;
    std::size_t length;
    const std::size_t capacity;
};
