cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME AVL_TREE)
project(${PROJECT_NAME})

# TODO(Kornyakov): not sure if these lines are needed
set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE)
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE})

#set(AVL_TREE_LIBRARY "${PROJECT_NAME}")
set(AVL_TREE_CUSTOM "${PROJECT_NAME}")
set(AVL_TREE_TESTS   "test_${PROJECT_NAME}")
set(AVL_TREE_INCLUDE "${CMAKE_CURRENT_SOURCE_DIR}/include")

include_directories("${AVL_TREE_INCLUDE}" gtest)

# BUILD
add_subdirectory(include)
add_subdirectory(samples)
add_subdirectory(gtest)
add_subdirectory(test)

# REPORT
message( STATUS "")
message( STATUS "General configuration for ${PROJECT_NAME}")
message( STATUS "======================================")
message( STATUS "")
message( STATUS "   Configuration: ${CMAKE_BUILD_TYPE}")
message( STATUS "")