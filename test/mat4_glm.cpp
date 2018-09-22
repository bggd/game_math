#define BOOST_TEST_MODULE Mat4 GLM
#define BOOST_TEST_DYN_LINK
#include <boost/test/included/unit_test.hpp>

#include "../src/vec3.hpp"
#include "../src/vec3.cpp"
#include "../src/vec4.hpp"
#include "../src/vec4.cpp"
#include "../src/mat4.hpp"
#include "../src/mat4.cpp"

#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include <type_traits>
#include <vector>


BOOST_AUTO_TEST_CASE(test_mat4_glm, *boost::unit_test::tolerance<float>(0.000001f))
{
  BOOST_TEST(std::is_trivially_copyable<gmath::mat4>());

  gmath::mat4 M = gmath::mat4::look_at(gmath::vec3(0.0f, 1.0f, 2.0f), gmath::vec3(3.0f, 4.0f, 5.0f), gmath::vec3(6.0f, 7.0f, 8.0f));

  glm::mat4 glm_M = glm::lookAt(glm::vec3(0.0f, 1.0f, 2.0f), glm::vec3(3.0f, 4.0f, 5.0f), glm::vec3(6.0f, 7.0f, 8.0f));

  BOOST_TEST(std::vector<float>(M.elements, M.elements+16) == std::vector<float>(glm::value_ptr(glm_M), glm::value_ptr(glm_M)+16), boost::test_tools::per_element());

  M = gmath::mat4::perspective(glm::pi<float>() * 0.25f, 4.0f / 3.0f, 0.1f, 100.0f);
  
  glm_M = glm::perspective(glm::pi<float>() * 0.25f, 4.0f / 3.0f, 0.1f, 100.0f);

  BOOST_TEST(std::vector<float>(M.elements, M.elements+16) == std::vector<float>(glm::value_ptr(glm_M), glm::value_ptr(glm_M)+16), boost::test_tools::per_element());

  M = gmath::mat4::ortho(0.0f, 640.0f, 480.0f, 0.0f, 0.1f, 100.0f);

  glm_M = glm::ortho(0.0f, 640.0f, 480.0f, 0.0f, 0.1f, 100.0f);

  BOOST_TEST(std::vector<float>(M.elements, M.elements+16) == std::vector<float>(glm::value_ptr(glm_M), glm::value_ptr(glm_M)+16), boost::test_tools::per_element());
}
