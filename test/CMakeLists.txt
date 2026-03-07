project(tests LANGUAGES CXX)

# EXECUTABLES ---------------------------------
add_executable(playground playground.cpp)
target_link_libraries(playground
  PRIVATE pytokenizer
)