#include "lib/CProcess.h"

#include "print.h"

int main()
{
    CString cmd = "ls -la";

    CProcess process;
    if (!process.start(cmd, PF_PIPEOUT))
        return 1;

    if (process.exitStatus() != 0)
        return 1;

    print(process.outBuff);

    return 0;
}


