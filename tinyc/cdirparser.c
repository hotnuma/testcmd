#include <cdirparser.h>

#include <print.h>

int main()
{
    const char *indir = "/proc/asound";

    CDirParserAuto *dir = cdirparser_new();
    if (!cdirparser_open(dir, indir, CDP_FILES | CDP_SUBDIRS))
        return 1;

    CStringAuto *filepath = cstr_new_size(32);

    while (cdirparser_read(dir, filepath, NULL))
    {
        print(c_str(filepath));
    }

    return 0;
}


