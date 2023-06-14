#include <libstr.h>
#include <ctype.h>

#include <print.h>

bool str_getpart(char **start, char **result, int *length);
bool str_getpart(char **start, char **result, int *length)
{
    // usefull to browse columns, for example :
    //      col1    col2    col3    col4
    // won't work if there's empty colomns :-P

    // start of line.
    char *first = *start;

    while (isspace(*first)) ++first;

    // end of buffer ?
    if (*first == '\0')
        return false;

    // search end of line.
    char *p = first;

    while (1)
    {
        if (isspace(*p))
        {
            *result = first;
            *length = p - first;

            // move to the end.
            *start = ++p;

            return true;
        }
        else if (*p == '\0')
        {
            *result = first;
            *length = p - first;

            // move to the end.
            *start = p;

            return true;
        }

        ++p;
    }
}

int main()
{
    char buff[] = "   123   456   789    1 2 3 4 5 6    ";
    int nparts = 3;

    char *ptr = buff;
    char *result;
    int length;

    int count = 0;
    while (count < nparts && str_getpart(&ptr, &result, &length))
    {
        result[length] = '\0';

        print("part : %s\n", result);

        ++count;
    }

    while (isspace(*ptr)) ++ptr;

    // end of buffer ?
    if (*ptr == '\0')
        return EXIT_FAILURE;

    print("end : %s\n", ptr);

    return EXIT_SUCCESS;
}


