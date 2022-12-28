# CMakeList.txt : CMake project for AoC2022, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("AoC2022")

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Add source to this project's executable.
add_library (AoC2022Lib STATIC "Day1.cpp" "Day2.cpp" "Day3.cpp" "Day4.cpp" "Day5.cpp" "Day6.cpp" "Day7.cpp" "Day8.cpp" "Day9.cpp" "Day10.cpp")
target_include_directories(AoC2022Lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


add_executable (AoC2022 "AoC2022.cpp" "AoC2022.h")
target_include_directories(AoC2022 PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_directories(AoC2022 PUBLIC "${OUTPUT_DIRECTORY}")
target_link_libraries(AoC2022 AoC2022Lib)
# TODO: Add tests and install targets if needed.

enable_testing()

add_executable(
  AoCTests
  Day1Test.cpp
  Day10Test.cpp
)
target_link_libraries(
  AoCTests
  GTest::gtest_main
  AoC2022Lib
)

include(GoogleTest)
gtest_discover_tests(AoCTests)

add_test(executable AoC2022)
