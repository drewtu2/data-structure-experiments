# Create a library called "Hello" which includes the source file "hello.cxx".
# The extension is already found. Any number of sources could be listed here.
add_library (CircularBuffer
    circular_buffer.hpp
    circular_buffer.cpp
    )

# Make sure the compiler can find include files for our Hello library
# when other libraries or executables link to Hello
target_include_directories (CircularBuffer
    PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR})

set_target_properties(CircularBuffer PROPERTIES LINKER_LANGUAGE CXX)
