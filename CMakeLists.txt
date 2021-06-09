cmake_minimum_required(VERSION 3.10)

project(mat)

add_library(matrix STATIC src/Matrix.cpp)
add_library(fraction STATIC src/Fraction.cpp)

add_executable(mat src/mat.cpp)
target_link_libraries(mat PUBLIC matrix)
target_link_libraries(mat PUBLIC fraction)

install(TARGETS mat DESTINATION bin)