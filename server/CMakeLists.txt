add_executable(server src/server.cpp include/Server.h)
target_link_libraries(server math_lib common)
target_include_directories(server PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
