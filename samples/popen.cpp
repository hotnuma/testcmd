#include <libapp.h>
#include <libpath.h>
#include <print.h>
#include <stdio.h>

int main()
{
    setbuf(stdout, nullptr);

    CString path = getApplicationDir();
    CString testapp = pathJoin(path, "../samples/testout");

    FILE *fp = popen(testapp, "r");

    if (!fp)
    {
        print("can't find program %s", testapp.c_str());
        exit(1);
    }

    char readbuf[80];

    while (fgets(readbuf, 80, fp))
    {
        print("line = %s", readbuf);
    }

    pclose(fp);

    return 0;
}


