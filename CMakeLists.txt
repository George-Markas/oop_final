cmake_minimum_required(VERSION 3.25)
project(oop_final)

set(CMAKE_CXX_STANDARD 20)

add_compile_definitions(DEBUG)

add_executable(${PROJECT_NAME}
               main.cpp
               maze.cpp
               maze.h
               entity.cpp
               entity.h
)

target_link_libraries(${PROJECT_NAME} -lncursesw)