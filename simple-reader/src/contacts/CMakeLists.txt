# contacts CMakeLists.txt
aux_source_directory(. srcs)

set(BOOST_ROOT "/opt/boost")

#set(Boost_USE_STATIC_LIBS ON)
#set(Boost_USE_MULTITHREADED ON)
#set(Boost_USE_STATIC_RUNTIME OFF)


# filesystem依赖system
#
find_package(Boost REQUIRED COMPONENTS
#  regex
filesystem
system
)

if(NOT Boost_FOUND)
  message("未发现Boost")
endif()


include_directories(${PROJECT_SOURCE_DIR}/include
  ${PROJECT_SOURCE_DIR}/src/pugixml
  ${Boost_INCLUDE_DIRS}
  )

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

add_executable( contacts ${srcs})

link_directories(${PROJECT_SOURCE_DIR}/lib)

target_link_libraries(contacts
  person
  pugixml
  ${Boost_LIBRARIES}
  )