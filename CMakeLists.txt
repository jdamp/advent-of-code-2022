cmake_minimum_required(VERSION 3.10)
project(aoc2022 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Find google test
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


# Build library with common tools
file(GLOB HELP_INCLUDE "include/*.h")
file(GLOB HELP_SRC "src/*.cpp")
add_library(aocUtils SHARED ${HELP_INCLUDE} ${HELP_SRC})
include_directories(./include)
add_subdirectory(tests)

# Add all subdirectories named "days/dayxx" as subdirectories
MESSAGE(PWD=${CMAKE_CURRENT_SOURCE_DIR})
file(GLOB DAYS RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/days/day*)
MESSAGE("DAYS=${DAYS}")

FOREACH(DAY ${DAYS})
    ADD_SUBDIRECTORY(${DAY})
ENDFOREACH()


# copy data files to the build directory
add_custom_command(TARGET aocUtils POST_BUILD
                   COMMAND ${CMAKE_COMMAND} -E copy_directory
                   ${CMAKE_SOURCE_DIR}/data/ $<TARGET_FILE_DIR:aocUtils>/data/
)