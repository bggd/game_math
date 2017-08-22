namespace gmath {

mat4 mat4::mul(const mat4& left, const mat4& right)
{
  const float* A = left.elements;
  const float* B = right.elements;

  mat4 ret = {
    A[0]*B[0] + A[4]*B[1] + A[8]*B[2] + A[12]*B[3],
    A[1]*B[0] + A[5]*B[1] + A[9]*B[2] + A[13]*B[3],
    A[2]*B[0] + A[6]*B[1] + A[10]*B[2] + A[14]*B[3],
    A[3]*B[0] + A[7]*B[1] + A[11]*B[2] + A[15]*B[3],

    A[0]*B[4] + A[4]*B[5] + A[8]*B[6] + A[12]*B[7],
    A[1]*B[4] + A[5]*B[5] + A[9]*B[6] + A[13]*B[7],
    A[2]*B[4] + A[6]*B[5] + A[10]*B[6] + A[14]*B[7],
    A[3]*B[4] + A[7]*B[5] + A[11]*B[6] + A[15]*B[7],

    A[0]*B[8] + A[4]*B[9] + A[8]*B[10] + A[12]*B[11],
    A[1]*B[8] + A[5]*B[9] + A[9]*B[10] + A[13]*B[11],
    A[2]*B[8] + A[6]*B[9] + A[10]*B[10] + A[14]*B[11],
    A[3]*B[8] + A[7]*B[9] + A[11]*B[10] + A[15]*B[11],

    A[0]*B[12] + A[4]*B[13] + A[8]*B[14] + A[12]*B[15],
    A[1]*B[12] + A[5]*B[13] + A[9]*B[14] + A[13]*B[15],
    A[2]*B[12] + A[6]*B[13] + A[10]*B[14] + A[14]*B[15],
    A[3]*B[12] + A[7]*B[13] + A[11]*B[14] + A[15]*B[15]
  };

  return ret;
}

mat4 mat4::ortho(float left, float right, float bottom, float top, float z_near, float z_far)
{
  float tx, ty, tz;
  tx = -(right+left)/(right-left);
  ty = -(top+bottom)/(top-bottom);
  tz = -(z_far+z_near)/(z_far-z_near);

  mat4 ret;
  ret.elements[0] = 2.0f/(right-left);
  ret.elements[5] = 2.0f/(top-bottom);
  ret.elements[11] = -2.0f/(z_far-z_near);
  ret.elements[12] = tx;
  ret.elements[13] = ty;
  ret.elements[14] = tz;

  return ret;
}

} // namespace gmath
