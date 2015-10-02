# contacts CMakeLists.txt
aux_source_directory(. srcs)

include_directories(${PROJECT_SOURCE_DIR}/include
  ${PROJECT_SOURCE_DIR}/src/pugixml
  )

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable( contacts ${srcs})

link_directories(${PROJECT_SOURCE_DIR}/lib)

target_link_libraries(contacts
  person
  pugixml
  )