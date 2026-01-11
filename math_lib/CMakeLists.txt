# Создаем shared библиотеку
add_library(math_lib SHARED src/MathLib.cpp)
target_include_directories(math_lib PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/../common/include
)
