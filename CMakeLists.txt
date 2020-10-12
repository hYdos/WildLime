cmake_minimum_required(VERSION 3.17)
project(WildLime)

set(CMAKE_CXX_STANDARD 20)

find_package(glfw3 REQUIRED)
find_package(glm REQUIRED)
find_package(Vulkan REQUIRED)

add_executable(WildLime main.cpp)

target_link_libraries(WildLime glfw)
target_link_libraries(WildLime glm)
target_link_libraries(WildLime vulkan)