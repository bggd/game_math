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

};

} // namespace gmath
