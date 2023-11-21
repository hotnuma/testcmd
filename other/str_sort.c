#include <cstringlist.h>
#include <locale.h>

#include <print.h>

static int _compare(void *entry1, void *entry2)
{
    CString *e1 = *((CString**) entry1);
    CString *e2 = *((CString**) entry2);

    //return strcasecmp(c_str(e1), c_str(e2));
    return strcoll(c_str(e1), c_str(e2));
}

int main()
{
    setlocale(LC_ALL, "");

    CStringListAuto *list = cstrlist_new_size(16);

    cstrlist_append(list, "é");
    cstrlist_append(list, "E");
    cstrlist_append(list, "e");

    cstrlist_append(list, "à");
    cstrlist_append(list, "A");
    cstrlist_append(list, "a");

    cstrlist_sort_func(list, (CCompareFunc) _compare);

    int size = cstrlist_size(list);

    for (int i = 0; i < size; ++i)
    {
        print("%s", cstrlist_at_str(list, i));
    }

    return EXIT_SUCCESS;
}


