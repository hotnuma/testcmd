#include <libstr.h>
#include <ctype.h>

#include <print.h>

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


