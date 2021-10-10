#include "CDirParser.h"
#include "CFile.h"

#include "print.h"

int main()
{
    const char *indir = "D:\\Films\\Ep - Faites entrer l'accusé 1";
    const char *outpath = "D:\\Downloads\\fela_list.txt";

    CFile outfile;
    if (!outfile.open(outpath, "wb"))
        return false;

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


