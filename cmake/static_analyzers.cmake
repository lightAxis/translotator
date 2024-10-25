# Cppcheck setup
if(CPP_LINT)
    find_program(CPPCHECK cppcheck)

    if(CPPCHECK)
        message(STATUS "CMAKE_BINARY_DIR found: ${CMAKE_BINARY_DIR}")
        set(CMAKE_CXX_CPPCHECK
            ${CPPCHECK} --enable=all --std=c++17 --language=c++
            --suppress=missingIncludeSystem)
        message(STATUS "cppcheck found: ${CPPCHECK}")
    else()
        message(WARNING "cppcheck not found")
    endif()

    # Clang-tidy setup
    find_program(CLANGTIDY clang-tidy)

    if(CLANGTIDY)
        set(CMAKE_CXX_CLANG_TIDY ${CLANGTIDY})
        message(STATUS "clang-tidy found: ${CLANGTIDY}")
    else()
        message(WARNING "clang-tidy not found")
    endif()
endif()
