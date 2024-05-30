message(STATUS "--- Run CMakeLists.txt for SPH-02-FDM ---")

# 设置源文件目录
set(EXE_SRC_PATH ${CMAKE_CURRENT_SOURCE_DIR})
message(STATUS "EXE_SRC_PATH = ${EXE_SRC_PATH}")

# 设置exe1的源文件变量为src_files
file(GLOB SRC_FILES ${EXE_SRC_PATH}/*.cpp ${EXE_SRC_PATH}/*.h)
message(STATUS "SRC_FILES = ${SRC_FILES}")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${EXE_OUTPUT_DIR})
message(STATUS "EXE_OUTPUT_PATH = ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}")

set(EXE_NAME 02-FDM)
# 生成可执行程序.exe
add_executable(${EXE_NAME} ${SRC_FILES})

# 链接MPI的lib库
target_link_libraries(${EXE_NAME})
