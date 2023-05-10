#include <cfile.h>
#include <print.h>

int main()
{
    const char *filepath = "/home/hotnuma/Bureau/Fela.md";

    CFileAuto *file = cfile_new();
    if (!cfile_read(file, filepath))
        return EXIT_FAILURE;

    if (!cfile_open(file, filepath, "wb"))
        return EXIT_FAILURE;

    CStringAuto *line = cstr_new_size(32);
    while (cfile_getline(file, line))
    {
        if (!cstr_endswith(line, "  ", true))
            cstr_append(line, "  ");

        cfile_write(file, c_str(line));
        cfile_write(file, "\n");

        print(c_str(line));
    }

    return EXIT_SUCCESS;
}


