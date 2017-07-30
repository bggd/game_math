namespace gmath {

struct Mat4 {

  union {
    float elements[16] = {
      1.0f, 0.0f, 0.0f, 0.0f,
      0.0f, 1.0f, 0.0f, 0.0f,
      0.0f, 0.0f, 1.0f, 0.0f,
      0.0f, 0.0f, 0.0f, 1.0f
    };
    struct {
      float m00, m01, m02, m03;
      float m04, m05, m06, m07;
      float m08, m09, m10, m11;
      float m12, m13, m14, m15;
    };
  };

};

namespace mat4 {

gmath::Mat4 mul(const gmath::Mat4& A, const gmath::Mat4& B);

gmath::Mat4 ortho(float left, float right, float bottom, float top, float z_near, float z_far);

} // namespace gmath::mat4
} // namespace gmath
