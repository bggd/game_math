namespace gmath {

vec3::vec3() : x(0.0f), y(0.0f), z(0.0f)
{
}

vec3::vec3(float cx, float cy, float cz) : x(cx), y(cy), z(cz)
{
}

vec3 vec3::add(vec3 a, vec3 b)
{
  return { a.x+b.x, a.y+b.y, a.z+b.z };
}

vec3 vec3::sub(vec3 a, vec3 b)
{
  return { a.x-b.x, a.y-b.y, a.z-b.z };
}

vec3 vec3::mul(vec3 a, vec3 b)
{
  return { a.x*b.x, a.y*b.y, a.z*b.z };
}

float vec3::length(vec3 v)
{
  return sqrtf(vec3::dot(v, v));
}

vec3 vec3::normalize(vec3 v)
{
  float len;
  len = 1.0f/vec3::length(v);
  return { v.x*len, v.y*len, v.z*len };
}

float vec3::dot(vec3 a, vec3 b)
{
  return a.x*b.x+a.y*b.y+a.z*b.z;
}

vec3 vec3::cross(vec3 a, vec3 b)
{
  return {
    a.y*b.z-a.z*b.y,
    a.z*b.x-a.x*b.z,
    a.x*b.y-a.y*b.x
  };
}

} // namespace gmath
