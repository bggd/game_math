#ifndef GAME_MATH_SRC_VEC3_HPP_INCLUDED
#define GAME_MATH_SRC_VEC3_HPP_INCLUDED

namespace gmath {

struct vec3 {

  float x, y, z;

  vec3();
  vec3(float cx, float cy, float cz);

  static vec3 add(vec3 a, vec3 b);
  static vec3 sub(vec3 a, vec3 b);
  static vec3 mul(vec3 a, vec3 b);
  static float length(vec3 v);
  static float length2(vec3 v);
  static vec3 normalize(vec3 v);
  static float dot(vec3 a, vec3 b);
  static vec3 cross(vec3 a, vec3 b);

  static vec3 scalar_mul(vec3 v, float scalar);

};

} // namespace gmath

#endif //GAME_MATH_SRC_VEC3_HPP_INCLUDED
