cmake_minimum_required(VERSION 4.3)

project(gmtk-2026 CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

find_package(raylib REQUIRED)

file(GLOB SRC CONFIGURE_DEPENDS "src/*.cpp" "src/*.h")
add_executable(gmtk-2026 ${SRC})

target_compile_options(gmtk-2026 PRIVATE
    -Wall
    -Wextra
    -Wpedantic
)

target_link_libraries(gmtk-2026 PRIVATE raylib)

add_custom_target(run
    COMMAND gmtk-2026
    DEPENDS gmtk-2026
    WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}/bin
)
