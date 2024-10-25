option(CPP_LINT "Enable cppcheck & clang-tidy" OFF)
option(BUILD_EXAMPLES "Enable examples" OFF)
option(BUILD_TESTING "Enable testing" OFF)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()