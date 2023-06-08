#include <cfile.h>
#include <print.h>

int main()
{
    CStringAuto *cmdline = cstr_new_size(128);

    if (!file_read(cmdline, "/proc/self/cmdline"))
        return EXIT_FAILURE;

    char *ptr = cstr_data(cmdline);
    int size = cstr_size(cmdline);
    for (int i = 0; i < size; ++i)
    {
        if (ptr[i] == '\0')
            ptr[i] = '|';
    }

    print("%s size = %d", c_str(cmdline), cstr_size(cmdline));

    return EXIT_SUCCESS;
}


