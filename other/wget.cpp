#include "print.h"
#include "libutils.h"

#include "CProcess.h"
#include "libutils.h"

bool wget(const char *url, CString &result, const char *options)
{
    CString cmd = "wget.exe";

    if (options && *options)
    {
        cmd += " ";
        cmd += options;
    }

    cmd += " --no-check-certificate -qO - ";
    cmd += url;

    CProcess process;
    if (!process.start(cmd, PF_PIPEOUT))
        return false;

    if (process.exitStatus() != 0)
        return false;

    result = process.outBuff;

    return true;
}

int main()
{
    CString result;
    wget("https://www.google.com/", result);

    print(result);

    return 0;
}


