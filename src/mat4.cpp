gmath::Mat4 gmath::mat4::mul(const gmath::Mat4& A, const gmath::Mat4& B)
{
  gmath::Mat4 ret;

  ret.m00 = A.m00*B.m00 + A.m04*B.m01 + A.m08*B.m02 + A.m12*B.m03;
  ret.m01 = A.m01*B.m00 + A.m05*B.m01 + A.m09*B.m02 + A.m13*B.m03;
  ret.m02 = A.m02*B.m00 + A.m06*B.m01 + A.m10*B.m02 + A.m14*B.m03;
  ret.m03 = A.m03*B.m00 + A.m07*B.m01 + A.m11*B.m02 + A.m15*B.m03;

  ret.m04 = A.m00*B.m04 + A.m04*B.m05 + A.m08*B.m06 + A.m12*B.m07;
  ret.m05 = A.m01*B.m04 + A.m05*B.m05 + A.m09*B.m06 + A.m13*B.m07;
  ret.m06 = A.m02*B.m04 + A.m06*B.m05 + A.m10*B.m06 + A.m14*B.m07;
  ret.m07 = A.m03*B.m04 + A.m07*B.m05 + A.m11*B.m06 + A.m15*B.m07;

  ret.m08 = A.m00*B.m08 + A.m04*B.m09 + A.m08*B.m10 + A.m12*B.m11;
  ret.m09 = A.m01*B.m08 + A.m05*B.m09 + A.m09*B.m10 + A.m13*B.m11;
  ret.m10 = A.m02*B.m08 + A.m06*B.m09 + A.m10*B.m10 + A.m14*B.m11;
  ret.m11 = A.m03*B.m08 + A.m07*B.m09 + A.m11*B.m10 + A.m15*B.m11;

  ret.m12 = A.m00*B.m12 + A.m04*B.m13 + A.m08*B.m14 + A.m12*B.m15;
  ret.m13 = A.m01*B.m12 + A.m05*B.m13 + A.m09*B.m14 + A.m13*B.m15;
  ret.m14 = A.m02*B.m12 + A.m06*B.m13 + A.m10*B.m14 + A.m14*B.m15;
  ret.m15 = A.m03*B.m12 + A.m07*B.m13 + A.m11*B.m14 + A.m15*B.m15;

  return ret;
}

gmath::Mat4 gmath::mat4::ortho(float left, float right, float bottom, float top, float z_near, float z_far)
{
  float tx, ty, tz;
  tx = -(right+left)/(right-left);
  ty = -(top+bottom)/(top-bottom);
  tz = -(z_far+z_near)/(z_far-z_near);

  gmath::Mat4 ret;
  ret.m00 = 2.0f/(right-left);
  ret.m05 = 2.0f/(top-bottom);
  ret.m11 = -2.0f/(z_far-z_near);
  ret.m12 = tx;
  ret.m13 = ty;
  ret.m14 = tz;

  return ret;
}
