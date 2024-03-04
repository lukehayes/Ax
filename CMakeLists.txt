cmake_minimum_required(VERSION 3.2)
project(Ax)

# Variables.
# 
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(INCLUDE_DIRS "include")
set(BIN_NAME "Ax")

#add_compile_definitions(DEBUG=true)
#add_compile_definitions(MAX_ENTITIES=100)
add_definitions(DEBUG=true)
add_definitions(MAX_ENTITIES=100)

# Find all source files.
# 
# file(GLOB SRC_FILES "${CMAKE_SOURCE_DIR}/src/*.cpp")

# Find GLFW library.
# 
find_package(glfw3 3.3 REQUIRED)

# Set the project include directories.
# 
include_directories(${INCLUDE_DIRS})

add_executable(${BIN_NAME} main.cpp ${SRC_FILES})

add_subdirectory("src")

# Link in any libraies the binary needs.
# 
target_link_libraries(${BIN_NAME} glfw)

target_link_libraries(${BIN_NAME} AxLib)

