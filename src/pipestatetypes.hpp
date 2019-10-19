#include "frame/frame.hpp"

struct Color
{
    float b, g, r, a;
    Color (float b, float, g, float r, float a)
    : b(b), g(g), r(r), a(a) {}
};

struct Vertex3
{
    float x, y, z;
    Vertex3(float x, float y, float z)
    : x(x), y(y), z(z) {}
};

struct Vertex2
{
    float x, y;
    Vertex3(float x, float y)
    : x(x), y(y) {}
};

struct GraphicVertex
{
    Vertex3 pos;
    Vertex2 tex;
};

using DepthFrame = Frame<float>;
using EndFrame = Frame<Color>;
using VertexSequence = vertex3*;
using Resolution_type = ResolutionType;
using Indecies = int*;