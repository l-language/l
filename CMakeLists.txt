cmake_minimum_required (VERSION 3.8)
project ("L")

set(CMAKE_CXX_STANDARD 14)
set(L_VERSION_MAJOR 0)
set(L_VERSION_MINOR 0)
set(L_VERSION_PATCH 5)

include(InstallRequiredSystemLibraries)
set (CPACK_RESOURCE_FILE_LICENSE
  "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
set (CPACK_PACKAGE_VERSION_MAJOR "${L_VERSION_MAJOR}")
set (CPACK_PACKAGE_VERSION_MINOR "${L_VERSION_MINOR}")
set (CPACK_PACKAGE_VERSION_PATCH "${L_VERSION_PATCH}")
include(CPack)

configure_file(
  "${CMAKE_CURRENT_SOURCE_DIR}/src/L/version.cpp.in" 
  "${CMAKE_CURRENT_SOURCE_DIR}/src/L/version.cpp"
)

include_directories(include)
file(GLOB_RECURSE libL_SOURCES CONFIGURE_DEPENDS src/L/*.cpp)
add_library(libL OBJECT ${libL_SOURCES})
add_executable(L src/L.cpp $<TARGET_OBJECTS:libL>)

include(CTest)
add_test(NAME lexer COMMAND L ./test/helloworld.l)