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
  static mat4 mul(const mat4& a, const mat4& b);
  static mat4 translate(vec3 position);
  static mat4 rotate(float angle, vec3 axis);
  static mat4 perspective(float y_fov, float aspect, float z_near, float z_far);
  static mat4 ortho(float left, float right, float bottom, float top, float z_near, float z_far);

  static vec4 xform(const mat4& m, vec4 v);

};

} // namespace gmath
