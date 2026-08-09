#include <zyn/copier.hpp>
#include <filesystem>
#include <stdexcept>

namespace fs = std::filesystem;

namespace zyn {
    void zyn_path(
        const fs::path &source,
        const fs::path &destination,
        const Options &options1
    )

    {
        if(!fs::exists(source)) {
            throw std::runtime_error(
                "source does not exist: " + source.string()
            );
        }

        fs::copy_options copy_options = fs::copy_options::none;

        if(options1.force) {
            copy_options  |= fs::copy_options::overwrite_existing;
        }

        if (options1.recursive){
            copy_options |= fs::copy_options::recursive;
        }

        fs::copy(source,destination, copy_options);
    }
}