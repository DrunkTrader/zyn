#include "zyn/cli.hpp"

#include <stdexcept>
#include <string>
#include <iostream>

namespace zyn {
    Options parse_options(
        int argc,
        char* argv[],
        int &first_path
    ) {
        Options opt;
        first_path = 1;
        while (first_path < argc) {
            std::string_view arg{argv[first_path]};

            //end of options.
            if (arg == "--"){
                ++first_path;
                break;
            }

            //first non-option argument.
            if (arg.empty() || arg[0] != '-'){
                break;
            }

            if(arg == "-r"){
                opt.recursive = true;
            }
            else if (arg == "-r")  {
                opt.recursive = true;
            }
            else if (arg == "-f")  {
                opt.force = true;
            }
            else if (arg == "-h")  {
                opt.help = true;
            }
            
            else if ( arg.size() > 1) {
                //support combined opt : -rf, -rh, etc.

                for(const char option_ : arg.substr(1)){
                    switch(option_){
                        case 'r':
                            opt.recursive = true;
                            break;

                        case 'f':
                            opt.force = true;
                            break;

                        case 'h':
                            opt.help = true;
                            break;

                        default:
                            throw std::invalid_argument("unknown option: -" + std::string( 1,option_));
                    }
                }
            }

            ++first_path;
        }
        return opt;
    }

    void print_usage(std::string_view program){
        std::cout
            << "Usage: " << program
            << "[-rfh] <source> <destination>\n\n"

            << "Options:\n"
            << " -r Recursive copy\n"
            << " -f Force overwrite\n"
            << " -h Display this help message\n";
    }
}


  