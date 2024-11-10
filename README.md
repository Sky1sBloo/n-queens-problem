# N Queens Problem
Program solving N-queens-problem. Used custom vector wrapper as stack since `std::stack` doesn't allow iteration without popping.
The class `QueenBuilder` overloads the ostream `<<` operator for output and uses its own exception `QueenBuilderException` if it fails to generate.

## Requirements
- C++20
- CMake minimum 3.28
- C++ Compiler (gcc/clang/visual studio)

## Installation
### Using CMake
1. Create build folder
```
mkdir build
cd build
```
2. Generate CMakeFiles
```
cmake ../
```
3. Build
```
cmake --build ./
```
### Using GCC
1. Move all files on src to main folder
2. Compile all cpp files with `-std=c++20`
   ```
   g++ -std=c++20 main.cpp QueenBuilder.cpp 
   ```
## Usage
```
n-queens-problem [number of queens]
```
Returns valid positions of queens.
