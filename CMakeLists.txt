cmake_minimum_required(VERSION 3.10)

set(PATCH_VERSION "1" CACHE INTERNAL "Patch version")
set(PROJECT_VERSION 0.0.${PATCH_VERSION})
set(gtest_force_shared_crt ON)

project(helloworld VERSION ${PROJECT_VERSION})

# find_package(Boost COMPONENTS unit_test_framework REQUIRED)

configure_file(version.h.in version.h)

add_executable(helloworld_cli hello_world.cpp)
add_library(helloworld lib.cpp)
target_include_directories(
    helloworld PRIVATE "${CMAKE_BINARY_DIR}"
)

target_link_libraries(helloworld_cli PRIVATE helloworld)
include_directories(${CMAKE_BINARY_DIR} ${CMAKE_SOURCE_DIR})


install(TARGETS helloworld_cli RUNTIME DESTINATION bin)
set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_DEBIAN_PACKAGE_MAINTAINER "Nikolas")

include(CPack)

enable_testing()

add_subdirectory(googletest)

add_library(helloworld_cli_lib STATIC hello_world.cpp lib.h)

add_subdirectory(test)