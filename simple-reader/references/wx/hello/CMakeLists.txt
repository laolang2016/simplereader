cmake_minimum_required(VERSION 3.3)

project(helloWX CXX)

aux_source_directory(. srcs)

find_package(wxWidgets REQUIRED)
include(${wxWidgets_USE_FILE})



add_executable(helloWX ${srcs})

TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${wxWidgets_LIBRARIES})


