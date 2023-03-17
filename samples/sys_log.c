#include <cprocess.h>
#include <cfile.h>
#include <libapp.h>
#include <libpath.h>
#include <libstr.h>
#include <string.h>

#include <print.h>

int main()
{
    CStringAuto *homedir = cstr_new_size(64);
    get_homedir(homedir);

    CStringAuto *outpath = cstr_new_size(64);
    path_join(outpath, c_str(homedir), "sys_log.txt");

    const char *cmd = "journalctl -b 0 --no-pager";

    CProcessAuto *process = cprocess_new();
    if (!cprocess_start(process, cmd, CP_PIPEOUT))
    {
        print("start failed");

        return EXIT_FAILURE;
    }

    int status = cprocess_exitstatus(process);

    if (status != 0)
    {
        print("program returned : %d", status);

        return -1;
    }

    CString *buffer = cprocess_outbuff(process);
    char *ptr = cstr_data(buffer);
    char *result;
    int length;

    CFileAuto *outfile = cfile_new();
    if (!cfile_open(outfile, c_str(outpath), "wb"))
        return 1;

    while (str_getlineptr(&ptr, &result, &length))
    {
        result[length] = '\0';

        cfile_writefmt(outfile, "%s\n", result);

        print(result);
    }

    return 0;
}


