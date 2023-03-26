#include <cfile.h>
#include <libstr.h>
#include <print.h>

int main()
{
    const char *filepath = "/etc/lsb-release";
    CFileAuto *file = cfile_new();

    if (!cfile_read(file, filepath))
        return 1;

    char *ptr = cfile_data(file);
    char *result;
    int length;

    while (str_getlineptr(&ptr, &result, &length))
    {
        result[length] = '\0';
        print(result);
    }

    return 0;
}


