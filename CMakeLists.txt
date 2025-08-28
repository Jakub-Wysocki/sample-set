cmake_minimum_required(VERSION 3.10)

project(Skill-sample C)

include_directories(inc)

file(GLOB SOURCES "src/*.c")

add_executable(main ${SOURCES})

target_link_libraries(main m)