cmake_minimum_required(VERSION 3.10)
project(KenguruProject VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Добавляем поддиректории
add_subdirectory(common)
add_subdirectory(math_lib)
add_subdirectory(server)
add_subdirectory(client)
