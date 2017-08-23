namespace gmath {

struct mat4 {

  union {
    float elements[16];
    vec4 columns[4];
  };

  mat4();
  mat4(vec4 c0, vec4 c1, vec4 c2, vec4 c3);

  inline vec4& operator[](size_t idx) { return this->columns[idx]; }
  inline const vec4& operator[](size_t idx) const { return this->columns[idx]; }

  static mat4 identity();
  static mat4 post_mul(const mat4& m, const mat4& n);
  static mat4 ortho(float left, float right, float bottom, float top, float z_near, float z_far);

};

} // namespace gmath
