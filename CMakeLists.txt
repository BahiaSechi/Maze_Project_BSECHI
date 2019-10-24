cmake_minimum_required(VERSION 3.15)
project(Maze_Project_BSECHI C)

set(CMAKE_C_STANDARD 99)

add_executable(Maze_Project_BSECHI main.c maze.c maze.h gameplay.c gameplay.h player.c player.h tools.c tools.h score.c score.h)