#include "pipeline.hpp"
#include "pipestate.hpp"

extern void run_pipeline(PipeStateBase& state) noexcept;

void Pipeline::set_config(Pipeline::config_type const* cfg) {
    config = cfg;
}

Pipeline::config_type const&
Pipeline::get_config() const noexcept {
    assert (config != nullptr);
    return *config;
}

bool
Pipeline::is_full_conf() const noexcept {
    assert (config != nullptr);
    return config->is_valid_state();
}

void
Pipeline::dump(std::ostream& out) const {
    assert (config != nullptr);
    return config->dump(out);
}

Pipeline::Pipeline() noexcept
: config(nullptr) {}

Pipeline::Pipeline(Pipeline::config_type const* cfg)
: Pipeline::Pipeline()
{
    Pipeline::set_config(cfg);
}

Pipeline::~Pipeline()
{
    config = nullptr;
}

void 
Pipeline::run_process() noexcept {
    assert(config != nullptr);
    run_pipeline(*config);
    return;
}