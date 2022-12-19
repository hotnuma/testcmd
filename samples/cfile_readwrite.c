#include <cfile.h>
#include <print.h>

int main()
{
    const char *inpath = "/tmp/infile.txt";
    const char *outpath = "/tmp/outfile.txt";

    CFileAuto *infile = cfile_new();
    if (!cfile_read(infile, inpath))
        return 1;

    CFileAuto *outfile = cfile_new();
    if (!cfile_open(outfile, outpath, "wb"))
        return 1;

    CStringAuto *line = cstr_new_size(32);
    while (cfile_getline(infile, line))
    {
        cfile_write(outfile, c_str(line));
        cfile_write(outfile, "\n");

        print(c_str(line));
    }

    return 0;
}



