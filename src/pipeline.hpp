#pragma once
#include <map>
#include <any>
#include <ostream>

enum class CONFIGTYPE {
    DEPTH_FRAME,
    ENDFRAME,
    RESOLUTION_FOR_DRAWING,
};

class Pipeline
{
public:
    using config_type = std::map<CONFIGTYPE, std::any>;

private:
    void *state;
    config_type const* config;
public:
    Pipeline(config_type const*);
    Pipeline() noexcept;
    ~Pipeline();

    bool is_full_conf() noexcept;
    void dump(std::ostream&);

    void run_process() noexcept;
    void set_config(config_type const*);
    config_type const* get_config() noexcept;
};

