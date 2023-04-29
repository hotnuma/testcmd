#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <print.h>

#if 0
CList* clist_new_args(int argc, char **argv)
{
    if (argc < 1)
        return NULL;

    CList *list = clist_new(argc, (CDeleteFunc) free);

    for (int i = 0; i < argc; ++i)
    {
        clist_append(list, strdup(argv[i]));
    }

    return list;
}
#endif


static int _app_exit(bool usage, int ret)
{
    if (usage)
    {
        print("*** usage");
        print("app -opt");
        print("app -arg value");
    }

    return ret;
}

int main(int argc, char **argv)
{
    if (argc < 2)
        return _app_exit(true, EXIT_FAILURE);

    int n = 1;

    while (n < argc)
    {
        const char *part = argv[n];

        if (strcmp(part, "-opt") == 0)
        {
            return EXIT_SUCCESS;
        }
        else if (strcmp(part, "-arg") == 0)
        {
            if (++n >= argc)
                return _app_exit(true, EXIT_FAILURE);

            return EXIT_SUCCESS;
        }
        else
        {
            return _app_exit(true, EXIT_FAILURE);
        }

        ++n;
    }

    return 0;
}


