# unity building
add_library(unity-framework STATIC unity/unity.c)
set(UNITY_HEADER_FILES
    unity/unity.h
    unity_internal.h)
set_target_properties(unity-framework PROPERTIES PUBLIC_HEADER "${UNITY_HEADER_FILES}")

# tests
add_executable(runner_test)
target_sources(runner_test PRIVATE 
    runner_test.c
)

target_link_libraries(runner_test PRIVATE data-structures unity-framework)