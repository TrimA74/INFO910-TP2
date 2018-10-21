cmake_minimum_required(VERSION 3.10)
project(TP2_INFO901)

set(CMAKE_CXX_STANDARD 11)

add_executable(TP2_INFO901 Rainbow.cpp Rainbow.h Cracker.cpp Cracker.h Context.cpp Context.h test-context.cpp cracker-tool.cpp rainbow-tool.cpp parameters-tool.cpp)