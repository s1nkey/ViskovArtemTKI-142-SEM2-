cmake_minimum_required(VERSION 3.14)
project(GeometryProject)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>DLL")

include(FetchContent)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_library(core
    src/CircularList.cpp
    src/Node.cpp
)

target_include_directories(core PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/header
)

add_executable(tests
    tests/tests.cpp
)

target_link_libraries(tests
    PRIVATE
    core
    gtest
    gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests)
