cmake_minimum_required(VERSION 3.19)
project(SandPiles)

find_package(OpenCV REQUIRED)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -pthread")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} -O0")
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-Ofast")
set(BUILD_ARCH "-m64")


file(GLOB sandPilesCPPs CONFIGURE_DEPENDS *.cpp)
add_executable(SandPiles ${sandPilesCPPs})
target_link_libraries(SandPiles ${OpenCV_LIBS} stdc++fs)
set_target_properties(SandPiles PROPERTIES RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")