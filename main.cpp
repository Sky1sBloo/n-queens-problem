#include "QueenBuilder.hpp"
#include <cctype>
#include <iostream>
#include <stdexcept>

int main(int argc, char* argv[])
{
    if (argc != 2) {
        std::cerr << "Error: Missing or too much arguments" << std::endl;
        return 1;
    }

    int size;

    try {
        size = std::stoi(argv[1]);
        QueenBuilder queens(size);
        std::cout << queens << std::endl;
    } catch (std::invalid_argument) {
        std::cerr << "Error: Argument not a number" << std::endl;
        return 1;
    } catch (QueenBuilderException& error) {
        std::cerr << error.what() << std::endl;
        return 1;
    }

    return 0;
}
