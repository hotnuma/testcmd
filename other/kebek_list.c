#include <cfile.h>
#include <cstringlist.h>
#include <print.h>

bool parse(const char *inpath, const char *outpath)
{
    CFileAuto *file = cfile_new();
    if (!cfile_read(file, inpath))
        return false;

    //if (!cfile_open(file, outpath, "wb"))
    //    return EXIT_FAILURE;

    CStringAuto *line = cstr_new_size(32);
    CStringListAuto *parts = cstrlist_new_size(18);

    if (!cfile_getline(file, line))
        return false;

    while (cfile_getline(file, line))
    {
        cstrlist_split(parts, c_str(line), "\t", true, true);

        int count = cstrlist_size(parts);

        if (count != 18)
            return false;

        const char *country = c_str(cstrlist_at(parts, 8));
        if (strcmp(country, "France") != 0)
            continue;

        CString *year = cstrlist_at(parts, 11);
        int val = cstr_toint(year);
        print("val %d", val);

        break;

        //cfile_write(file, c_str(line));
        //cfile_write(file, "\n");
        //print(c_str(line));
    }

    return true;
}

int main()
{
    const char *inpath = "/home/hotnuma/Downloads/0Supprimer/20230217-upload-imdb.csv";
    const char *outpath = "/tmp/result.txt";

    parse(inpath, outpath);

    fflush(stdout);

    return EXIT_SUCCESS;
}


