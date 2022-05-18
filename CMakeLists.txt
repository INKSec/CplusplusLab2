cmake_minimum_required(VERSION 3.22)
project(CLionProjekt)

set(CMAKE_CXX_STANDARD 17)

add_executable(CLionProjekt main.cpp KlasseA.cpp )

add_subdirectory(dishlib)


target_link_libraries(CLionProjekt dishlib )

















