cmake_minimum_required(VERSION 3.10)

project(gmath)

enable_testing()

if(MSVC)
  set(CMAKE_CXX_FLAGS_DEBUG "/Wall /permissive- /MDd /Zi /Ob0 /Od /RTC1 " CACHE STRING "" FORCE)
endif()

find_package(boost COMPONENTS unit_test_framework)

add_executable(test_vec3 test/vec3.cpp)
target_include_directories(test_vec3 PRIVATE ${Boost_INCLUDE_DIRS})
target_link_libraries(test_vec3 PRIVATE ${Boost_UNIT_TEST_FRAMEWORRK_LIBRARY})
add_test(NAME test_vec3 COMMAND test_vec3)
