cmake_minimum_required(VERSION 3.15)

# # project detail
include(cmake/settings.cmake)
include(cmake/static_analyzers.cmake)
include(cmake/parse_git_tag.cmake)

set(PARSED_GIT_TAG_VERSION ${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH})

project(
    "translotator"
    VERSION ${PARSED_GIT_TAG_VERSION}
    LANGUAGES CXX)

# C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED On)

# alternative project name
string(TOUPPER ${PROJECT_NAME} PROJECT_NAME_UPPER)
string(TOLOWER ${PROJECT_NAME} PROJECT_NAME_LOWER)
string(REPLACE " " "_" PROJECT_NAME_UPPER ${PROJECT_NAME_UPPER})
string(REPLACE "-" "_" PROJECT_NAME_UPPER ${PROJECT_NAME_UPPER})
string(REPLACE " " "_" PROJECT_NAME_LOWER ${PROJECT_NAME_LOWER})
string(REPLACE "-" "_" PROJECT_NAME_LOWER ${PROJECT_NAME_LOWER})

# configure version header
configure_file(cmake/version.hpp.in
    ${CMAKE_SOURCE_DIR}/include/translotator/version.hpp @ONLY)

# Prevent building in the source directory
if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
    message(
        FATAL_ERROR
        "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there.\n"
    )
endif()

# common compile options
include(cmake/target_compile_options_common.cmake)

# Header only Library
add_library(translotator INTERFACE)
add_library(${PROJECT_NAME}::translotator ALIAS translotator)
target_compile_options_common(translotator INTERFACE)
target_include_directories(
    translotator
    INTERFACE $<INSTALL_INTERFACE:include>
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)

if(BUILD_TESTING)
    include(CTest)
    add_subdirectory(test)
endif()

if(BUILD_EXAMPLES)
    add_subdirectory(examples)
endif()

# Installation
include(GNUInstallDirs)
install(
    TARGETS translotator
    EXPORT ${PROJECT_NAME}Targets
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
    INCLUDES
    DESTINATION include
    PUBLIC_HEADER DESTINATION include)
install(
    EXPORT ${PROJECT_NAME}Targets
    FILE ${PROJECT_NAME}Targets.cmake
    NAMESPACE ${PROJECT_NAME}::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME})
install(DIRECTORY include/${PROJECT_NAME} DESTINATION include)

# Uninstallation
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/cmake/cmake_uninstall.cmake.in"
    "${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake" @ONLY)
add_custom_target(
    uninstall COMMAND ${CMAKE_COMMAND} -P
    ${CMAKE_CURRENT_BINARY_DIR}/cmake_uninstall.cmake)

# Packaging
include(CMakePackageConfigHelpers)
write_basic_package_version_file(
    ${PROJECT_NAME}ConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion)
configure_package_config_file(
    ${CMAKE_CURRENT_LIST_DIR}/cmake/${PROJECT_NAME}Config.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME})
install(FILES ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME})
