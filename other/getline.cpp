#include "libfile.h"

#include "print.h"

int main()
{
    const char *inpath = "D:\\Downloads\\test.txt";
    const char *outpath = "D:\\Downloads\\test2.txt";

    CString inbuff;

    if (!fileRead(inpath, inbuff))
        return false;

    char *ptr = inbuff.data();
    CString line;

    CString outbuff;

    while (getLine(&ptr, line))
    {
        outbuff.append(line);
        outbuff.append('\n');
    }

    if (!fileWrite(outpath, outbuff))
        return false;

    return 0;
}


