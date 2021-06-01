cmake_minimum_required(VERSION 3.19)
project(Lab3)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wunused-parameter -Wextra -Wreorder -Wa,-mbig-obj")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wa,-mbig-obj")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wunused-parameter -Wextra -Wreorder -Wa,-mbig-obj -O2")
set(CMAKE_CXX_STANDARD 20)

#add_executable(Lab3 main.cpp Branch.h BinaryTree.h 3-aryTree.h Branch3.h MenuFull.h MenuTree3.h MenuBinaryTree.h test.cpp catch.hpp Speed_Test.cpp)
add_executable(Lab3 main.cpp Branch.h BinaryTree.h 3-aryTree.h Branch3.h MenuFull.h MenuTree3.h MenuBinaryTree.h Speed_Test.cpp Speed_Test.h)