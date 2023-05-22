#include <cdirparser.h>
#include <print.h>

// parse all subdirectories and get statistics

CString *_count_path = NULL;
int _count_result = 0;

CString *_long_path = NULL;
int _long_result = 0;

void init()
{
    _count_path = cstr_new_size(256);
    _long_path = cstr_new_size(256);
}

void release()
{
    cstr_free(_count_path);
    cstr_free(_long_path);
}

void parse(const char *dirpath)
{
    CDirParserAuto *dir = cdirparser_new();
    if (!cdirparser_open(dir, dirpath, CDP_DIRS | CDP_FILES))
        return;

    CStringAuto *filepath = cstr_new_size(128);
    int count = 0;

    while (cdirparser_read(dir, filepath))
    {
        ++count;

        int length = cstr_size(filepath);
        if (length > _long_result)
        {
            cstr_copy_len(_long_path, c_str(filepath), length);
            _long_result = length;
        }
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
    int numdirs = 0;

    CDirParserAuto *dir = cdirparser_new();
    if (!cdirparser_open(dir, indir, CDP_DIRS | CDP_SUBDIRS))
        return EXIT_FAILURE;

    CStringAuto *dirpath = cstr_new_size(32);

    while (cdirparser_read(dir, dirpath))
    {
        ++numdirs;

        print("%d : %s", numdirs, c_str(dirpath));

        parse(c_str(dirpath));
    }

    print("--------------------------------------------------");
    print("count_path : %s", c_str(_count_path));
    print("count_result : %d", _count_result);

    print("--------------------------------------------------");
    print("long_path : %s", c_str(_long_path));
    print("long_result : %d", _long_result);

    print("--------------------------------------------------");
    print("numdirs : %d", numdirs);

    release();

    return EXIT_SUCCESS;
}


