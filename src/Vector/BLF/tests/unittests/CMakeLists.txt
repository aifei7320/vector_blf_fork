include_directories(${PROJECT_SOURCE_DIR}/src)

find_package(Boost 1.55 COMPONENTS unit_test_framework REQUIRED)
include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIRS})

add_definitions(
  -DCMAKE_CURRENT_SOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}"
  -DCMAKE_CURRENT_BINARY_DIR="${CMAKE_CURRENT_BINARY_DIR}")

add_executable(test_Logfile test_Logfile.cpp)

if(OPTION_USE_GCOV_LCOV)
  add_definitions(-g -O0 -fprofile-arcs -ftest-coverage)
  target_link_libraries(test_Logfile gcov)
endif()

target_link_libraries(test_Logfile
  Vector_BLF
  ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY})

enable_testing()

add_test(Logfile test_Logfile)
