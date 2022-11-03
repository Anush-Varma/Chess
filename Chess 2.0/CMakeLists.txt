cmake_minimum_required(VERSION 3.22)
project(Chess_2_0)

set(CMAKE_CXX_STANDARD 14)

add_executable(Chess_2_0 main.cpp Board.cpp Board.h ChessPieces.cpp ChessPieces.h Game.cpp Game.h Empty.cpp Empty.h)
