#include "zyn/cli.hpp"
#include "zyn/copier.hpp"

#include <filesystem>
#include <iostream>
#include <vector>

namespace fs = std::filesystem;

int main(int argc, char*  argv[]){
    try {
        int first_path = 1;

        const auto options = zyn::parse_options(
            argc,
            argv,
            first_path
        );

        if (options.help){
            zyn::print_usage(argv[0]);
            return 0;
        }

        const int path_count = argc - first_path;

        if(path_count < 2) {
            std::cerr <<  "Error :  Missing source or destination\n\n";

            zyn::print_usage(argv[0]);
            return  1;
        }

        const fs::path  destination = argv[argc - 1];
        std::vector<fs::path> sources;

        sources.reserve(path_count - 1);

        for(int i = first_path; i < argc - 1; ++i){
            sources.emplace_back(argv[i]);
        }

        //one source
        if(sources.size() == 1){
            zyn::zyn_path(
                sources.front(),
                destination,
                options
            );
            return 0;
        }

        //multiple sources
        if(!fs::exists(destination)){
            throw std::runtime_error("Destination directory does not exist: " + destination.string());
        }


        if(!fs::is_directory(destination)){
            throw std::runtime_error("Destination must be a directory.");
        }

        for (const auto &source : sources) {
            const auto destination_path = destination / source.filename();
        
            zyn::zyn_path(source, destination_path, options);
        }
        return 0;
    }
    catch (const fs::filesystem_error &e) {
        std::cerr
            << "Filesystem error: "
            << e.what()
            << '\n';

            return 1;
    }

    catch (const std::exception &e) {
        std::cerr
        <<  "Error: "
        << e.what()
        << '\n';
    
        return 1;
    }
}