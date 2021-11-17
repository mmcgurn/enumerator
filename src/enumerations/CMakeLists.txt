target_sources(enumeratorLibrary
        PUBLIC
        enumeration.hpp
        list.hpp
        list.cpp
        )

target_include_directories(enumeratorLibrary PUBLIC ${CMAKE_CURRENT_LIST_DIR})
