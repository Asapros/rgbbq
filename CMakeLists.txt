cmake_minimum_required(VERSION 4.3)

project(gmtk-2026 CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

if(EMSCRIPTEN)
    include(FetchContent)

    FetchContent_Declare(
        raylib
        GIT_REPOSITORY https://github.com/raysan5/raylib.git
        GIT_TAG 5.5
    )

    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
    set(BUILD_GAMES OFF CACHE BOOL "" FORCE)

    FetchContent_MakeAvailable(raylib)
else()
    find_package(raylib REQUIRED)
endif()

file(GLOB_RECURSE SRC CONFIGURE_DEPENDS "src/*.cpp" "src/*.h")
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

if (EMSCRIPTEN)
  set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -s USE_GLFW=3 -s ASSERTIONS=1 -s WASM=1 -s ASYNCIFY")
  set(CMAKE_EXECUTABLE_SUFFIX ".html") # This line is used to set your executable to build with the emscripten html template so taht you can directly open it.
endif ()
