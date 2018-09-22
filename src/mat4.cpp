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

  r[0].x = (a[0].x * b[0].x) + (a[1].x * b[0].y) + (a[2].x * b[0].z) + (a[3].x * b[0].w);
  r[1].x = (a[0].x * b[1].x) + (a[1].x * b[1].y) + (a[2].x * b[1].z) + (a[3].x * b[1].w);
  r[2].x = (a[0].x * b[2].x) + (a[1].x * b[2].y) + (a[2].x * b[2].z) + (a[3].x * b[2].w);
  r[3].x = (a[0].x * b[3].x) + (a[1].x * b[3].y) + (a[2].x * b[3].z) + (a[3].x * b[3].w);

  r[0].y = (a[0].y * b[0].x) + (a[1].y * b[0].y) + (a[2].y * b[0].z) + (a[3].y * b[0].w);
  r[1].y = (a[0].y * b[1].x) + (a[1].y * b[1].y) + (a[2].y * b[1].z) + (a[3].y * b[1].w);
  r[2].y = (a[0].y * b[2].x) + (a[1].y * b[2].y) + (a[2].y * b[2].z) + (a[3].y * b[2].w);
  r[3].y = (a[0].y * b[3].x) + (a[1].y * b[3].y) + (a[2].y * b[3].z) + (a[3].y * b[3].w);

  r[0].z = (a[0].z * b[0].x) + (a[1].z * b[0].y) + (a[2].z * b[0].z) + (a[3].z * b[0].w);
  r[1].z = (a[0].z * b[1].x) + (a[1].z * b[1].y) + (a[2].z * b[1].z) + (a[3].z * b[1].w);
  r[2].z = (a[0].z * b[2].x) + (a[1].z * b[2].y) + (a[2].z * b[2].z) + (a[3].z * b[2].w);
  r[3].z = (a[0].z * b[3].x) + (a[1].z * b[3].y) + (a[2].z * b[3].z) + (a[3].z * b[3].w);

  r[0].w = (a[0].w * b[0].x) + (a[1].w * b[0].y) + (a[2].w * b[0].z) + (a[3].w * b[0].w);
  r[1].w = (a[0].w * b[1].x) + (a[1].w * b[1].y) + (a[2].w * b[1].z) + (a[3].w * b[1].w);
  r[2].w = (a[0].w * b[2].x) + (a[1].w * b[2].y) + (a[2].w * b[2].z) + (a[3].w * b[2].w);
  r[3].w = (a[0].w * b[3].x) + (a[1].w * b[3].y) + (a[2].w * b[3].z) + (a[3].w * b[3].w);

  return r;
}

mat4 mat4::translate(vec3 position)
{
  return {
    vec4(1.0f, 0.0f, 0.0f, 0.0f),
    vec4(0.0f, 1.0f, 0.0f, 0.0f),
    vec4(0.0f, 0.0f, 1.0f, 0.0f),
    vec4(position, 1.0f)
  };
}

mat4 mat4::rotate(float angle, vec3 axis)
{
  float c = cosf(angle);
  float s = sinf(angle);
  float t = 1.0f - c;
  return {
    vec4(axis.x*axis.x*t + c,        axis.y*axis.x*t + axis.z*s, axis.x*axis.z*t - axis.y*s, 0.0f),
    vec4(axis.x*axis.y*t - axis.z*s, axis.y*axis.y*t + c,        axis.y*axis.z*t + axis.x*s, 0.0f),
    vec4(axis.x*axis.z*t + axis.y*s, axis.y*axis.z*t - axis.x*s, axis.z*axis.z*t + c,        0.0f),
    vec4(0.0f, 0.0f, 0.0f, 1.0f)
  };
}

mat4 mat4::transpose(const mat4& m)
{
  return {
    vec4(m[0].x, m[1].x, m[2].x, m[3].x),
    vec4(m[0].y, m[1].y, m[2].y, m[3].y),
    vec4(m[0].z, m[1].z, m[2].z, m[3].z),
    vec4(m[0].w, m[1].w, m[2].w, m[3].w)
  };
}

mat4 mat4::perspective(float y_fov, float aspect, float z_near, float z_far)
{
  float f = 1.0f/tanf(0.5*y_fov);
  return {
    vec4(f/aspect, 0.0f, 0.0f, 0.0f),
    vec4(0.0f, f, 0.0f, 0.0f),
    vec4(0.0f, 0.0f, (z_far+z_near)/(z_near-z_far), -1.0f),
    vec4(0.0f, 0.0f, (2.0f*z_far*z_near)/(z_near-z_far), 0.0f)
  };
}

mat4 mat4::ortho(float left, float right, float bottom, float top, float z_near, float z_far)
{
  float tx, ty, tz;
  tx = -((right+left)/(right-left));
  ty = -((top+bottom)/(top-bottom));
  tz = -((z_far+z_near)/(z_far-z_near));

  mat4 r = mat4::identity();
  r.elements[0] = 2.0f/(right-left);
  r.elements[5] = 2.0f/(top-bottom);
  r.elements[10] = -2.0f/(z_far-z_near);
  r.elements[12] = tx;
  r.elements[13] = ty;
  r.elements[14] = tz;

  return r;
}

mat4 mat4::look_at(vec3 position, vec3 target, vec3 up)
{
  vec3 camera_forward = vec3::sub(position, target);
  camera_forward = vec3::normalize(camera_forward);

  vec3 camera_side = vec3::cross(up, camera_forward);
  camera_side = vec3::normalize(camera_side);

  vec3 camera_up = vec3::cross(camera_forward, camera_side);

  // Transposed rotation
  mat4 view(
    vec4(camera_side.x, camera_up.x, camera_forward.x, 0.0f),
    vec4(camera_side.y, camera_up.y, camera_forward.y, 0.0f),
    vec4(camera_side.z, camera_up.z, camera_forward.z, 0.0f),
    vec4(-vec3::dot(camera_side, position), -vec3::dot(camera_up, position), -vec3::dot(camera_forward, position), 1.0f)
  );

  return view;
}

vec4 mat4::xform(const mat4& m, vec4 v)
{
  vec4 r;
  r.x = (m[0].x * v.x) + (m[1].x * v.y) + (m[2].x * v.z) + (m[3].x * v.w);
  r.y = (m[0].y * v.x) + (m[1].y * v.y) + (m[2].y * v.z) + (m[3].y * v.w);
  r.z = (m[0].z * v.x) + (m[1].z * v.y) + (m[2].z * v.z) + (m[3].z * v.w);
  r.w = (m[0].w * v.x) + (m[1].w * v.y) + (m[2].w * v.z) + (m[3].w * v.w);
  return r;
}

} // namespace gmath
