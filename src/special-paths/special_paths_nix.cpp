#include <special-paths/special_paths.hpp>

#include <unistd.h>
#include <sys/types.h>
#include <pwd.h>

namespace SpecialPaths
{
//#####################################################################################################################
    std::filesystem::path getHome(bool useEnvironment, bool useAppdata)
    {
        if (useEnvironment)
        {
            auto const* homedir = getenv("HOME");
            if (homedir != nullptr)
                return {homedir};
        }

        struct passwd *pw = getpwuid(getuid());
        if (pw != nullptr)
        {
            return {pw->pw_dir};
        }
        return std::filesystem::path{};
    }
//---------------------------------------------------------------------------------------------------------------------
//#####################################################################################################################
}
