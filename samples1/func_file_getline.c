#include <cfile.h>
#include <print.h>

int main()
{
    CStringAuto *buffer = cstr_new_size(512);

    if (!file_read(buffer, "/etc/lsb-release"))
        return EXIT_FAILURE;

    const char *ptr = c_str(buffer);
    CStringAuto *line = cstr_new_size(32);

    while (file_getline(&ptr, line))
    {
        print(c_str(line));
    }

    return EXIT_SUCCESS;
}


