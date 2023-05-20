#include <cdirparser.h>
#include <print.h>

// parse all subdirectories and get statistics

CString *_count_path = NULL;
int _count_result = 0;

void init()
{
    _count_path = cstr_new_size(256);
}

void release()
{
    cstr_free(_count_path);
}

void parse(const char *dirpath)
{
    CDirParserAuto *dir = cdirparser_new();
    if (!cdirparser_open(dir, dirpath, CDP_DIRS | CDP_FILES))
        return;

    CStringAuto *filepath = cstr_new_size(32);
    int count = 0;

    while (cdirparser_read(dir, filepath))
    {
        ++count;
    }

    if (count > _count_result)
    {
        //print("%s : %d", dirpath, count);
        cstr_copy(_count_path, dirpath);
        _count_result = count;
    }
}

int main()
{
    init();

    const char *indir = "/";

    CDirParserAuto *dir = cdirparser_new();
    if (!cdirparser_open(dir, indir, CDP_DIRS | CDP_SUBDIRS))
        return EXIT_FAILURE;

    CStringAuto *dirpath = cstr_new_size(32);

    while (cdirparser_read(dir, dirpath))
    {
        print(c_str(dirpath));

        parse(c_str(dirpath));
    }

    print("--------------------------------------------------");
    print("count_path : %s", c_str(_count_path));
    print("count_result : %d", _count_result);

    release();

    return EXIT_SUCCESS;
}


