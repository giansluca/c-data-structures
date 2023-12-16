set(SOURCE_FILES
        various/utils.c
        array/dynamic_array.c
        array/array_driver.c
        linked_list/s_linked_list.c
        linked_list/linked_list_driver.c
        stack/array_stack.c
        stack/stack_driver.c
        queue/array_queue.c
        queue/priority_queue.c
        queue/queue_driver.c)

set(HEADER_FILES
        various/utils.h
        array/dynamic_array.h
        array/array_driver.h
        linked_list/s_linked_list.h
        linked_list/linked_list_driver.h
        stack/array_stack.h
        stack/stack_driver.h
        queue/array_queue.h
        queue/priority_queue.h
        queue/queue_driver.h)

add_library(data-structures STATIC)
target_sources(data-structures PRIVATE ${SOURCE_FILES})
set_target_properties(data-structures PROPERTIES PUBLIC_HEADER "${HEADER_FILES}")

add_executable(data-structures-main)
target_sources(data-structures-main PRIVATE main.c)
target_link_libraries(data-structures-main PRIVATE data-structures)

install(TARGETS data-structures data-structures-main
    RUNTIME DESTINATION ${INSTALL_CURRENT_DIR}/bin
    LIBRARY DESTINATION ${INSTALL_CURRENT_DIR}/lib
    ARCHIVE DESTINATION ${INSTALL_CURRENT_DIR}/lib
    PUBLIC_HEADER DESTINATION ${INSTALL_CURRENT_DIR}/include)   
