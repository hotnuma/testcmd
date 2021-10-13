#include "libfile.h"

#include "print.h"

int main()
{
    const char *inpath = "D:\\Downloads\\test.html";
    const char *outpath = "D:\\Downloads\\test2.html";

    CString inbuff;

    if (!fileRead(inpath, inbuff))
        return false;

    char *ptr = inbuff.data();
    char *result;
    int length;

    CString outbuff;

    while (getLinePtr(&ptr, &result, &length))
    {
        outbuff.append(result, length);
        outbuff.append('\n');
    }

    if (!fileWrite(outpath, outbuff))
        return false;

    return 0;
}


