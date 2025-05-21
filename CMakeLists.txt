cmake_minimum_required(VERSION 3.22)
project(TypeLangFixer VERSION 1.0.0)

# Enable CTest and options only for the main project
if(CMAKE_CURRENT_SOURCE_DIR STREQUAL CMAKE_SOURCE_DIR)
    include(CTest)
    set(PARENT_PROJECT_NAME ${PROJECT_NAME})
    option(TypeLangFixer_BUILD_TESTING "Enable testing" ON)
endif()

set(project_lib ${PROJECT_NAME}Lib)
set(project_exec ${PROJECT_NAME})

# Configuration
set(version_config "${PROJECT_NAME}ConfigVersion.cmake")
set(project_config "${PROJECT_NAME}Config.cmake")
set(TARGETS_EXPORT_NAME "${PROJECT_NAME}Targets")
set(namespace "qlm::")
set(INSTALL_INC_DIR "include")
set(INSTALL_BIN_DIR "bin")
set(INSTALL_LIB_DIR "lib")
set(INSTALL_RUN_DIR "dll")
set(INSTALL_CFG_DIR "cmake")

# Source files
file(GLOB_RECURSE SOURCES source/*.cpp)

# Create the static library
add_library(${project_lib} STATIC ${SOURCES})

set_target_properties(${project_lib} PROPERTIES 
                        CXX_STANDARD 20
                        CXX_EXTENSIONS OFF)

target_include_directories(${project_lib} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${INSTALL_INC_DIR}>
)

add_library(${namespace}::${project_lib} ALIAS ${project_lib})

# Source file for the executable
set(MAIN_SOURCE main.cpp)

# Create the executable
add_executable(${project_exec} ${MAIN_SOURCE})
target_link_libraries(${project_exec} PRIVATE ${project_lib})

# Check if testing is enabled
if(TypeLangFixer_BUILD_TESTING AND BUILD_TESTING)
    message(STATUS "Testing for ${PROJECT_NAME} is enabled")
    add_subdirectory(tests)

    set(INSTALL_GTEST OFF CACHE BOOL "" FORCE)
    set(INSTALL_GMOCK OFF CACHE BOOL "" FORCE)
endif()

# Install the executable
install(TARGETS ${project_exec}
    RUNTIME DESTINATION ${INSTALL_BIN_DIR}
)

# Install the library
install(TARGETS ${project_lib}
    EXPORT "${TARGETS_EXPORT_NAME}"
    LIBRARY DESTINATION ${INSTALL_LIB_DIR}
    ARCHIVE DESTINATION ${INSTALL_LIB_DIR}
    RUNTIME DESTINATION ${INSTALL_RUN_DIR}
    INCLUDES DESTINATION ${INSTALL_INC_DIR}
)

install(EXPORT "${TARGETS_EXPORT_NAME}"
    NAMESPACE "${namespace}"
    DESTINATION "${INSTALL_CFG_DIR}"
)

install(
    DIRECTORY include/
    DESTINATION ${INSTALL_INC_DIR}
    FILES_MATCHING PATTERN "*.hpp"
)

# Create the package configuration file
include(CMakePackageConfigHelpers)
configure_package_config_file(
  "${CMAKE_CURRENT_SOURCE_DIR}/cmake/${project_config}.in"
  "${CMAKE_CURRENT_BINARY_DIR}/${project_config}"
  INSTALL_DESTINATION "${INSTALL_CFG_DIR}"
)

# Write the library version file
write_basic_package_version_file(
  "${CMAKE_CURRENT_BINARY_DIR}/${version_config}"
  COMPATIBILITY AnyNewerVersion
)

# Install configuration and version files
install(FILES 
    "${CMAKE_CURRENT_BINARY_DIR}/${version_config}"
    "${CMAKE_CURRENT_BINARY_DIR}/${project_config}"
    DESTINATION ${INSTALL_CFG_DIR}
)
