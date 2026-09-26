cmake_minimum_required(VERSION 3.16)

project(robot_endpoints LANGUAGES CXX)

include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

add_library(robot_endpoints INTERFACE)
add_library(robot_endpoints::robot_endpoints ALIAS robot_endpoints)

target_compile_features(robot_endpoints INTERFACE cxx_std_17)

target_include_directories(
  robot_endpoints
  INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

install(TARGETS robot_endpoints EXPORT robot_endpointsTargets)

install(DIRECTORY DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

install(DIRECTORY include/ DESTINATION ${CMAKE_INSTALL_INCLUDEDIR} OPTIONAL)

set(ROBOT_ENDPOINTS_CMAKE_INSTALL_DIR "${CMAKE_INSTALL_LIBDIR}/cmake/robot_endpoints")

configure_package_config_file(
  cmake/robot_endpointsConfig.cmake.in
  "${CMAKE_CURRENT_BINARY_DIR}/robot_endpointsConfig.cmake"
  INSTALL_DESTINATION "${ROBOT_ENDPOINTS_CMAKE_INSTALL_DIR}"
)

install(
  FILES "${CMAKE_CURRENT_BINARY_DIR}/robot_endpointsConfig.cmake"
  DESTINATION "${ROBOT_ENDPOINTS_CMAKE_INSTALL_DIR}"
)

install(
  EXPORT robot_endpointsTargets
  FILE robot_endpointsTargets.cmake
  NAMESPACE robot_endpoints::
  DESTINATION "${ROBOT_ENDPOINTS_CMAKE_INSTALL_DIR}"
)
