cmake_minimum_required(VERSION 3.10.0)
project(SpaceCrafter VERSION 0.1.0 LANGUAGES C CXX)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 设置编译选项

if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Werror)
endif()

# 设置CMAKE输出目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_SOURCE_DIR}/Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_Release ${CMAKE_SOURCE_DIR}/Release)

# 设置产物名称
set(TARGET ${PROJECT_NAME}-${CMAKE_HOST_SYSTEM_NAME})

# 添加Package
find_package(SDL2 REQUIRED)

add_executable(${TARGET} src/main.cpp)

# target_link_libraries(${TARGET}  
#                                 SDL::SDL2main 
#                                 SDL::SDL2)

#链接库， 这个变量可以替代上面的SDL2Main，SDL2 ，该变量可以处理跨平台.
target_link_libraries(${TARGET} 
                                ${SDL2_LIBRARIES}
                                SDL2_image::SDL2_image) 

# # 添加可执行文件
# add_executable(SpaceCrafter main.cpp)

# # 添加头文件搜索路径
# include_directories(${CMAKE_SOURCE_DIR}/lib/SDL2/include)

# # 添加库文件搜索路径
# link_directories(${CMAKE_SOURCE_DIR}/lib/SDL2/lib/x64)

# # 链接库文件


# include_directories("./lib/SDL2/include")

# link_directories("./lib/SDL2/lib/x64")

# add_executable(SpaceCrafter main.cpp)

# target_link_libraries(SpaceCrafter SDL2main SDL2)