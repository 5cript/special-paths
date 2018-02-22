#pragma once

#include <string>

namespace SpecialPaths
{
    /**
     *  Retrieve the home path in your operating system.
     *
     *  @param useEnvironment Will try to get the home directory over the HOME environment variable first.
     *  @param useAppdata only relevant for Windows, because programs should use appdata, but
     *         some cross platform applications do not, but instead dump their stuff into the
     *         user directory directly. If you want to be one of THOSE people, go ahead an pass false.
     */
    std::string getHome(bool useEnvironment = true, bool useAppdata = true);
}
