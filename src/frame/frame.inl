#include "frame.hpp"
#include <cassert>

template<typename T>
Frame<T>::Frame() noexcept 
: data(nullptr)
, resolution(0, 0)
{}

template<typename T>
Frame<T>::Frame(resolution_type const& resol)
: Frame()
{
    set_resolution(resol);
}

template<typename T>
void Frame<T>::set_resolution(resolution_type const& not_current_resolution) {
    if (data == nullptr) {
        delete[] data;
        data = nullptr;
    }
    data = new T[not_current_resolution.x * not_current_resolution.y];
    resolution = not_current_resolution;
}

template<typename T>
typename
Frame<T>::resolution_type Frame<T>::get_resolution() const noexcept {
    return resolution;
}

template<typename T>
const 
typename Frame<T>::pointer Frame<T>::get_data() const noexcept {
    return data;
}

template<typename T>
typename
Frame<T>::pointer Frame<T>::operator[](int y_ind) noexcept {
    assert((y_ind >= 0) && (y_ind <= resolution.y));
    return data + (resolution.y - y_ind ) * resolution.x;
}