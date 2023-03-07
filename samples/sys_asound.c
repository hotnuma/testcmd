#include <cdirparser.h>
#include <stdio.h>
#include <string.h>

#include <print.h>

#define STATE_RUNNING "state: RUNNING"

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
            print("%s %s", filepath, buff);

            fclose(fp);

            return true;
        }
    }

    fclose(fp);

    return false;
}

int main()
{
    const char *indir = "/proc/asound";

    CDirParserAuto *dir = cdirparser_new();
    if (!cdirparser_open(dir, indir, CDP_FILES | CDP_SUBDIRS))
        return 1;

    CStringAuto *filepath = cstr_new_size(32);

    while (cdirparser_read(dir, filepath))
    {
        if (cstr_endswith(filepath, "/status", true))
        {
            is_running(c_str(filepath));
        }

        //print(filepath);
    }

    return 0;
}


