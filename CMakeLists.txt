cmake_minimum_required(VERSION 3.21)
project(competition)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

set(CMAKE_CXX_FLAGS "-O2")

# add_subdirectory(oj)

# add_executable(P1616 oj/luogu/P1616.cpp)
# add_executable(segament.tree.struct exp/template/segament.tree.struct.cpp)
# add_executable(segament.tree exp/template/segament.tree.cpp)
# add_executable(KMP exp/template/KMP.cpp)
# add_executable(P1400 oj/jtx/P1400.cpp)
# add_executable(test other/test.cpp)
