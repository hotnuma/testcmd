#include "cfileinfo.h"
#include "libapp.h"
#include "cfile.h"

#define _TESTFILE "/tmp/cfileinfo.txt"

int main()
{
    if (!file_exists(_TESTFILE))
    {
        CFileAuto *file = cfile_new();
        cfile_open(file, _TESTFILE, "wb");
        cfile_write(file, "bla");
        cfile_flush(file);
    }

    CFileInfoAuto *fi = cfileinfo_new();
    if (!cfileinfo_read(fi, _TESTFILE))
        return EXIT_FAILURE;

    //size_t size = cfileinfo_size(fi);
    uint64_t btime = cfileinfo_btime(fi);
    uint64_t mtime = cfileinfo_mtime(fi);
    uint64_t atime = cfileinfo_atime(fi);

    printf("btime = %lu\n", btime);
    printf("mtime = %lu\n", mtime);
    printf("atime = %lu\n", atime);

    return EXIT_SUCCESS;
}


