# unity building
add_library(unity-framework STATIC unity/unity.c)
set(UNITY_HEADER_FILES
    unity/unity.h
    unity_internal.h)
set_target_properties(unity-framework PROPERTIES PUBLIC_HEADER "${UNITY_HEADER_FILES}")

add_executable(array_test)
target_sources(array_test PRIVATE modules/array_test.c)
target_link_libraries(array_test PRIVATE data-structures unity-framework)

add_executable(linked_list_test)
target_sources(linked_list_test PRIVATE modules/linked_list_test.c)
target_link_libraries(linked_list_test PRIVATE data-structures unity-framework)

add_executable(queue_test)
target_sources(queue_test PRIVATE modules/queue_test.c)
target_link_libraries(queue_test PRIVATE data-structures unity-framework)

add_executable(stack_test)
target_sources(stack_test PRIVATE modules/stack_test.c)
target_link_libraries(stack_test PRIVATE data-structures unity-framework)
