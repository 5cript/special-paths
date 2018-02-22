#include "special_paths.hpp"

#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

namespace SpecialPaths
{
//#####################################################################################################################
    std::string getHome(bool useEnvironment, bool useAppdata)
    {
        if (useEnvironment)
        {
            auto const* homedir = getenv("HOME");
            if (homedir != nullptr)
                return {homedir};
        }

        struct passwd *pw = getpwuid(getuid());
        return {pw->pw_dir};
    }
//---------------------------------------------------------------------------------------------------------------------
//#####################################################################################################################
}
