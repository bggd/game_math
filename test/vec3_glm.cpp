#define BOOST_TEST_MODULE Vec3 GLM
#define BOOST_TEST_DYN_LINK
#include <boost/test/included/unit_test.hpp>

#include <glm/glm.hpp>
#include <glm/ext.hpp>

#include "../src/vec3.hpp"
#include "../src/vec3.cpp"

#include <type_traits>


BOOST_AUTO_TEST_CASE(test_vec3_glm, *boost::unit_test::tolerance(0.00001))
{
  BOOST_TEST(std::is_trivially_copyable<gmath::vec3>());

  gmath::vec3 a(0.0f, 1.0f, 2.0f);
  gmath::vec3 b(1.0f, 2.0f, 3.0f);
  gmath::vec3 c = gmath::vec3::add(a, b);

  glm::vec3 glm_a(0.0f, 1.0f, 2.0f);
  glm::vec3 glm_b(1.0f, 2.0f, 3.0f);
  glm::vec3 glm_c = glm_a + glm_b;

  BOOST_TEST(c.x == glm_c.x);
  BOOST_TEST(c.y == glm_c.y);
  BOOST_TEST(c.z == glm_c.z);

  c = gmath::vec3::sub(a, b);
  glm_c = glm_a - glm_b;

  BOOST_TEST(c.x == glm_c.x);
  BOOST_TEST(c.y == glm_c.y);
  BOOST_TEST(c.z == glm_c.z);

  c = gmath::vec3::mul(a, b);
  glm_c = glm_a * glm_b;

  BOOST_TEST(c.x == glm_c.x);
  BOOST_TEST(c.y == glm_c.y);
  BOOST_TEST(c.z == glm_c.z);

  float len = gmath::vec3::length(c);
  float glm_len = glm::length(glm_c);

  BOOST_TEST(len == glm_len);

  c = gmath::vec3::normalize(c);
  glm_c = glm::normalize(glm_c);

  BOOST_TEST(c.x == glm_c.x);
  BOOST_TEST(c.y == glm_c.y);
  BOOST_TEST(c.z == glm_c.z);

  float d = gmath::vec3::dot(a, b);
  float glm_d = glm::dot(glm_a, glm_b);

  BOOST_TEST(d == glm_d);

  c = gmath::vec3::cross(a, b);
  glm_c = glm::cross(glm_a, glm_b);

  BOOST_TEST(c.x == glm_c.x);
  BOOST_TEST(c.y == glm_c.y);
  BOOST_TEST(c.z == glm_c.z);
}
