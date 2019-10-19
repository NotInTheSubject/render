#pragma once

#include "frame.hpp"
#include "pipestatetypes.hpp"

#include <ostream>

struct Pipestate
{
    DepthFrame*     depthBuffer = nullptr;
    EndFrame*       endFrame    = nullptr;
    VertexSequence* vertexSequence = nullptr;
    Indecies*       incs        = nullptr;
    Resolution_type*resolution  = nullptr;
    

    bool is_valid_state() const noexcept {
        return (depthBuffer != nullptr)
            && (endFrame    != nullptr)
            && (vertexSequence != nullptr)
            && (incs        != nullptr)
            && (resolution  != nullptr);
    }

    void dump(std::ostream& out) const {
        out << "------------------------\n";
        out << "Pipestate dump\n";
        out << "------------------------\n";
        out << "DepthFrame*     : " << (void*)depthBuffer << '\n'; 
        out << "EndFrame*       : " << (void*)endFrame    << '\n';
        out << "VertexSequence* : " << (void*)vertexSequence << '\n';
        out << "Indecies*       : " << (void*)incs        << '\n';
        out << "Resolution_type*: " << (void*)resolution  << '\n';
        out << "------------------------\n";
        out.flush();
    }
};

Pipestate& represent_as_state(void* ptr) noexcept {
    assert(ptr != nullptr);
    return *static_cast<Pipestate*>(ptr);
}
