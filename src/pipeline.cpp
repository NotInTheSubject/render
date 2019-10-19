#include "pipeline.hpp"
#include "pipestate.hpp"

void Pipeline::set_config(Pipeline::config_type const* cfg) {
    if (cfg == nullptr) {
        throw std::runtime_error("The pointer to a pipeline-config is NULL.");
    }
    config = cfg;

    operator delete[](state_storage);
    state_storage = operator new[](sizeof(void*) * cfg->size(), std::nothrow);
    if (state_storage == nullptr) {
        throw std::runtime_error("Cannot allocate memory for the pipeline-config state");
    }

    Pipestate& pipe_state = represent_as_state(state_storage);
    for ( auto const& [k, v] : *cfg) {
        switch (k)
        {
        case CONFIGTYPE::DEPTH_FRAME:
            pipe_state.depthBuffer = std::any_cast<DepthFrame*>(v);
            assert (pipe_state.depthBuffer != nullptr);
            break;

        case CONFIGTYPE::ENDFRAME:
            pipe_state.endFrame = std::any_cast<EndFrame*>(v);
            assert (pipe_state.endFrame != nullptr);
            break;

        case CONFIGTYPE::VERTEX_SEQUENCE:
            pipe_state.vertexSequence = std::any_cast<VertexSequence*>(v);
            assert (pipe_state.vertexSequence != nullptr);
            break;

        case CONFIGTYPE::INDEX_SEQUENCE:
            pipe_state.incs = std::any_cast<Indecies*>(v);
            assert (pipe_state.incs != nullptr);
            break;

        case CONFIGTYPE::RESOLUTION_FOR_DRAWING:
            pipe_state.resolution = std::any_cast<Resolution_type*>(v);
            assert (pipe_state.resolution != nullptr);
            break;
        
        default:
            break;
        }
    }
}

Pipeline::config_type const&
Pipeline::get_config() const noexcept {
    assert (config != nullptr);
    return *config;
}

bool
Pipeline::is_full_conf() const noexcept {
    assert (state_storage != nullptr);
    return represent_as_state(state_storage).is_valid_state();
}

void
Pipeline::dump(std::ostream& out) const {
    assert (state_storage != nullptr);
    return represent_as_state(state_storage).dump(out);
}

Pipeline::Pipeline() noexcept
: state_storage(nullptr)
, config(nullptr) {}

Pipeline::Pipeline(Pipeline::config_type const* cfg)
: Pipeline::Pipeline()
{
    Pipeline::set_config(cfg);
}

Pipeline::~Pipeline()
{
    operator delete[](state_storage);
    state_storage = nullptr;
    config = nullptr;
}