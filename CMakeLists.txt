cmake_minimum_required(VERSION 3.24)
project(leetcode)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(leetcode
        func.h
        main.cpp
        Math_fun/math_fun.h Math_fun/mymath.cpp BackSearch/back_search.cpp Mat/My_Mat.cpp Greedy/greedy.cpp Sort/sort.cpp monotonic_stack/mono_stack.cpp Tree/tree.cpp List/list.cpp Test/test.cpp Dynamic/dynamic.cpp String/mystring.cpp Vector/vector.cpp HashSet/hash.cpp)
