#define BOOST_TEST_MODULE Mat4 Ublas
#define BOOST_TEST_DYN_LINK
#include <boost/test/included/unit_test.hpp>
#include <boost/numeric/ublas/matrix.hpp>

#include "../src/vec3.hpp"
#include "../src/vec3.cpp"
#include "../src/vec4.hpp"
#include "../src/vec4.cpp"
#include "../src/mat4.hpp"
#include "../src/mat4.cpp"

#include <type_traits>
#include <stdio.h>

using namespace boost::numeric;

BOOST_AUTO_TEST_CASE(test_mat4_ubas, *boost::unit_test::tolerance(0.00001))
{
  BOOST_TEST(std::is_trivially_copyable<gmath::mat4>());

  gmath::mat4 ident = gmath::mat4::identity();

  ublas::matrix<float, ublas::column_major> ublas_i = ublas::identity_matrix<float>(4);

  BOOST_TEST(ident.elements == ublas_i.data());

  gmath::mat4 m = gmath::mat4();
  for (uint8_t i = 0; i < 16; ++i) {
    m.elements[i] = i;
  }

  ublas::matrix<float, ublas::column_major> ublas_m(4, 4);
  for (uint8_t i = 0; i < 4; ++i) {
    for (uint8_t j = 0; j < 4; ++j) {
      ublas_m(j, i) = 4*i + j;
    }
  }

  BOOST_TEST(m.elements == ublas_m.data());

  gmath::mat4 n = gmath::mat4::mul(m, m);

  ublas::matrix<float, ublas::column_major> ublas_n = ublas::prod(ublas_m, ublas_m);

  BOOST_TEST(n.elements == ublas_n.data());

  for (uint8_t c = 0; c < 4; ++c) {
    for (uint8_t r = 0; r < 4; ++r) {
      m.elements[4*c+r] = 0.0f;
      if (c == r) { m.elements[4*c+r] = 2.0f; }
    }
  }

  gmath::vec4 v1(1.0f, 1.0f, 1.0f, 1.0f);

  gmath::vec4 v2 = gmath::mat4::xform(m, v1);

  for (uint8_t c = 0; c < 4; ++c) {
    for (uint8_t r = 0; r < 4; ++r) {
      ublas_m(c, r) = 0.0f;
      if (c == r) { ublas_m(c, r) = 2.0f; }
    }
  }

  ublas::vector<float> ublas_v1(4);
  for (uint8_t i = 0; i < ublas_v1.size(); ++i) {
    ublas_v1(i) = 1.0f;
  }

  ublas::vector<float> ublas_v2 = ublas::prod(ublas_m, ublas_v1);

  BOOST_TEST(v2.x == ublas_v2(0));
  BOOST_TEST(v2.y == ublas_v2(1));
  BOOST_TEST(v2.z == ublas_v2(2));
  BOOST_TEST(v2.w == ublas_v2(3));

}
