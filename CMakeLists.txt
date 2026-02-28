cmake_minimum_required(VERSION 3.24)
project(pytokenizer LANGUAGES CXX)

# CORE CONFIG ---------------------------------
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


# CORE TARGETS ---------------------------------
add_subdirectory(csrc/src/)
add_subdirectory(csrc/bindings)


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
