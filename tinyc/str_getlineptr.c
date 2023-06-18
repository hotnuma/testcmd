#include <cfile.h>
#include <libstr.h>
#include <print.h>

int main()
{
    CStringAuto *buffer = cstr_new_size(512);

    if (!file_read(buffer, "/etc/lsb-release"))
        return EXIT_FAILURE;

    char *ptr = c_str(buffer);
    char *result;
    int length;

    while (str_getlineptr(&ptr, &result, &length))
    {
        result[length] = '\0';
        print(result);
    }

    return EXIT_SUCCESS;
}


