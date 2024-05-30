# 设置CMake最低版本号
cmake_minimum_required(VERSION 3.12)

# 设置项目的语言
set(CMAKE_CXX_STANDARD 17)

# 设置工程项目的名称
project("SPH-Method")

# 设置源码根目录和项目二进制构建目录
set(ROOT_SRC_DIR ${PROJECT_SOURCE_DIR})
message(STATUS "ROOT_SRC_DIR = ${ROOT_SRC_DIR}")

set(ROOT_BUILD_DIR ${PROJECT_BINARY_DIR})
message(STATUS "ROOT_BUILD_DIR = ${ROOT_BUILD_DIR}")


set(EXE_OUTPUT_DIR ${ROOT_BUILD_DIR}/bin)
file(MAKE_DIRECTORY ${EXE_OUTPUT_DIR})
message(STATUS "EXE_OUTPUT_DIR = ${EXE_OUTPUT_DIR}")

set(DATA_OUTPUT_DIR ${ROOT_BUILD_DIR}/data)
file(MAKE_DIRECTORY ${DATA_OUTPUT_DIR})

# 添加项目源码路径
include_directories(${ROOT_SRC_DIR})

# 在这个CMakeLists.txt文件中，通过add_subdirectory命令引入
if (WIN32)
  add_subdirectory(SPH-02-FDM) 
endif()