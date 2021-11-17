target_sources(enumeratorLibrary
        PUBLIC
        enumerator.hpp
        enumerator.cpp
        generator.hpp
        reporter.hpp
        )

add_subdirectory(enumerations)
target_include_directories(enumeratorLibrary PUBLIC ${CMAKE_CURRENT_LIST_DIR})
