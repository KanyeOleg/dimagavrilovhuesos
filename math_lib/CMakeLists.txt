add_library(math_lib SHARED src/MathLib.cpp include/MathLib.h)
target_include_directories(math_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
