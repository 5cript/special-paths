#include "special_paths.hpp"
#include <shlobj.h>
#include <stdexcept>

namespace SpecialPaths
{
//#####################################################################################################################
    std::string getHome(bool useEnvironment, bool useAppdata)
    {
        auto cslid = CSIDL_APPDATA;
        if (!useAppdata)
            cslid = CSIDL_PROFILE;

        char profilePath[MAX_PATH];
        HRESULT result = SHGetFolderPath(NULL, cslid, NULL, 0, profilePath);
        if (SUCCEEDED(result))
            return {profilePath};
        else
            throw std::runtime_error("Could not get folder path - windows error code: " + std::to_string(result));
    }
//#####################################################################################################################
}
