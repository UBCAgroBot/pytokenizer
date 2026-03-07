project(pytokenizer_core LANGUAGES CXX)

set(PYTOKENIZER_SOURCES
  tokenizer.cpp
)

add_library(pytokenizer_core SHARED ${PYTOKENIZER_SOURCES})

target_link_libraries(pytokenizer_core
  PUBLIC pytokenizer_compile_config
)