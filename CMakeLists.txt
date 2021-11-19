cmake_minimum_required(VERSION 3.14)

# Create the new project
project(Enumerator VERSION 0.1.0)

# Set the standards
set(CMAKE_CXX_STANDARD 17)

# Create the project
add_library(enumeratorLibrary)

# FetContent will allow downloading of other libraries
include(FetchContent)

# Build a stand alone executable
add_executable(enumerator main.cpp)
target_link_libraries(enumerator PRIVATE enumeratorLibrary)

# Load in the source code
add_subdirectory(src)

# Get the CPP dependency
FetchContent_Declare(
        cppParser
        GIT_REPOSITORY https://github.com/UBCHREST/CppParser.git
        GIT_TAG main
)
FetchContent_MakeAvailable(cppParser)
target_link_libraries(enumeratorLibrary PUBLIC cppParserLibrary cppParserTestLibrary)

# Add required warnings for projects
function(default_target_compile_options target)
    if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
        target_compile_options(${target} PUBLIC $<$<OR:$<CXX_COMPILER_ID:Clang>,$<CXX_COMPILER_ID:AppleClang>,$<CXX_COMPILER_ID:GNU>>: -Werror -Wall -Wwrite-strings -Wno-strict-aliasing -Wno-unknown-pragmas -Wsign-compare -fstack-protector -fno-stack-check >)
    endif()
endfunction()
default_target_compile_options(enumeratorLibrary)
default_target_compile_options(enumerator)

# Check if we should enable testing options
if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    set_property(GLOBAL PROPERTY CTEST_TARGETS_ADDED 1)
    include(CTest)

    # Include the format command only if we are the main project
    include(clangFormatter.cmake)

    # Setup and configure testing
    if(BUILD_TESTING)
        enable_testing()
        include(GoogleTest)
        add_subdirectory(tests)
    endif()
endif()


