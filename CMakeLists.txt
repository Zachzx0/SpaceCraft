cmake_minimum_required(VERSION 3.10.0)
project(SpaceCrafter VERSION 0.1.0 LANGUAGES C CXX)

include_directories("./lib/SDL2/include")

link_directories("./lib/SDL2/lib/x64")

add_executable(SpaceCrafter main.cpp)

target_link_libraries(SpaceCrafter SDL2main SDL2)