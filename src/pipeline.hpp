#pragma once
#include <map>
#include "frame_types.hpp"

class Pipeline
{
public:
    using config_type = std::map<std::string, void*>;

private:
    void *state;
    config_type const* config;
public:
    Pipeline(config_type const*);
    Pipeline() noexcept;
    ~Pipeline();

    void run_process() noexcept;
    void set_config(config_type const*);
    config_type const* get_config() noexcept;
};

