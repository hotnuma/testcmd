#include <cfile.h>

#include <print.h>

int main()
{
    const char *filepath = "/etc/lsb-release";

    CFileAuto *file = cfile_new();

    if (!cfile_read(file, filepath))
        return 1;

    CStringAuto *line = cstr_new_size(32);

    while (cfile_getline(file, line))
    {
        print(c_str(line));
    }

    return 0;
}


