#pragma once

#include <string_view>

namespace zyn {
    
    struct Options {
        bool recursive = false;
        bool force = false;
        bool help = false;
   };

   Options parse_options(
    int argc,
    char* argv[],
    int &first_path
   );

   void print_usage(std::string_view program);
}
