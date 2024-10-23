add_library(n-queens-problem-lib)
target_sources(n-queens-problem-lib
    Board.cpp
)

target_include_directories(n-queens-problem-lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
