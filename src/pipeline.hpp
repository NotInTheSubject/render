#pragma once
#include <map>
#include <any>
#include <ostream>

enum class CONFIGTYPE {
    DEPTH_FRAME,
    ENDFRAME,
    RESOLUTION_FOR_DRAWING,
    VERTEX_SEQUENCE,
    INDEX_SEQUENCE
};
/**
 * Pipeline class. The constructor and the set_config take
 * as arguments pointers to the corresponding values CONFIGTYPE
 * 
 * If content of a config is enough to processing is_full_conf()
 * returns TRUE. Otherwise, a dump() will help showing what is 
 * received and what is missing.
 */
class Pipeline
{
public:
    using config_type = std::map<CONFIGTYPE, std::any>;

private:
    void *state_storage;
    config_type const* config;
public:
    Pipeline(config_type const*);
    Pipeline() noexcept;
    ~Pipeline();

    bool is_full_conf() const noexcept;
    void dump(std::ostream&) const;

    void run_process() noexcept;
    void set_config(config_type const*);
    config_type const& get_config() const noexcept;
};

