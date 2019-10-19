#pragma once

#include "pipestatetypes.hpp"

#include <ostream>

struct PipeStateBase
{
    DepthFrame*     depthBuffer = nullptr;
    EndFrame*       endFrame    = nullptr;
    VertexSequence* vertexSequence = nullptr;
    Indecies*       incs        = nullptr;
    Resolution_type*resolution  = nullptr;
    

    virtual
    bool is_valid_state() const noexcept {
        return (depthBuffer != nullptr)
            && (endFrame    != nullptr)
            && (vertexSequence != nullptr)
            && (incs        != nullptr)
            && (resolution  != nullptr);
    }

    virtual
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

