#ifndef GAME_MATH_SRC_VEC4_HPP_INCLUDED
#define GAME_MATH_SRC_VEC4_HPP_INCLUDED

namespace gmath {

struct vec4 {

  float x, y, z, w;

  vec4();
  vec4(float cx, float cy, float cz, float cw);
  vec4(vec3 v, float cw);

};

} // namespace gmath

#endif // GAME_MATH_SRC_VEC4_HPP_INCLUDED
