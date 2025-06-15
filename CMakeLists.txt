cmake_minimum_required(VERSION 3.10)
project(cube-solver)

# Add include directory
include_directories(include)

# Add executable with source files
add_executable(
    main
    main.cxx
    src/wall.cxx
    src/cube_constructors.cxx
    src/cube_moves.cxx
    src/cube_other.cxx
    src/cube_solving.cxx
)
