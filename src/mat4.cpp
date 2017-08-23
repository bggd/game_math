namespace gmath {

mat4::mat4() : elements{0.0f}
{
}

mat4::mat4(vec4 c0, vec4 c1, vec4 c2, vec4 c3) : columns{c0, c1, c2, c3}
{
}

mat4 mat4::identity()
{
  return {
    vec4(1.0f, 0.0f, 0.0f, 0.0f),
    vec4(0.0f, 1.0f, 0.0f, 0.0f),
    vec4(0.0f, 0.0f, 1.0f, 0.0f),
    vec4(0.0f, 0.0f, 0.0f, 1.0f)
  };
}

mat4 mat4::post_mul(const mat4& m, const mat4& n)
{
  mat4 r;

  r[0].x = m[0].x * n[0].x + m[1].x * n[0].y + m[2].x * n[0].z + m[3].x * n[0].w;
  r[1].x = m[0].x * n[1].x + m[1].x * n[1].y + m[2].x * n[1].z + m[3].x * n[1].w;
  r[2].x = m[0].x * n[2].x + m[1].x * n[2].y + m[2].x * n[2].z + m[3].x * n[2].w;
  r[3].x = m[0].x * n[3].x + m[1].x * n[3].y + m[2].x * n[3].z + m[3].x * n[3].w;

  r[0].y = m[0].y * n[0].x + m[1].y * n[0].y + m[2].y * n[0].z + m[3].y * n[0].w;
  r[1].y = m[0].y * n[1].x + m[1].y * n[1].y + m[2].y * n[1].z + m[3].y * n[1].w;
  r[2].y = m[0].y * n[2].x + m[1].y * n[2].y + m[2].y * n[2].z + m[3].y * n[2].w;
  r[3].y = m[0].y * n[3].x + m[1].y * n[3].y + m[2].y * n[3].z + m[3].y * n[3].w;

  r[0].z = m[0].z * n[0].x + m[1].z * n[0].y + m[2].z * n[0].z + m[3].z * n[0].w;
  r[1].z = m[0].z * n[1].x + m[1].z * n[1].y + m[2].z * n[1].z + m[3].z * n[1].w;
  r[2].z = m[0].z * n[2].x + m[1].z * n[2].y + m[2].z * n[2].z + m[3].z * n[2].w;
  r[3].z = m[0].z * n[3].x + m[1].z * n[3].y + m[2].z * n[3].z + m[3].z * n[3].w;

  r[0].w = m[0].w * n[0].x + m[1].w * n[0].y + m[2].w * n[0].z + m[3].w * n[0].w;
  r[1].w = m[0].w * n[1].x + m[1].w * n[1].y + m[2].w * n[1].z + m[3].w * n[1].w;
  r[2].w = m[0].w * n[2].x + m[1].w * n[2].y + m[2].w * n[2].z + m[3].w * n[2].w;
  r[3].w = m[0].w * n[3].x + m[1].w * n[3].y + m[2].w * n[3].z + m[3].w * n[3].w;

  return r;
}

mat4 mat4::ortho(float left, float right, float bottom, float top, float z_near, float z_far)
{
  float tx, ty, tz;
  tx = -(right+left)/(right-left);
  ty = -(top+bottom)/(top-bottom);
  tz = -(z_far+z_near)/(z_far-z_near);

  mat4 r = mat4::identity();
  r.elements[0] = 2.0f/(right-left);
  r.elements[5] = 2.0f/(top-bottom);
  r.elements[11] = -2.0f/(z_far-z_near);
  r.elements[12] = tx;
  r.elements[13] = ty;
  r.elements[14] = tz;

  return r;
}

} // namespace gmath
