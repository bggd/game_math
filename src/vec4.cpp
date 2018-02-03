namespace gmath {

vec4::vec4() : x(0.0f), y(0.0f), z(0.0f), w(0.0f)
{
}

vec4::vec4(float cx, float cy, float cz, float cw) : x(cx), y(cy), z(cz), w(cw)
{
}

vec4::vec4(vec3 v, float cw) : x(v.x), y(v.y), z(v.z), w(cw)
{
}

} // namespace gmath
