cmake_minimum_required(VERSION 3.4)

project(serversite)

option(BUILD_TESTING OFF)

add_subdirectory(thirdparty/curl)
add_subdirectory(thirdparty/json)

add_executable(app ${CMAKE_CURRENT_SOURCE_DIR}/applications/solution.cpp)

target_link_libraries(app libcurl nlohmann_json)

