#include <cfile.h>
#include <print.h>

int main()
{
    const char *filepath = "/etc/lsb-release";
    CFileAuto *file = cfile_new();

    if (!cfile_read(file, filepath))
        return 1;

    const char *ptr = cfile_data(file);
    CStringAuto *line = cstr_new_size(32);

    while (file_getline(&ptr, line))
    {
        print(c_str(line));
    }

    return 0;
}


