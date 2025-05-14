cmake_minimum_required(VERSION 3.15)
project(Cursor VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Header files
include_directories(include)

# Source files
file(GLOB_RECURSE LIB_SOURCES CONFIGURE_DEPENDS src/*.cpp)

# Static library
add_library(${PROJECT_NAME} STATIC ${LIB_SOURCES})
target_include_directories(${PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
)

# Optional test program
add_subdirectory(test)

# ========== Installation Support ==========

# Install the compiled library
install(TARGETS ${PROJECT_NAME}
    EXPORT CursorTargets
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)

# Install headers
install(FILES ${CMAKE_SOURCE_DIR}/include/cursor.hpp DESTINATION include)
install(DIRECTORY ${CMAKE_SOURCE_DIR}/include/cursor DESTINATION include)

# Export targets for find_package support
install(EXPORT CursorTargets
    FILE CursorTargets.cmake
    NAMESPACE Cursor::
    DESTINATION lib/cmake/Cursor
)

# Generate a config file for find_package
include(CMakePackageConfigHelpers)
configure_package_config_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/CursorConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/CursorConfig.cmake
    INSTALL_DESTINATION lib/cmake/Cursor
)

# Install config file
install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/CursorConfig.cmake
    DESTINATION lib/cmake/Cursor
)
