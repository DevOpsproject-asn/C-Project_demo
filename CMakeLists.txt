cmake_minimum_required(VERSION 3.10)
project(MathUtils VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set output directories
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Add compile flags for better warnings and optimization
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic -O2)
endif()

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/include)

# ===== Math Library =====
add_library(mathutils
    src/math_utils.cpp
)

target_include_directories(mathutils PUBLIC
    $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# ===== Main Application =====
add_executable(math_app
    src/main.cpp
)

target_link_libraries(math_app PRIVATE mathutils)

# ===== Unit Tests =====
enable_testing()

add_executable(run_tests
    tests/test_math_utils.cpp
)

target_link_libraries(run_tests PRIVATE mathutils)
target_include_directories(run_tests PRIVATE ${CMAKE_SOURCE_DIR}/include)

add_test(NAME MathUtilsTests COMMAND run_tests)

# ===== Install Targets (Optional) =====
install(TARGETS math_app mathutils
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
)

install(DIRECTORY include/ DESTINATION include)

# ===== Print Build Info =====
message(STATUS "=== Build Configuration ===")
message(STATUS "Build Type: ${CMAKE_BUILD_TYPE}")
message(STATUS "C++ Standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "Compiler: ${CMAKE_CXX_COMPILER}")
message(STATUS "Source Dir: ${CMAKE_SOURCE_DIR}")
message(STATUS "Binary Dir: ${CMAKE_BINARY_DIR}")
message(STATUS "===========================")
