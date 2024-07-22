cmake_minimum_required(VERSION 3.5.0)
project(main.c VERSION 0.1.0 LANGUAGES C)
cmake_policy(SET CMP0072 NEW)  #making sure we use the new CMake

find_package(OpenGL REQUIRED)

add_executable(main.c 
main.c 
glad/glad.h 
glad/glad.c)

target_link_libraries(main.c 
glfw
OpenGL::GL
)

