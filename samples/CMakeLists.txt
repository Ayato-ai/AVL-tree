# Get all cpp-files in the current directory
file(GLOB samples_list RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} *.cpp)


foreach(sample_filename ${samples_list})
  # Get file name without extension
  get_filename_component(sample ${sample_filename} NAME_WE)

  # Add and configure executable file to be produced
  add_executable(${sample} ${sample_filename})
  target_link_libraries(${sample} ${AVL_TREE_LIBRARY})
  set_target_properties(${sample} PROPERTIES
    OUTPUT_NAME "${sample}"
    PROJECT_LABEL "${sample}"
    RUNTIME_OUTPUT_DIRECTORY "../")
endforeach()
