cmake_minimum_required(VERSION 3.10)
project(palind_cm)
set(CMAKE_C_STANDARD 11)
include_directories(include)
add_executable(palind_cm src/palind.c src/main.c)
add_executable(test_palind src/palind.c test/test_palind.c)
configure_file(
    "${CMAKE_SOURCE_DIR}/rgr1.txt"
    "${CMAKE_BINARY_DIR}/rgr1.txt"
    COPYONLY
)
