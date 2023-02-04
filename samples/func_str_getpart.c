#include <cfile.h>
#include <libstr.h>
#include <print.h>

int main()
{
    const char *filepath = "/home/hotnuma/dev_installed.txt";

    CFileAuto *file = cfile_new();

    if (!cfile_read(file, filepath))
        return 1;

    CStringAuto *line = cstr_new_size(32);

    while (cfile_getline(file, line))
    {
        char *start = c_str(line);
        print(start);

        int count = 0;
        char *result;
        int len;

        while (str_getpart(&start, &result, &len))
        {
            if (++count == 5)
            {
                print(result);
                break;
            }

            result[len] = '\0';
            print(result);
        }
    }

    return 0;
}


