cmake_minimum_required(VERSION 3.15)

project(Cursor VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Include headers
include_directories(include)

# Collect all .cpp files in src/ (recursively if needed)
file(GLOB_RECURSE LIB_SOURCES CONFIGURE_DEPENDS src/*.cpp)

# Define static library
add_library(${PROJECT_NAME} STATIC ${LIB_SOURCES})

# Make include path public for consumers
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Enable subdirectory for test
add_subdirectory(test)

# Installation rules (optional but recommended for reuse)
install(TARGETS ${PROJECT_NAME}
        EXPORT CursorTargets
        ARCHIVE DESTINATION lib
        LIBRARY DESTINATION lib
        RUNTIME DESTINATION bin)

install(DIRECTORY include/ DESTINATION include)

export(EXPORT CursorTargets
       FILE "${CMAKE_CURRENT_BINARY_DIR}/CursorTargets.cmake"
       NAMESPACE Cursor::)
