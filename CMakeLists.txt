cmake_minimum_required(VERSION 3.10)

project(gmath)

include(CTest)

if(BUILD_TESTING)

  if(MSVC)
    set(CMAKE_CXX_FLAGS_DEBUG "/W4 /permissive- /MDd /Zi /Ob0 /Od /RTC1" CACHE STRING "" FORCE)
  endif()

  find_package(Boost REQUIRED COMPONENTS unit_test_framework)
  find_package(glm REQUIRED)

  add_executable(test_vec3_ublas test/vec3_ublas.cpp)
  target_include_directories(test_vec3_ublas PRIVATE ${Boost_INCLUDE_DIRS})
  target_link_libraries(test_vec3_ublas PRIVATE Boost::unit_test_framework)
  add_test(NAME test_vec3_ublas COMMAND test_vec3_ublas)

  add_executable(test_vec3_glm test/vec3_glm.cpp)
  target_include_directories(test_vec3_glm PRIVATE ${Boost_INCLUDE_DIRS})
  target_link_libraries(test_vec3_glm PRIVATE glm Boost::unit_test_framework)
  add_test(NAME test_vec3_glm COMMAND test_vec3_glm)

  add_executable(test_mat4_ublas test/mat4_ublas.cpp)
  target_include_directories(test_mat4_ublas PRIVATE ${Boost_INCLUDE_DIRS})
  target_link_libraries(test_mat4_ublas PRIVATE Boost::unit_test_framework)
  add_test(NAME test_mat4_ublas COMMAND test_mat4_ublas)

  add_executable(test_mat4_glm test/mat4_glm.cpp)
  target_include_directories(test_mat4_glm PRIVATE ${Boost_INCLUDE_DIRS})
  target_link_libraries(test_mat4_glm PRIVATE glm Boost::unit_test_framework)
  add_test(NAME test_mat4_glm COMMAND test_mat4_glm)

endif()
