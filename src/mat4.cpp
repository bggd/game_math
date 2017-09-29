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

mat4 mat4::mul(const mat4& a, const mat4& b)
{
  mat4 r;

  r[0].x = a[0].x * b[0].x + a[1].x * b[0].y + a[2].x * b[0].z + a[3].x * b[0].w;
  r[1].x = a[0].x * b[1].x + a[1].x * b[1].y + a[2].x * b[1].z + a[3].x * b[1].w;
  r[2].x = a[0].x * b[2].x + a[1].x * b[2].y + a[2].x * b[2].z + a[3].x * b[2].w;
  r[3].x = a[0].x * b[3].x + a[1].x * b[3].y + a[2].x * b[3].z + a[3].x * b[3].w;

  r[0].y = a[0].y * b[0].x + a[1].y * b[0].y + a[2].y * b[0].z + a[3].y * b[0].w;
  r[1].y = a[0].y * b[1].x + a[1].y * b[1].y + a[2].y * b[1].z + a[3].y * b[1].w;
  r[2].y = a[0].y * b[2].x + a[1].y * b[2].y + a[2].y * b[2].z + a[3].y * b[2].w;
  r[3].y = a[0].y * b[3].x + a[1].y * b[3].y + a[2].y * b[3].z + a[3].y * b[3].w;

  r[0].z = a[0].z * b[0].x + a[1].z * b[0].y + a[2].z * b[0].z + a[3].z * b[0].w;
  r[1].z = a[0].z * b[1].x + a[1].z * b[1].y + a[2].z * b[1].z + a[3].z * b[1].w;
  r[2].z = a[0].z * b[2].x + a[1].z * b[2].y + a[2].z * b[2].z + a[3].z * b[2].w;
  r[3].z = a[0].z * b[3].x + a[1].z * b[3].y + a[2].z * b[3].z + a[3].z * b[3].w;

  r[0].w = a[0].w * b[0].x + a[1].w * b[0].y + a[2].w * b[0].z + a[3].w * b[0].w;
  r[1].w = a[0].w * b[1].x + a[1].w * b[1].y + a[2].w * b[1].z + a[3].w * b[1].w;
  r[2].w = a[0].w * b[2].x + a[1].w * b[2].y + a[2].w * b[2].z + a[3].w * b[2].w;
  r[3].w = a[0].w * b[3].x + a[1].w * b[3].y + a[2].w * b[3].z + a[3].w * b[3].w;

  return r;
}

mat4 mat4::perspective(float y_fov, float aspect, float z_near, float z_far)
{
  float f = tanf(0.5f*y_fov);
  return {
    vec4(1.0f/aspect*f, 0.0f, 0.0f, 0.0f),
    vec4(0.0f, 1.0f/f, 0.0f, 0.0f),
    vec4(0.0f, 0.0f, z_far+z_near/z_near-z_far, -1.0f),
    vec4(0.0f, 0.0f, 2*z_far*z_near/z_near-z_far, 0.0f)
  };
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
