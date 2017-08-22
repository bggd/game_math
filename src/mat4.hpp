namespace gmath {

struct mat4 {

  float elements[16] = {
    1.0f, 0.0f, 0.0f, 0.0f,
    0.0f, 1.0f, 0.0f, 0.0f,
    0.0f, 0.0f, 1.0f, 0.0f,
    0.0f, 0.0f, 0.0f, 1.0f
  };

  static mat4 mul(const mat4& left, const mat4& right);
  static mat4 ortho(float left, float right, float bottom, float top, float z_near, float z_far);

};

} // namespace gmath
