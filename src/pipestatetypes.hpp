#include "frame.hpp"

using Color = struct { float b, g, r, a; };
using DepthFrame = Frame<float>;
using EndFrame = Frame<Color>;
using vertex3 = struct { float x, y, z; };
using vertex2 = struct { float x, y; };
using graphic_vertex = struct { vertex3 pos; vertex2 tex; };
using VertexSequence = vertex3*;
using Resolution_type = ResolutionType;
using Indecies = int*;