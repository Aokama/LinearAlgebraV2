cmake_minimum_required(VERSION 3.16)
project(LinearAlgebra)

set(CMAKE_CXX_STANDARD 20)

add_executable(LinearAlgebra main.cpp PowerIterationMethod.cpp PowerIterationMethod.h Matrix.cpp Matrix.h Dimension.cpp Dimension.h Vector.cpp Vector.h)