#include <cfile.h>
#include <print.h>

#define START "<editsection "   // 13
#define END "</editsection>"    // 14

static int _app_exit(bool usage, int ret)
{
    if (usage)
    {
        print("*** usage");
        print("testcmd \"filepath\"");
    }

    return ret;
}

int main(int argc, char **argv)
{
    if (argc < 2)
        return _app_exit(true, EXIT_FAILURE);

    const char *filepath = argv[1];

    print("%s", filepath);

    CFileAuto *file = cfile_new();

    if (!cfile_read(file, filepath))
        return 1;

    char *p = cfile_data(file);

    if (!p)
        return 1;

    CStringAuto *outbuff = cstr_new_size(strlen(p) + 1);
    bool remove = false;

    while (*p != '\0')
    {
        if (remove == false)
        {
            if (strncmp(p, START, 13) == 0)
            {
                remove = true;
                p += 13;
                continue;
            }

            cstr_append_c(outbuff, *p);

            ++p;
        }
        else if (remove == true)
        {
            if (strncmp(p, END, 14) == 0)
            {
                remove = false;
                p += 14;
                continue;
            }

            ++p;
        }
    }

    if (!cfile_open(file, filepath, "wb"))
        return EXIT_FAILURE;

    cfile_write(file, c_str(outbuff));

    return 0;
}


