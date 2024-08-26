cmake_minimum_required(VERSION 3.10)
project(IntegerVector)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add source files
set(SOURCES src/integer_vector.cpp main.cpp)

# Add include directories
include_directories(include)

# Add the executable
add_executable(main ${SOURCES})

# Google Test
enable_testing()

# Add GoogleTest
add_subdirectory("D:/Work/googletest" "${CMAKE_BINARY_DIR}/googletest")

# Include directories
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

# Add test executable
add_executable(runTests 
               tests/test_main.cpp
               tests/test_integer_vector.cpp 
               tests/test_integer_linked_list.cpp  # Add this line
               src/integer_vector.cpp
               src/integer_linked_list.cpp)  # Add this line
target_link_libraries(runTests gtest gtest_main)

# Add tests
add_test(NAME IntegerVectorTests COMMAND runTests)