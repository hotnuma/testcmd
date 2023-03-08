#include <cdirparser.h>
#include <cstringlist.h>
#include <libstr.h>
#include <stdio.h>
#include <string.h>

#include <print.h>

#define STATE_RUNNING "state: RUNNING"
#define PART_POS 19

bool is_running(const char *filepath)
{
    size_t size = 14; // state: RUNNING
    char buff[size + 1];
    buff[0] = '\0';

    FILE *fp = fopen(filepath, "rb");
    if (!fp)
        return false;

    size_t nb = fread(buff, 1, size, fp);
    if (nb > 0)
    {
        buff[nb] = '\0';

        if (strncmp(buff, STATE_RUNNING, strlen(STATE_RUNNING)) == 0)
        {
            //print("%s %s", filepath, buff);

            fclose(fp);

            return true;
        }
    }

    fclose(fp);

    return false;
}

int parse(CStringList *list)
{
    const char *indir = "/proc/asound";

    CDirParserAuto *dir = cdirparser_new();
    if (!cdirparser_open(dir, indir, CDP_FILES | CDP_SUBDIRS))
        return 0;

    CStringAuto *filepath = cstr_new_size(32);
    char part[24];

    while (cdirparser_read(dir, filepath))
    {
        if (cstr_endswith(filepath, "/status", true))
        {
            if (cstr_size(filepath) < PART_POS)
                continue;

            const char *p = c_str(filepath) + PART_POS;
            const char *end = strchr(p, '/');

            if (!end)
                continue;

            strncpy(part, p, end - p);

            if (str_startswith(part, "pcm", true)
                && str_endswith(part, "p", true))
            {
                //print(c_str(filepath));

                cstrlist_append(list, c_str(filepath));
            }
        }
    }

    return cstrlist_size(list);
}

int main()
{
    CStringListAuto *list = cstrlist_new_size(12);

    int count = parse(list);

    for (int i = 0; i < count; ++i)
    {
        CString *str = cstrlist_at(list, i);

        print(c_str(str));
    }

    return EXIT_SUCCESS;
}


