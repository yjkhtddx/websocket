# cmake最低版本
# Set the minimum required version of cmake for a project.
cmake_minimum_required(VERSION 3.0)

# 项目名称
# Set a name, version, and enable languages for the entire project.
project(websocket VERSION 0.1.1)

message("=======================================")
message("项目版本信息")
message("---------------------------------------")
message(${PROJECT_NAME})
message(${PROJECT_SOURCE_DIR})
message(${PROJECT_BINARY_DIR})
message(${PROJECT_VERSION})
message("---------------------------------------")

set(CMAKE_SYSTEM_NAME Linux )

SET (CMAKE_C_COMPILER             "/usr/bin/clang")
SET (CMAKE_C_FLAGS                "-Wall -std=c99 -Wno-error=deprecated-declarations -Wno-deprecated-declarations")
SET (CMAKE_C_FLAGS_DEBUG          "-g")
SET (CMAKE_C_FLAGS_MINSIZEREL     "-Os -DNDEBUG")
SET (CMAKE_C_FLAGS_RELEASE        "-O4 -DNDEBUG")
SET (CMAKE_C_FLAGS_RELWITHDEBINFO "-O2 -g")

SET (CMAKE_CXX_COMPILER             "/usr/bin/clang++")
SET (CMAKE_CXX_FLAGS                "-Wall -std=c++11 -Wno-error=deprecated-declarations -Wno-deprecated-declarations")
SET (CMAKE_CXX_FLAGS_DEBUG          "-g")
SET (CMAKE_CXX_FLAGS_MINSIZEREL     "-Os -DNDEBUG")
SET (CMAKE_CXX_FLAGS_RELEASE        "-O4 -DNDEBUG")
SET (CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g")

SET (CMAKE_AR      "/usr/bin/llvm-ar")
SET (CMAKE_LINKER  "/usr/bin/llvm-ld")
SET (CMAKE_NM      "/usr/bin/llvm-nm")
SET (CMAKE_OBJDUMP "/usr/bin/llvm-objdump")
SET (CMAKE_RANLIB  "/usr/bin/llvm-ranlib")

# 使用C++11特性
# Adds -D define flags to the compilation of source files.
# add_definitions(-std=c++11)


if(CMAKE_COMPILER_IS_GNUCXX)
    set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS} -Wdeprecated-declarations")
    message(STATUS "optional:-std=c++11")   
endif(CMAKE_COMPILER_IS_GNUCXX)

# 源代码文件和头文件加入变量SRC_LIST(可多组)
# Find all source files in a directory.
aux_source_directory(./websocket SRC_LIST)
aux_source_directory(./websocket/tools SRC_LIST)
aux_source_directory(./websocket/core SRC_LIST)

message("=======================================")
message("项目源文件列表")
message("---------------------------------------")
message(${SRC_LIST})
message("---------------------------------------")

# 头文件路径(可多组)
# Add include directories to the build.
include_directories(./websocket)
include_directories(./websocket/tools)
include_directories(./websocket/core)

# 库搜索路径(可多组)
# Specify directories in which the linker will look for libraries.
# link_directories(/usr/local/lib)  #  默认系统路径 protobuf + grpc
# link_directories(/home/gj027/GitHubFork/libwebsockets/build/lib) # libwebsockets
# link_directories(/home/gj027/GitHubFork/ffmpegBuild/dist/lib) # ffmpeg


# 生成程序名
# Add an executable to the project using the specified source files.
ADD_EXECUTABLE(websocket ${SRC_LIST})

# 库名(可多组)
# Link a target to given libraries.
# ffmpeg
# target_link_libraries(websocket -lavcodec -lavdevice -lavfilter -lavformat -lavutil -lswresample -lswscale)
# libwebsockets
# target_link_libraries(websocket -lwebsockets)
# grpc + protobuf
# target_link_libraries(websocket -lgrpc++ -lprotobuf -lpthread -lgrpc++_reflection)
# std::thread还需要这个东西 
# target_link_libraries(stream_media_service -lpthread) # grpc + protobuf 中已有,重复添加

