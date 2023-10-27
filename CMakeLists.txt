cmake_minimum_required(VERSION 3.16)
project(basos VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

add_executable(basos main.cpp)

find_package(SFML 2.6.0 REQUIRED COMPONENTS graphics)


target_link_libraries(basos PRIVATE sfml-graphics)
target_compile_features(basos PRIVATE cxx_std_17)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
