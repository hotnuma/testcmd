#include <cprocess.h>

#include <print.h>

int main()
{
    const char *cmd = "ls -la";

    CProcessAuto *process = cprocess_new();
    if (!cprocess_start(process, cmd, CP_PIPEOUT))
    {
        print("start failed");

        return -1;
    }

    int status = cprocess_exitstatus(process);

    if (status != 0)
    {
        print("program returned : %d", status);

        return -1;
    }

    CString *result = cprocess_outbuff(process);

    print(c_str(result));

    return 0;
}


