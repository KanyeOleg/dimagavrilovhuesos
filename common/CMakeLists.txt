# Создаем статическую библиотеку
add_library(common STATIC src/Config.cpp)
target_include_directories(common PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
