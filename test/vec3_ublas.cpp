#define BOOST_TEST_MODULE Vec3 Ublas
#define BOOST_TEST_DYN_LINK
#include <boost/test/included/unit_test.hpp>
#include <boost/numeric/ublas/vector.hpp>

#include "../src/vec3.hpp"
#include "../src/vec3.cpp"

#include <type_traits>


BOOST_AUTO_TEST_CASE(test_vec3_ubas, *boost::unit_test::tolerance<float>(0.00001f))
{
  BOOST_TEST(std::is_trivially_copyable<gmath::vec3>());

  gmath::vec3 v;
  BOOST_TEST(v.x == 0.0f);
  BOOST_TEST(v.y == 0.0f);
  BOOST_TEST(v.z == 0.0f);

  gmath::vec3 v2(1.0f, 2.0f, 3.0f);
  BOOST_TEST(v2.x == 1.0f);
  BOOST_TEST(v2.y == 2.0f);
  BOOST_TEST(v2.z == 3.0f);

  boost::numeric::ublas::vector<float> ub_vec_a(3);
  boost::numeric::ublas::vector<float> ub_vec_b(3);
  for (uint8_t i = 0; i < ub_vec_a.size(); ++i) {
    ub_vec_a(i) = i;
    ub_vec_b(i) = i+1.0f;
  }

  boost::numeric::ublas::vector<float> ub_vec_c = ub_vec_a + ub_vec_b;

  gmath::vec3 a(0.0f, 1.0f, 2.0f);
  gmath::vec3 b(1.0f, 2.0f, 3.0f);
  gmath::vec3 c = gmath::vec3::add(a, b);

  BOOST_TEST(c.x == ub_vec_c(0));
  BOOST_TEST(c.y == ub_vec_c(1));
  BOOST_TEST(c.z == ub_vec_c(2));

  c = gmath::vec3::sub(a, b);
  ub_vec_c = ub_vec_a - ub_vec_b;

  BOOST_TEST(c.x == ub_vec_c(0));
  BOOST_TEST(c.y == ub_vec_c(1));
  BOOST_TEST(c.z == ub_vec_c(2));

  c = gmath::vec3::mul(a, b);
  ub_vec_c = boost::numeric::ublas::element_prod(ub_vec_a, ub_vec_b);

  BOOST_TEST(c.x == ub_vec_c(0));
  BOOST_TEST(c.y == ub_vec_c(1));
  BOOST_TEST(c.z == ub_vec_c(2));

  float n = gmath::vec3::dot(a, b);
  float ub_n = boost::numeric::ublas::inner_prod(ub_vec_a, ub_vec_b);

  BOOST_TEST(n == ub_n);
}
