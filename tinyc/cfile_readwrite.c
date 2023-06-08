#include <cfile.h>
#include <print.h>

int main()
{
    const char *inpath = "/etc/lsb-release";
    const char *outpath = "/tmp/result.txt";

    CFileAuto *file = cfile_new();
    if (!cfile_read(file, inpath))
        return EXIT_FAILURE;

    if (!cfile_open(file, outpath, "wb"))
        return EXIT_FAILURE;

    CStringAuto *line = cstr_new_size(32);
    while (cfile_getline(file, line))
    {
        cfile_write(file, c_str(line));
        cfile_write(file, "\n");

        print(c_str(line));
    }

    return EXIT_SUCCESS;
}


