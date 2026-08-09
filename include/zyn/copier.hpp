#pragma once 

#include <filesystem>
#include <stdexcept>
#include <zyn/cli.hpp>

namespace zyn {

    void zyn_path(
        const std::filesystem::path &source,
        const std::filesystem::path &destination,
        const Options &options1
    );
}