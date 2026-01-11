cmake_minimum_required(VERSION 3.10)
project(KenguruProject VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(client)
add_subdirectory(server)
add_subdirectory(math_lib)
add_subdirectory(common)
