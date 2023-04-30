cmake_minimum_required(VERSION 3.25)
project(data-structures VERSION 1.0)

set(CMAKE_VERBOSE_MAKEFILE ON)

set(SOURCE_FILES
        src/main.c
        src/various/utils.c
        src/array/dynamic_array.c
        src/array/array_driver.c
        src/linked_list/s_linked_list.c
        src/linked_list/linked_list_driver.c
        src/stack/array_stack.c
        src/stack/stack_driver.c
        src/queue/array_queue.c
        src/queue/priority_queue.c
        src/queue/queue_driver.c)

add_executable(c-data-structures ${SOURCE_FILES})

target_compile_options(c-data-structures PRIVATE -m64 -Wall)

target_link_options(c-data-structures PRIVATE LINKER:-lm)