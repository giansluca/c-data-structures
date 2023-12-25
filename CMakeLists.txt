cmake_minimum_required(VERSION 3.28)

project(data-structures VERSION "1.0.0" LANGUAGES C)

if(WIN32)
    message(STATUS "Platform windows")
    set(INSTALL_CURRENT_DIR ${PROJECT_SOURCE_DIR}/build/install)
    if (MSVC)
        set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
        add_compile_options(/W4)
    else()
        add_compile_options(-m64 -Wall)
    endif()
elseif(APPLE)
    message(STATUS "Platform apple")
    set(INSTALL_CURRENT_DIR ${PROJECT_SOURCE_DIR}/build/install)
    add_compile_options(-m64 -Wall)
elseif(UNIX)
    message(STATUS "Platform *nix")
    set(INSTALL_CURRENT_DIR ${PROJECT_SOURCE_DIR}/build/install)
    add_compile_options(-m64 -Wall)
endif()

message(STATUS "current project version: " ${CMAKE_PROJECT_VERSION})
message(STATUS "current project dir: " ${PROJECT_SOURCE_DIR})
message(STATUS "current binary dir: " ${CMAKE_CURRENT_BINARY_DIR})
message(STATUS "current install dir: " ${INSTALL_CURRENT_DIR})

add_subdirectory(src)
add_subdirectory(test)

# unit tests
enable_testing()
add_test(NAME Array COMMAND array_test)
add_test(NAME LinkedList COMMAND linked_list_test)
add_test(NAME Queue COMMAND queue_test)
list(APPEND CMAKE_CTEST_ARGUMENTS "--verbose")

# Example --> commands from project root
#
# -Debug-
# create makefile :         (mac)       cmake -S . -B build/debug -DCMAKE_C_COMPILER=clang -DCMAKE_BUILD_TYPE=Debug -Wno-dev
#                           (debian)    cmake -S . -B build/debug -DCMAKE_C_COMPILER=gcc -DCMAKE_BUILD_TYPE=Debug -Wno-dev
#                           (windows)   cmake -G "Unix Makefiles" -S . -B build/debug -DCMAKE_C_COMPILER=gcc -DCMAKE_BUILD_TYPE=Debug -Wno-dev
# build :                   cmake --build build/debug
# run tests :               make test -C build/debug (ctest --test-dir build/debug -V)
# build and run tests :     make all test -C build/debug
# install:                  cmake --install build/debug
# clean :                   cmake --build build/debug --target clean
# run configuration :       cmake build/debug       

#
# -Release-
# create makefile :         (mac)       cmake -S . -B build/release -DCMAKE_C_COMPILER=clang -DCMAKE_BUILD_TYPE=Release -Wno-dev
#                           (debian)    cmake -S . -B build/release -DCMAKE_C_COMPILER=gcc -DCMAKE_BUILD_TYPE=Release -Wno-dev
#                           (windows)   cmake -G "Unix Makefiles" -S . -B build/debug -DCMAKE_C_COMPILER=gcc -DCMAKE_BUILD_TYPE=Release -Wno-dev
# build :                   cmake --build build/release
# run tests :               make test -C build/release (ctest --test-dir build/release -V)
# build and run tests :     make all test -C build/release
# install:                  cmake --install build/release
# clean :                   cmake --build build/release --target clean
# run configuration :       cmake build/release
