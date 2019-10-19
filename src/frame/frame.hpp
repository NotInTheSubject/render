#pragma once

struct ResolutionType 
{
    int x, y;
    ResolutionType(int x, int y) noexcept
    : x(x)
    , y(y) {}
};


template<typename T>
class Frame
{
public:
using value_type = T;
using pointer = T*;
using resolution_type = ResolutionType;
private:
    value_type* data;
    resolution_type resolution;
public:
    Frame  (resolution_type const&);
    Frame  () noexcept;
    ~Frame ();

    void set_resolution(resolution_type const&);
    resolution_type get_resolution() const noexcept;

    const pointer get_data() const noexcept;
    pointer operator[](int ind) noexcept;
};

#include "frame.inl"