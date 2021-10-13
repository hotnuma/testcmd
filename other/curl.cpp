#include "CString.h"
#include "CProcess.h"

#include "print.h"

bool curl(const char *url, CString &result,
          const char *options = nullptr);

bool curl(const char *url, CString &result, const char *options)
{
    CString cmd(120);

    cmd += "curl.exe -k ";

    if (options && *options)
    {
        cmd += " ";
        cmd += options;
    }

    cmd += url;

    //print(cmd);

    CProcess process;
    if (!process.start(cmd, PF_PIPEOUT))
        return false;

    result.swap(process.outBuff);

    //print("result : %d", result.size());

    return true;
}

int main()
{
    CString result;

    curl("https://www.example.com", result);

    print(result.c_str());

    return 0;
}


