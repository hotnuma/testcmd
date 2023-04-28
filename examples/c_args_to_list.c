#include <clist.h>
#include <string.h>
#include <print.h>

int main(int argc, char **argv)
{
    CListAuto *list = clist_new_args(argc, argv);

    int argc_copy = clist_size(list);
    char **argv_copy = (char**) clist_data(list);

    for (int i = 0; i < argc_copy; ++i)
    {
        print("arg %d = %p : %s", i, argv_copy[i], argv_copy[i]);
    }

    return EXIT_SUCCESS;
}


