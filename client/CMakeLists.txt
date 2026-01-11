add_executable(client src/client.cpp include/Client.h)
target_link_libraries(client common)
target_include_directories(client PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
