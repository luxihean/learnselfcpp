cmake_minimum_required(VERSION 3.20)
project(CppProject)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 添加 include 目录
include_directories(${CMAKE_SOURCE_DIR}/include)

# 定义 hellotest 的可执行文件
add_executable(hellotest_main
    src/hellotest/main.cpp
    src/hellotest/hello.cpp
)
add_executable(CH1_10to2_main
    src/CH1/10to2/main.cpp
)
add_executable(CH1_talorexp_main
    src/CH1/talorexp/main.cpp
)
add_executable(CH1_caculatesimulator_main
    src/CH1/caculatesimulator/main.cpp
    src/CH1/caculatesimulator/error.cpp
)
