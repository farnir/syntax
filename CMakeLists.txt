set(SRC main.cpp stack.cpp stack.cpp symbol.cpp)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -O3 -pedantic")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "..")
add_executable (syntax_analyser ${SRC})
