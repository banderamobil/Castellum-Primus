// System definition files.
//
#include <stdexcept>

// Common definition files.
//
#include "Toolkit/Report.h"

// Local definition files.
//
#include "Primus/Kernel.hpp"

int
main(void)
{
    try
    {
        Workspace::Kernel& kernel = Workspace::Kernel::InitInstance();

        kernel.activateSysLog(Workspace::Local0, Workspace::Debug, "primus");

        kernel.daemonize(Workspace::RootPath);

        kernel.run();
    }
    catch (std::exception& exception)
    {
        ReportWarning("[Main] Exception: %s", exception.what());
    }

    return EXIT_SUCCESS;
}
