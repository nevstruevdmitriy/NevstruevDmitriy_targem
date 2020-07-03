cmake_minimum_required(VERSION 3.4)

include("cmake/HunterGate.cmake")

HunterGate(
    URL "https://github.com/cpp-pm/hunter/archive/v0.23.251.tar.gz"
    SHA1 "5659b15dc0884d4b03dbd95710e6a1fa0fc3258d"
)

project(MyString)

hunter_add_package(GTest)

find_package(GTest CONFIG REQUIRED)

include_directories(include)

add_library(MyString ${CMAKE_CURRENT_SOURCE_DIR}/sources/MyString.cpp)
add_executable(demo ${CMAKE_CURRENT_SOURCE_DIR}/examples/demo.cpp)
target_link_libraries(demo MyString)

target_compile_options(MyString PRIVATE -Wall -Wextra -pedantic -Werror -std=c++17)

enable_testing()
add_executable(check ${CMAKE_CURRENT_SOURCE_DIR}/tests/test.cpp)
target_link_libraries(check MyString GTest::gtest_main)
add_test(NAME check COMMAND check)

