set(target ${AVL_TREE_TESTS})

file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

include_directories("${CMAKE_CURRENT_SOURCE_DIR}/../3rdparty")

add_executable(${target} ${srcs} ${hdrs})
target_link_libraries(${target} gtest ${AVL_TREE_LIBRARY})
