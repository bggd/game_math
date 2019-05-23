#ifndef GAME_MATH_SRC_MAT4_HPP_INCLUDED
#define GAME_MATH_SRC_MAT4_HPP_INCLUDED

#include "vec3.hpp"
#include "vec4.hpp"

namespace gmath {

struct mat4 {

  union {
    float raw[16];
    vec4 elements[4];
  };

  mat4();
  mat4(vec4 c0, vec4 c1, vec4 c2, vec4 c3);

  inline vec4& operator[](size_t idx) { return this->elements[idx]; }
  inline const vec4& operator[](size_t idx) const { return this->elements[idx]; }

  static mat4 identity();
  static mat4 mul(const mat4& a, const mat4& b);
  static mat4 translate(vec3 position);
  static mat4 rotate(float angle, vec3 axis);
  static mat4 transpose(const mat4& m);
  static mat4 perspective(float y_fov, float aspect, float z_near, float z_far);
  static mat4 ortho(float left, float right, float bottom, float top, float z_near, float z_far);
  static mat4 look_at(vec3 position, vec3 target, vec3 up);

  static vec4 xform(const mat4& m, vec4 v);

};

} // namespace gmath

#endif // GAME_MATH_SRC_MAT4_HPP_INCLUDED
