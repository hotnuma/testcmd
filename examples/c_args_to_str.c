#include <clist.h>
#include <cstring.h>
#include <string.h>
#include <print.h>

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

void clist_split(CList *cslist, const char *str, const char *sep,
                 bool keepEmptyParts, bool sensitive)
{
    clist_clear(cslist);

    int slen = strlen(sep);

    const char *c = str;
    int len = 0;

    while (1)
    {
        if (*c == '\0')
        {
            len = c - str;

            if (len || keepEmptyParts)
                clist_append(cslist, strndup(str, len));

            break;
        }

        if (sensitive)
        {
            if (strncmp(c, sep, slen) == 0)
            {
                len = c - str;

                if (len > 0 || keepEmptyParts)
                    clist_append(cslist, strndup(str, len));

                c += slen;
                str = c;

                continue;
            }
        }
        else
        {
            if (strncasecmp(c, sep, slen) == 0)
            {
                len = c - str;

                if (len > 0 || keepEmptyParts)
                    clist_append(cslist, strndup(str, len));

                c += slen;
                str = c;

                continue;
            }
        }

        ++c;
    }
}

char* args_to_str(int argc, char **argv)
{
    if (argc < 1)
        return NULL;

    int len = 0;
    for (int i = 0; i < argc; ++i)
    {
        if (i > 0)
            ++len;

        len += strlen(argv[i]);
    }

    char *result = (char*) malloc((len + 1) * sizeof(char));
    char *p = result;

    for (int i = 0; i < argc; ++i)
    {
        if (i > 0)
        {
            *p = '|';
            ++p;
        }

        strcpy(p, argv[i]);
        p += strlen(argv[i]);
    }

    result[len] = '\0';

    return result;
}

CList* str_to_args(const char *str)
{
    if (!str || !*str)
        return NULL;

    CList *list = clist_new(10, (CDeleteFunc) free);
    clist_split(list, str, "|", true, true);

    return list;
}

int main(int argc, char **argv)
{
    char *str = args_to_str(argc, argv);

    print(str);

    CList *list = str_to_args(str);

    int argc_copy = clist_size(list);
    char **argv_copy = (char**) clist_data(list);

    for (int i = 0; i < argc_copy; ++i)
    {
        print("arg : %s", argv_copy[i]);
    }

    return EXIT_SUCCESS;
}


