cmake_minimum_required (VERSION 2.8.11)
project (listtests CXX C ASM)

# Set the build definitions
SET(CMAKE_CXX_FLAGS "-g -O0 -std=gnu++11")
SET(BUILD_DEFINITIONS_TARGET "")
SET(BUILD_DEFINITIONS_DEBUG "")
SET(BUILD_DEFINITIONS_RELEASE "")

include_directories(${CMAKE_CURRENT_LIST_DIR})
link_directories(${CMAKE_CURRENT_BINARY_DIR})

add_executable(
    ${CMAKE_PROJECT_NAME}
    main.cpp
    ListTests.cpp
)

target_link_libraries(
    ${CMAKE_PROJECT_NAME}
    gtest
    pthread
)

add_custom_target(run DEPENDS ${CMAKE_PROJECT_NAME} COMMAND ./${CMAKE_PROJECT_NAME})