#include <CString.h>
#include <string.h>


CString argsToCString(int argc, char **argv)
{
    CString result(64);
    int size = 0;

    for (int i = 0; i < argc; ++i)
    {
        char *arg = argv[i];
        int len = strlen(arg);

        if (len < 1)
            continue;

        result.resize(size + len + 2);
        char *p = result.data() + size;
        strcpy(p, arg);
        size += len + 1;
    }

    if (size < 1)
    {
        result.clear();
        return result;
    }

    result.resize(size + 1);
    result.terminate(size);

    return result;
}

int main(int argc, char **argv)
{
    CString cmd = argsToCString(argc, argv);

    //int size = cmd.size();


//    const char *p = cmd.c_str();
//    const char *start = p;

//    while (1)
//    {
//        if (*p == '\0')
//        {

//        }

//        ++p;
//    }


}


