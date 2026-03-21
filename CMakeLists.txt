cmake_minimum_required(VERSION 3.24)
project(pytokenizer LANGUAGES CXX)

# CORE CONFIG ---------------------------------
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# CORE TARGETS ---------------------------------
add_library(pytokenizer_compile_config INTERFACE)
target_compile_options(pytokenizer_compile_config
  INTERFACE
    $<$<CONFIG:Release>:-march=native;-ffast-math> # also compiles with -O3 -DNDEBUG
    $<$<CONFIG:Debug>:-march=native;-ffast-math> # -g
)
target_include_directories(pytokenizer_compile_config
  INTERFACE
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/csrc/include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}/csrc/include>
)

add_subdirectory(csrc/src/core)
add_subdirectory(csrc/bindings)
add_subdirectory(test)
add_subdirectory(benchmark)

add_library(pytokenizer INTERFACE)
target_link_libraries(pytokenizer INTERFACE pytokenizer_core)


# FORMATTING ---------------------------------
file(GLOB_RECURSE ALL_SOURCE "${CMAKE_CURRENT_SOURCE_DIR}/csrc/src/*.[ch]pp")

find_program(CLANG_FORMAT_EXE NAMES clang-format)
if(CLANG_FORMAT_EXE)
  add_custom_target(format
    COMMAND ${CLANG_FORMAT_EXE}
            -i
            ${ALL_SOURCE}
    COMMENT "Apply clang-format to all sources"
  )
endif()


# LINTING ---------------------------------
find_program(CLANG_TIDY_EXE NAMES clang-tidy)
if(CLANG_TIDY_EXE)
  add_custom_target(lint
    COMMAND ${CLANG_TIDY_EXE}
            -p build
            ${ALL_SOURCE} -header-filter=.*
    COMMENT "Apply clang-tidy to all sources"
  )
endif()
