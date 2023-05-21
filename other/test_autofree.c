#include <libmacros.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <print.h>

#define c_autotest GC_CLEANUP(_autofree)

GC_UNUSED static inline void _autofree(void *p)
{
    void **pp = (void**) p;

    if (*pp)
    {
        print("free : %p", *pp);
        free(*pp);
    }
}

int main(int argc, char **argv)
{
    c_autotest char *dirpath = NULL;

    print("dirpath : %p", dirpath);

    //return EXIT_SUCCESS;

    int n = 1;

    while (n < argc)
    {
        const char *part = argv[n];

        if (strcmp(part, "-d") == 0)
        {
            if (++n >= argc)
                return EXIT_FAILURE;

            dirpath = strdup(argv[n]);
            print("getcwd : %p", dirpath);
        }

        n++;
    }

    if (!dirpath)
    {
        dirpath = getcwd(NULL, 0);
        print("getcwd : %p", dirpath);

        if (!dirpath)
        {
            print("*** unable to read current directory, abort...");
            return EXIT_FAILURE;
        }
    }

    if (dirpath)
        print(dirpath);

    return EXIT_SUCCESS;
}


