#include <CDirParser.h>
#include <CFile.h>

#include <print.h>

int main()
{
    const char *indir = "/proc/asound";
    const char *outpath = "/tmp/proc_asound.txt";

    CFile outfile;
    if (!outfile.open(outpath, "wb"))
        return 1;

    CDirParser dir;
    if (!dir.open(indir, CDP_FILES | CDP_RELATIVE))
        return 1;

    CString filepath;

    while (dir.read(filepath))
    {
        outfile << indir;
        outfile << "\t";
        outfile << filepath;
        outfile << "\n";

        print(filepath);
    }

    return 0;
}


