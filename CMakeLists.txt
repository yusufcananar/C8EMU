cmake_minimum_required(VERSION 3.0.0)
project(c8emu VERSION 0.1.0)


file (GLOB_RECURSE c8emu_SOURCES CONFIGURE_DEPENDS "src/*.cpp")
file (GLOB_RECURSE c8emu_HEADERS CONFIGURE_DEPENDS "src/*.hpp")

set (c8emu_INCLUDE_DIRS "")
foreach (_headerFile ${c8emu_HEADERS})
    get_filename_component(_dir ${_headerFile} PATH)
    list (APPEND c8emu_INCLUDE_DIRS ${_dir})
endforeach()
list (REMOVE_DUPLICATES c8emu_INCLUDE_DIRS)

add_executable(c8emu ${c8emu_SOURCES})
target_include_directories(c8emu PRIVATE ${c8emu_INCLUDE_DIRS})


# include_directories("${PROJECT_SOURCE_DIR}/src")

# set(SOURCE main.cpp)
# add_executable(c8emu src/main.cpp src/chip8.cpp)