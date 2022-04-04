cmake_minimum_required(VERSION 3.17)
project(hpx_hello_world CXX)


set(CMAKE_PREFIX_PATH "/opt/hpx")

find_package(HPX REQUIRED)

add_executable(hello_world main.cpp)

target_link_libraries(hello_world HPX::hpx HPX::wrap_main HPX::iostreams_component)